//
// Created by Yuyang Huang on 10/23/19.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (41.70%)
 * Likes:    1955
 * Dislikes: 59
 * Total Accepted:    220.5K
 * Total Submissions: 528.8K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n' +
  '5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 *
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 *
 *
 * Example:
 *
 * Consider the following matrix:
 *
 *
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 *
 *
 * Given target = 5, return true.
 *
 * Given target = 20, return false.
 *
 */

// @lc code=start
class Solution {
public:
	/*
	 * time complexity: O(n), space complexity:O(1)
	 *
	 * if the currently-pointed-to value is larger than target we can move one row "up".
	 * Otherwise, if the currently-pointed-to value is smaller than target, we can move one column "right".
	 */
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		// base case for detecting empty
		if (matrix.empty() || matrix[0].empty()) {
			return false;
		}
		
		// start with bottom left corner
		int row = matrix.size() - 1, col = 0;
		while (row >= 0 && col < matrix[0].size()) {
			if (matrix[row][col] > target) {
				row--;
			} else if (matrix[row][col] < target) {
				col++;
			} else {
				return true;
			}
		}
		return false;
	}
};

// @lc code=end
int main() {
	Solution solution;
	vector<vector<int>> matrix = {
			{1,  4,  7,  11, 15},
			{2,  5,  8,  12, 19},
			{3,  6,  9,  16, 22},
			{10, 13, 14, 17, 24},
			{18, 21, 23, 26, 30}
	};
	bool result;
	
	result = solution.searchMatrix(matrix, 5);
	PrintSingleResult(result);
}

