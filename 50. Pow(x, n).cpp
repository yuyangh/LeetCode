#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (27.94%)
 * Likes:    849
 * Dislikes: 2080
 * Total Accepted:    322.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 *
 * Example 1:
 * Input: 2.00000, 10
 * Output: 1024.00000
 *
 *
 * Example 2:
 * Input: 2.10000, 3
 * Output: 9.26100
 *
 *
 * Example 3:
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 *
 *
 * Note:
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 */
class Solution {
public:
	/*
	 * Time complexity: O(n)
	 */
	double myPow(double x, int n) {
		return power(x, n);
	}
	
	// use recursion, and long long to handle overflow
	double power(double x, long long n) {
		if (x == 0) {
			return 0;
		}
		if (n == 0) {
			return 1;
		}
		if (n < 0) {
			x = 1 / x;
			n = -n;
		}
		if (n == 1) {
			return x;
		}
		if (n & 1) {
			return x * power(x * x, n / 2);
		} else {
			return power(x * x, n / 2);
		}
	}
};

