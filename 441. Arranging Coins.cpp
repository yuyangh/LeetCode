//
// Created by Yuyang Huang on 7/2/20.
//

#include "LeetCodeLib.h"

/*
 * 441. Arranging Coins
 *
 * https://leetcode.com/problems/arranging-coins/description/
 *
 * algorithms
 * Easy
 *
 * You have a total of n coins that you want to form in a staircase shape,
 * where every k-th row must have exactly k coins.
 * Given n, find the total number of full staircase rows that can be formed.
 * n is a non-negative integer and fits within the range of a 32-bit signed
 * integer.
 *
 * Example 1:
 *
 * n = 5
 *
 * The coins can form the following rows:
 * ¤
 * ¤ ¤
 * ¤ ¤
 *
 * Because the 3rd row is incomplete, we return 2.
 *
 *
 *
 * Example 2:
 *
 * n = 8
 *
 * The coins can form the following rows:
 * ¤
 * ¤ ¤
 * ¤ ¤ ¤
 * ¤ ¤
 *
 * Because the 4th row is incomplete, we return 3.
 *
 *
 */

// @lc code=start
class Solution {
public:
	/*
	 * Time complexity: O(1)
	 * Since (1 + row) * row / 2 <= n
	 * So, (r + 0.5) ^ 2 <= 2n + 0.25
	 */
	int arrangeCoins(int n) {
		return floor(sqrt(2 * static_cast<double>(n) + 0.25) - 0.5);
	}
};
// @lc code=end

