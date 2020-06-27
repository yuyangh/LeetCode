//
// Created by Yuyang Huang on 6/27/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (43.33%)
 * Likes:    2806
 * Dislikes: 181
 * Total Accepted:    294.4K
 * Total Submissions: 632.9K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * Example 1:
 *
 *
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 *
 * Example 2:
 *
 *
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */

// @lc code=start
class Solution {
public:
	/*
	 * Time complexity: O(n*sqrt(n))
	 * Space complexity: O(n)
	 * dynamic programming
	 */
	int numSquares(int n) {
		if (n == 0) {
			return 0;
		}
		
		int numSquareSize = static_cast<int >(sqrt(n));
		
		// calculate possible square size
		vector<int> squareSizes;
		squareSizes.reserve(numSquareSize);
		for (int i = 1; i <= numSquareSize; ++i) {
			squareSizes.emplace_back(i * i);
		}
		
		vector<int> squareCount(n + 1, INT_MAX);
		squareCount[0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int squareSizeIdx = 0; squareSizeIdx < squareSizes.size(); ++squareSizeIdx) {
				int prevSquareCount = i - squareSizes[squareSizeIdx];
				if (prevSquareCount >= 0) {
					squareCount[i] = min(squareCount[i], 1 + squareCount[prevSquareCount]);
				}
			}
		}
		
		return squareCount.back();
	}
};
// @lc code=end

int main() {
	Solution solution;
	
	PrintSingleResult(solution.numSquares(0));
	PrintSingleResult(solution.numSquares(1));
	PrintSingleResult(solution.numSquares(12));
	PrintSingleResult(solution.numSquares(13));
	PrintSingleResult(solution.numSquares(15));
	PrintSingleResult(solution.numSquares(16));
	
	Complete();
}