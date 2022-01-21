#include "search_server.h"
#include "iterator_range.h"
#include "profile.h"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>

vector<string> SplitIntoWords(const string& line) {
  istringstream words_input(line);
  return {istream_iterator<string>(words_input), istream_iterator<string>()};
}

SearchServer::SearchServer(istream& document_input) {
  UpdateDocumentBase(document_input);
}

void SearchServer::UpdateDocumentBase(istream& document_input) {
	LOG_DURATION("document base");
  InvertedIndex new_index;

  for (string current_document; getline(document_input, current_document); ) {
    new_index.Add(move(current_document));
  }

  index = move(new_index);
}

void SearchServer::AddQueriesStream(
  istream& query_input, ostream& search_results_output
) {
	TotalDuration split("split");
  TotalDuration count("count");
  TotalDuration sort_t("sort");
  TotalDuration result("result");

  vector<size_t> docid_count(index.Size());
  for (string current_query; getline(query_input, current_query); ) {
    vector<string>  words;
    { ADD_DURATION(split);
    words = SplitIntoWords(current_query);
    }

    { ADD_DURATION(count);
    for (const auto& word : words) {
      for (const size_t docid : index.Lookup(word)) {
        docid_count[docid]++;
      }
    }
    }

    /*
    vector<pair<size_t, size_t>> search_results(
      docid_count.begin(), docid_count.end()
    );
    */
    vector<pair<size_t, size_t>> search_results;
    { ADD_DURATION(sort_t);
    for (size_t k = 0; k < 5; ++k) {
      size_t  max_cnt = docid_count[0];
      size_t  max_i = 0;
      for (size_t i = 1; i < docid_count.size(); ++i) {
        if (docid_count[i] > max_cnt) {
          max_cnt = docid_count[i];
          max_i = i;
        }
      }
      if (max_cnt > 0) {
        search_results.push_back({max_i, max_cnt});
        docid_count[max_i] = 0;
      } else {
        break;
      }
    }
    }
    /*
    { ADD_DURATION(sort_t);
    sort(
      begin(search_results),
      end(search_results),
      [](pair<size_t, size_t> lhs, pair<size_t, size_t> rhs) {
        int64_t lhs_docid = lhs.first;
        auto lhs_hit_count = lhs.second;
        int64_t rhs_docid = rhs.first;
        auto rhs_hit_count = rhs.second;
        return make_pair(lhs_hit_count, -lhs_docid) > make_pair(rhs_hit_count, -rhs_docid);
      }
    );
    }
    */

    { ADD_DURATION(result);
    search_results_output << current_query << ':';
    for (auto [docid, hitcount] : Head(search_results, 5)) {
      search_results_output << " {"
        << "docid: " << docid << ", "
        << "hitcount: " << hitcount << '}';
    }
    search_results_output << endl;
    }
    fill(docid_count.begin(), docid_count.end(), 0);
  }
}

void InvertedIndex::Add(const string& document) {
  docs.push_back(document);

  const size_t docid = docs.size() - 1;
  for (const auto& word : SplitIntoWords(document)) {
    index[word].push_back(docid);
  }
}

list<size_t> InvertedIndex::Lookup(const string& word) const {
  if (auto it = index.find(word); it != index.end()) {
    return it->second;
  } else {
    return {};
  }
}
