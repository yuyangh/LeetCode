#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (14.64%)
 * Likes:    941
 * Dislikes: 5963
 * Total Accepted:    366.9K
 * Total Submissions: 2.5M
 * Testcase Example:  '"42"'
 *
 * Implement atoi which converts a string to an integer.
 *
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 *
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned.
 *
 * Note:
 *
 *
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical
 * value is out of the range of representable values, INT_MAX (2^31 − 1) or
 * INT_MIN (−2^31) is returned.
 *
 *
 * Example 1:
 * Input: "42"
 * Output: 42
 *
 * Example 2:
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus
 * sign.
 * Then take as many numerical digits as possible, which gets 42.
 *
 * Example 3:
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a
 * numerical digit.
 *
 * Example 4:
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a
 * numerical
 * digit or a +/- sign. Therefore no valid conversion could be performed.
 *
 * Example 5:
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit
 * signed integer.
 * Thefore INT_MIN (−2^31) is returned.
 *
 */
class Solution {
public:
	int myAtoi(string str) {
		bool negative = false, numExist = false;
		long long num = 0;
		int signCount = 0;
		
		// go through each char
		for (int i = 0; i < str.size(); i++) {
			// if space exist after num or sign, stop
			if (str[i] == ' ') {
				if (numExist || signCount) {
					break;
				}
				continue;
			}
			// if num exist after sign, break
			// if multiple sign before num, return 0
			if (str[i] == '+' || str[i] == '-') {
				if (numExist) {
					break;
				}
				if (str[i] == '-') {
					negative = true;
				}
				signCount++;
				if (signCount > 1) {
					return 0;
				}
				continue;
			}
			if (!isdigit(str[i])) {
				break;
			} else {
				numExist = true;
				num *= 10;
				num += str[i] - '0';
				if (!negative && num > INT_MAX) {
					return INT_MAX;
				}
				if (negative && -num < INT_MIN) {
					return INT_MIN;
				}
			}
		}
		if (negative) {
			num = -num;
		}
		return (int) (num);
	}
	
	// more succint version
	int myAtoiRef(string str) {
		long result = 0;
		int indicator = 1;// indicate the sign
		int i = str.find_first_not_of(' ');
		if (str[i] == '-' || str[i] == '+')
			indicator = (str[i++] == '-') ? -1 : 1;
		while ('0' <= str[i] && str[i] <= '9') {
			result = result * 10 + (str[i++] - '0');
			if (result * indicator >= INT_MAX) return INT_MAX;
			if (result * indicator <= INT_MIN) return INT_MIN;
		}
		
		return result * indicator;
	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
				case '\"':
					result.push_back('\"');
					break;
				case '/' :
					result.push_back('/');
					break;
				case '\\':
					result.push_back('\\');
					break;
				case 'b' :
					result.push_back('\b');
					break;
				case 'f' :
					result.push_back('\f');
					break;
				case 'r' :
					result.push_back('\r');
					break;
				case 'n' :
					result.push_back('\n');
					break;
				case 't' :
					result.push_back('\t');
					break;
				default:
					break;
			}
			i++;
		} else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main() {
	string line;
	while (getline(cin, line)) {
		string str = stringToString(line);
		
		int ret = Solution().myAtoi(str);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}