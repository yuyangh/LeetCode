#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.16%)
 * Likes:    690
 * Dislikes: 3237
 * Total Accepted:    198.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 *
 * Return the quotient after dividing dividend by divisor.
 *
 * The integer division should truncate toward zero.
 *
 * Example 1:
 * Input: dividend = 10, divisor = 3
 * Output: 3
 *
 * Example 2:
 * Input: dividend = 7, divisor = -3
 * Output: -2
 *
 * Note:
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 2^31 − 1 when the
 * division result overflows.
 */

class Solution {
public:
	// O(n) method, use bitwise operation to try divisor<<=1
	int divide(int dividend, int divisor) {
		return calculate(dividend, divisor);
	}
	
	// O(2^n) subtract divisor n times method
	int divideSlow(int dividend, int divisor){
		bool positive = true;
		int result = calculate(dividend, divisor, positive);
		if (result != 0 && !positive) {
			result = -result;
		}
		return result;
	}
	
	/**
	 * O(n) method, use bitwise operation to try divisor<<=1
	 */
	int calculate(int dividend, int divisor) {
		if (dividend == INT_MIN && divisor == -1) {
			return INT_MAX;
		}
		int sign = getResultSign(dividend, divisor),ans=0;
		int result = 0;
		// labs() is abs() for long
		long long dvd = labs(dividend), dvs = labs(divisor);
		
		// accumulate the divisor
		while (dvd >= dvs) {
			long temp = dvs;
			result = 1;
			// find largest multiples of divisor exponentially
			while ((temp << 1) <= dvd) {
				temp <<= 1;
				result <<= 1;
			}
			dvd -= temp;
			ans += result;
		}
		return sign * ans;
	}
	
	int getResultSign(int dividend, int divisor) {
		int sign = 1 << 31;
		if ((dividend & sign) ^ (divisor & sign)) {
			return -1;
		} else {
			return 1;
		}
	}
	
	int overflowProcess(int dividend, int divisor) {
		if (dividend == 0) {
			return 0;
		}
		if (dividend == INT_MIN) {
			if (divisor == -1) {
				return INT_MAX;
			}
		}
		if (divisor == 1) {
			return dividend;
		}
		if (divisor == -1) {
			return -dividend;
		}
		return 0;
	}
	
	/**
	 * dividend and divisor are both negative to avoid overflow
	 * use dividend -= divisor to calculate
	 * this is O(2^n), too slow
	 */
	int division(int dividend, int divisor) {
		int count = 0;
		while (dividend - divisor <= 0) {
			++count;
			dividend -= divisor;
		}
		return count;
	}
	
	int calculate(int dividend, int divisor, bool &positive) {
		int ans = overflowProcess(dividend, divisor);
		if (ans != 0) {
			return ans;
		} else {
			if (dividend == 0) {
				return dividend;
			}
		}
		int temp;
		
		if (dividend > 0) {
			if (divisor > 0) {
				// both positive, dividend < divisor
				return division(-dividend, -divisor);
			} else {
				// dividend >0, divisor <0
				positive = false;
				return division(-dividend, divisor);
			}
		} else {
			if (divisor < 0) {
				// both negative
				return division(dividend, divisor);
			} else {
				// dividend negative, divisor positive
				positive = false;
				return division(dividend, -divisor);
			}
		}
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int dividend = stringToInteger(line);
		getline(cin, line);
		int divisor = stringToInteger(line);
		
		int ret = Solution().divide(dividend, divisor);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}