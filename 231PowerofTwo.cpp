//
// Created by Yuyang Huang on 6/8/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (42.46%)
 * Likes:    784
 * Dislikes: 184
 * Total Accepted:    319.5K
 * Total Submissions: 735.2K
 * Testcase Example:  '1'
 *
 * Given an integer, write a function to determine if it is a power of two.
 *
 * Example 1:
 *
 *
 * Input: 1
 * Output: true
 * Explanation: 2^0Â = 1
 *
 *
 * Example 2:
 *
 *
 * Input: 16
 * Output: true
 * Explanation: 2^4Â = 16
 *
 * Example 3:
 *
 *
 * Input: 218
 * Output: false
 *
 */

// @lc code=start

/*
 * Time compexity: O(1)
 */
class Solution {
public:
	/*
	 * if number x is a power of 2, then x-1 will have all 1s
	 * so x & (x-1) must be 0
	 */
	bool isPowerOfTwo(int n) {
		if (n == 0) {
			return false;
		}
		long x = n;
		return !(x & (x - 1));
	}
	
	/*
	 * because -x = ~x +1, so x & -x will get a number that has previous last 1 bit
	 * since a power of 2 only has 1 1bit, so x & (-x) == x can check
	 */
	bool isPowerOfTwo2(int n) {
		if (n == 0) {
			return false;
		}
		long x = n;
		return (x & -x) == x;
	}
};
// @lc code=end

int main() {
	Solution solution;
	assert(solution.isPowerOfTwo(1));
	assert(solution.isPowerOfTwo(2));
	assert(solution.isPowerOfTwo(4));
	assert(solution.isPowerOfTwo(2048));
	assert(!solution.isPowerOfTwo(3));
	Complete();
}

