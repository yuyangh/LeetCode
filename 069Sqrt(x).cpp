#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (31.39%)
 * Likes:    768
 * Dislikes: 1371
 * Total Accepted:    372.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 *
 * Example 1:
 * Input: 4
 * Output: 2
 *
 *
 * Example 2:
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since
 * the decimal part is truncated, 2 is returned.
 */
class Solution {
public:
	int mySqrt(int x) {
		return calSqrt(0, x, x);
	}
	
	// since we target to return the lower bound of sqrt
	// so return high, because low will always be high+1
	int calSqrt(int low, int high, int target) {
		long long mid;
		long long square;
		while (low <= high) {
			mid = (low + high) / 2;
			square = mid * mid;
			if (square == target) {
				return mid;
			} else {
				if (square > target) {
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}
		}
		return high;
	}
};


int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int x = stringToInteger(line);
		
		int ret = Solution().mySqrt(x);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}