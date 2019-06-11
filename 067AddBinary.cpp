#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (39.27%)
 * Likes:    976
 * Dislikes: 191
 * Total Accepted:    306.7K
 * Total Submissions: 780.7K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * The input strings are both non-empty and contains only characters 1 or 0.
 *
 * Example 1:
 *
 *
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Example 2:
 *
 *
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 */
class Solution {
public:
	string addBinary(string a, string b) {
		string result = "";
		int carry = 0;
		// reverse the order to calculate
		std::reverse(a.begin(), a.end());
		std::reverse(b.begin(), b.end());
		
		unsigned int length = max(a.size(), b.size());
		for (int i = 0; i < length; i++) {
			int numA = 0, numB = 0;
			if (i < a.size()) {
				numA = a[i] - '0';
			} else {
				numA = 0;
			}
			if (i < b.size()) {
				numB = b[i] - '0';
			} else {
				numB = 0;
			}
			int sum = (numA + numB + carry) % 2;
			carry = (numA + numB + carry) / 2;
			result += '0' + sum;
		}
		// append last carry
		if (carry) {
			result += '1';
		}
		// string supports pop_back()
		for (int i = result.size() - 1; i > 0; i--) {
			if (result[i] == '0') {
				result.pop_back();
			} else {
				break;
			}
		}
		std::reverse(result.begin(), result.end());
		return result;
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
		string a = stringToString(line);
		getline(cin, line);
		string b = stringToString(line);
		
		string ret = Solution().addBinary(a, b);
		
		string out = (ret);
		cout << out << endl;
	}
	return 0;
}