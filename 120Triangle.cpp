#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (39.27%)
 * Likes:    1107
 * Dislikes: 120
 * Total Accepted:    182.2K
 * Total Submissions: 462.6K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 *
 *
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 *
 */
class Solution {
public:
	int minimumTotal(vector<vector<int>> &triangle) {
		if (triangle.empty()) {
			return 0;
		}
		vector<int> ans(triangle.size(), INT_MAX);
		
		vector<vector<int>> cost;
		cost.reserve(triangle.size());
		for (int i = 0; i < triangle.size(); i++) {
			cost.emplace_back(triangle[i].size(), INT_MAX);
		}
		
		// accumulate the cost along the path
		cost[0][0] = triangle[0][0];
		for (int row = 0; row < (int) (triangle.size()) - 1; row++) {
			for (int col = 0; col < triangle[row].size(); ++col) {
				cost[row + 1][col] = min(cost[row + 1][col],
				                         cost[row][col] + triangle[row + 1][col]);
				cost[row + 1][col + 1] = min(cost[row + 1][col + 1],
				                             cost[row][col] + triangle[row + 1][col + 1]);
			}
		}
		
		// the minimum path cost is stored on the last row
		int sum = INT_MAX;
		int row = static_cast<int>(cost.size()) - 1;
		for (int col : cost[row]) {
			if (sum > col) {
				sum = col;
			}
		}
		return sum;
		
	}
};

int main() {
	vector<vector<int>> vec = {{2},
	                           {3, 4},
	                           {6, 5, 7},
	                           {4, 1, 8, 3}};
	Solution solution;
	cout << solution.minimumTotal(vec) << endl;
}