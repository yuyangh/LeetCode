#include "LeetCodeLib.h"

int CutBricks(const vector<vector<int>> &arr) {
	// are wall width all the same?
	
	unordered_map<int, int> intersections;
	for (const auto &row : arr) {
		int width = 0;
		for (int col = 0; col + 1 < row.size(); ++col) {
			width += row[col];
			
			auto it = intersections.find(width);
			// first intersections
			if (it == intersections.end()) {
				intersections.emplace(width, 1);
			} else {
				it->second += 1;
			}
		}
	}
	
	int maxIntersections = 0;
	int pos = -1;
	for (const auto &intersection : intersections) {
		if (intersection.second > maxIntersections) {
			maxIntersections = intersection.second;
			pos = intersection.first;
		}
	}
	return maxIntersections;
}

int main() {
	vector<vector<int>> arr = {{1, 2, 1},
	                           {2, 1, 1},
	                           {4},
	                           {1, 1, 1, 1}};
	/*
	 * | |  |  |
	 * |  | |  |
	 * |       |
	 * | | | | |
	 * */
	auto result = CutBricks(arr);
	PrintSingleResult(result);
	return 0;
}