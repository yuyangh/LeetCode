#include "LeetCodeLib.h"

/*
 * 43. Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 *
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 *
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 *
 *
 * Note:
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 */

/*
 * Time complexity： O(n*n)
 */
class Solution {
public:
	string multiply(string num1, string num2) {
		// allocate the size
		string sum(num1.size() + num2.size(), '0');
		
		// do the multiplication from the end
		for (int i = num1.size() - 1; i >= 0; --i) {
			int carry = 0;
			for (int j = num2.size() - 1; j >= 0; --j) {
				int tmp = (sum[i + j + 1] - '0') +
				          (num1[i] - '0') * (num2[j] - '0') + carry;
				sum[i + j + 1] = tmp % 10 + '0';
				carry = tmp / 10;
			}
			
			// write leading carry after a loop
			sum[i] += carry;
		}
		
		// trim any leading zeros
		size_t startPos = sum.find_first_not_of('0');
		if (string::npos != startPos) {
			return sum.substr(startPos);
		}
		
		// return 0 if we computed nothing but zeros
		return "0";
	}
};