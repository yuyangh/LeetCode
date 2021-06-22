#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (46.18%)
 * Likes:    764
 * Dislikes: 79
 * Total Accepted:    266.1K
 * Total Submissions: 568.9K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 5
 * Output:
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 *
 *
 */
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;
		result.reserve(numRows);
		if (numRows == 0) {
			return result;
		}
		
		// base case, first row
		result.emplace_back(1,1);
		for (int level = 1; level < numRows; ++level) {
			// first element
			result.emplace_back(1,1);
			result.back().reserve(level + 1);
			// middle element
			for (int mid = 0; mid < level - 1; ++mid) {
				result.back().emplace_back(result[level - 1][mid] +
				                           result[level - 1][mid + 1]);
			}
			// last element
			result.back().emplace_back(1);
		}
		return result;
	}
};

int main() {
	int numRows = 5;
	Solution solution;
	auto result = solution.generate(numRows);
	PrintVectorVector(result);
	return 0;
}

