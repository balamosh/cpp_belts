#include "search_server.h"
#include "iterator_range.h"
#include "profile.h"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>
#include <future>
#include <thread>

vector<string> SplitIntoWords(const string& line) {
  istringstream words_input(line);
  return {istream_iterator<string>(words_input), istream_iterator<string>()};
}

SearchServer::SearchServer(istream& document_input) {
  //UpdateDocumentBase(document_input);
  auto  updater = [&document_input, this] {
    InvertedIndex new_index;
    for (string current_document; getline(document_input, current_document); ) {
      new_index.Add(move(current_document));
    }
    auto  index_access = index.GetAccess();
    swap(index_access.ref_to_value, new_index);
  };

  futures.push_back(async(updater));
  futures.back().get();
}

void SearchServer::UpdateDocumentBase(istream& document_input) {
  auto  updater = [&document_input, this] {
    InvertedIndex new_index;
    for (string current_document; getline(document_input, current_document); ) {
      new_index.Add(move(current_document));
    }
    auto  index_access = index.GetAccess();
    swap(index_access.ref_to_value, new_index);
  };

  futures.push_back(async(updater));
  //async(updater);
}

void SearchServer::AddQueriesStream(
  istream& query_input, ostream& search_results_output
) {

  auto  query = [&search_results_output, &query_input, this] {
    vector<size_t>  docid_count(50000);
    vector<size_t>  docid_index(50000);
    for (string current_query; getline(query_input, current_query); ) {
      
      auto  words = SplitIntoWords(current_query);

      size_t  id = 0;
      {
        auto  index_access = index.GetAccess();
        auto& current_index = index_access.ref_to_value;

        for (const auto& word : words) {
          for (const auto [docid, cnt] : current_index.Lookup(word)) {
            if (docid_count[docid] == 0) {
              docid_index[id++] = docid;
            }
            docid_count[docid] += cnt;
          }
        }
      }

      vector<pair<size_t, size_t>> search_results;
      for (size_t docid = 0; docid < id; ++docid)
      {
        size_t count = 0;
        size_t id = 0;
        swap(count, docid_count[docid_index[docid]]);
        swap(id, docid_index[docid]);
        search_results.emplace_back(id, count);
      }

      partial_sort(
        begin(search_results),
        begin(search_results) + min(size_t(5), search_results.size()),
        end(search_results),
        [](pair<size_t, size_t> lhs, pair<size_t, size_t> rhs) {
          int64_t lhs_docid = lhs.first;
          auto lhs_hit_count = lhs.second;
          int64_t rhs_docid = rhs.first;
          auto rhs_hit_count = rhs.second;
          return make_pair(lhs_hit_count, -lhs_docid) > make_pair(rhs_hit_count, -rhs_docid);
        }
      );

      search_results_output << current_query << ':';
      for (auto [docid, hitcount] : Head(search_results, 5)) {
        search_results_output << " {"
          << "docid: " << docid << ", "
          << "hitcount: " << hitcount << '}';
      }
      search_results_output << endl;
    }
  };
  
  futures.push_back(async(query));
  //async(query);
}

void InvertedIndex::Add(const string& document) {
  docs.push_back(document);

  const size_t docid = docs.size() - 1;
  
  for (const auto& word : SplitIntoWords(docs.back()))
  {
    auto& docid_cnt = index[word];
    if(!docid_cnt.empty() && docid_cnt.back().first == docid) {
      docid_cnt.back().second += 1;
    } else {
      docid_cnt.emplace_back(docid, 1);
    }
  }
}

const vector<pair<size_t, size_t>>& InvertedIndex::Lookup(const string& word) const {
  if (auto it = index.find(word); it != index.end()) {
    return it->second;
  } else {
    return empty_;
  }
}
