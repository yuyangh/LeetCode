//
// Created by Yuyang Huang on 6/15/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.52%)
 * Likes:    3302
 * Dislikes: 5222
 * Total Accepted:    1.1M
 * Total Submissions: 4.2M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 *
 * Input: 123
 * Output: 321
 *
 *
 * Example 2:
 *
 *
 * Input: -123
 * Output: -321
 *
 *
 * Example 3:
 *
 *
 * Input: 120
 * Output: 21
 *
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [âˆ’2^31,Â  2^31Â âˆ’ 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 *
 */

// @lc code=start

/*
 * Time complexity: O(n)
 * handle out of bound case by + and -
 */
class Solution {
public:
	int reverse(int x) {
		unsigned int sign = x & (1 << 31);
		int num = x;
		int reversedNum = 0;
		while (num != 0) {
			int digit = num % 10;
			// check out of bound
			if (reversedNum > INT_MAX / 10 || (reversedNum == INT_MAX / 10 && digit > 7)) {
				return 0;
			}
			if (reversedNum < INT_MIN / 10 || (reversedNum == INT_MIN / 10 && digit < -8)) {
				return 0;
			}
			reversedNum = reversedNum * 10 + digit;
			num /= 10;
		}
		return sign | reversedNum;
	}
};
// @lc code=end

int main() {
	Solution solution;
	PrintSingleResult(solution.reverse(123));
	PrintSingleResult(solution.reverse(-123));
	PrintSingleResult(solution.reverse(120));
	PrintSingleResult(solution.reverse(0));
	PrintSingleResult(solution.reverse(INT_MAX));
	PrintSingleResult(solution.reverse(INT_MIN));
	
	Complete();
}
