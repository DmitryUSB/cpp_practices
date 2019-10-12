#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using Segment = std::pair<int, int>;

struct sort_pairs_second
{
	bool operator() (Segment i, Segment j) {
		if (i.second == j.second) return (i.first > j.first); 
		else { return (i.second < j.second); }
	}
} sort_pairs_by_second;

std::vector <int> get_covering_set(std::vector <Segment> segments) {
	std::vector <int> result;	
	std::sort(segments.begin(), segments.end(), sort_pairs_by_second);
	result.push_back(segments[0].second);
			for (auto s : segments) {
				if (result.back() < s.first || result.back() > s.second) {
					result.push_back(s.second);
				}
			}
	return result;
}

int main(void) {
	int segments_count;
	std::cin >> segments_count;
	std::vector <Segment> segments(segments_count);
	for (auto& s : segments) {
		std::cin >> s.first >> s.second;
	}

	auto points = get_covering_set(std::move(segments));
	std::cout << points.size() << std::endl;
	for (auto point : points) {
		std::cout << point << " ";
	}
	std::cout << std::endl;
}