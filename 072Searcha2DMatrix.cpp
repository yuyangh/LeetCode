#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (34.91%)
 * Likes:    856
 * Dislikes: 99
 * Total Accepted:    228.1K
 * Total Submissions: 652.6K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 *
 *
 * Example 1:
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 *
 *
 * Example 2:
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 *
 */
class Solution {
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		// handle empty case
		if (matrix.empty() || matrix[0].empty()) {
			return false;
		}
		int rowIndex = binaryRowSearch(matrix, target);
		// handle before 1st row case
		if (rowIndex < 0) {
			return false;
		}
		return binary_search(matrix[rowIndex].begin(), matrix[rowIndex].end(), target);
	}
	
	// search for row
	int binaryRowSearch(vector<vector<int>> &matrix, int target) {
		int low = 0, high = matrix.size() - 1, mid;
		while (low <= high) {
			mid = (low + high) / 2;
			if (matrix[mid][0] < target) {
				low = mid + 1;
			} else {
				if (matrix[mid][0] > target) {
					high = mid - 1;
				} else {
					return mid;
				}
			}
		}
		return high;
	}
};

int main() {
	vector<vector<int>> arr = {{1,  2,  3},
	                           {4,  7,  9},
	                           {10, 20, 30}};
	int target = 11;
	Solution solution;
	auto ans = solution.searchMatrix(arr, target);
	cout << "ans is: " << ans << "\n";
	return 0;
}