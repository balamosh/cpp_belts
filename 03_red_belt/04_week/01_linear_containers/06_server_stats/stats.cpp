#include "stats.h"
#include <vector>

vector<string_view>	Split(string_view str) {
	vector<string_view>	result;
	size_t				pos = str.find_first_not_of(' ', 0);
	const size_t		pos_end = str.npos;

	while (true) {
		size_t	space = str.find(' ', pos);
		result.push_back(
			space == pos_end
			? str.substr(pos)
			: str.substr(pos, space - pos));
		if (space == pos_end) {
			break ;
		} else {
			pos = str.find_first_not_of(' ', space);
		}
	}
	return (result);
}

HttpRequest ParseRequest(string_view line) {
	HttpRequest			result;
	vector<string_view>	words;

	words = Split(line);
	result.method = words[0];
	result.uri = words[1];
	result.protocol = words[2];
	return (result);
}

Stats::Stats() {
	method_stats = {
		{"GET", 0},
		{"PUT", 0},
		{"POST", 0},
		{"DELETE", 0},
		{"UNKNOWN", 0},
	};
	uri_stats = {
		{"/", 0},
		{"/order", 0},
		{"/product", 0},
		{"/basket", 0},
		{"/help", 0},
		{"unknown", 0},
	};
}

#include <iostream>

void
Stats::AddMethod(string_view method) {
	if (method_stats.count(method))
		++method_stats[method];
	else
		++method_stats["UNKNOWN"];
}

void
Stats::AddUri(string_view method) {
	if (uri_stats.count(method))
		++uri_stats[method];
	else
		++uri_stats["unknown"];
}

const map<string_view, int>&
Stats::GetMethodStats() const {
	return (method_stats);
}

const map<string_view, int>&
Stats::GetUriStats() const {
	return (uri_stats);
}
