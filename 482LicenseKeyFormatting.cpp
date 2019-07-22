#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 *
 * https://leetcode.com/problems/license-key-formatting/description/
 *
 * algorithms
 * Easy (41.16%)
 * Likes:    305
 * Dislikes: 517
 * Total Accepted:    85.8K
 * Total Submissions: 208.1K
 * Testcase Example:  '"5F3Z-2e-9-w"\n4'
 *
 * You are given a license key represented as a string S which consists only
 * alphanumeric character and dashes. The string is separated into N+1 groups
 * by N dashes.
 *
 * Given a number K, we would want to reformat the strings such that each group
 * contains exactly K characters, except for the first group which could be
 * shorter than K, but still must contain at least one character. Furthermore,
 * there must be a dash inserted between two groups and all lowercase letters
 * should be converted to uppercase.
 *
 * Given a non-empty string S and a number K, format the string according to
 * the rules described above.
 *
 * Example 1:
 * Input: S = "5F3Z-2e-9-w", K = 4
 * Output: "5F3Z-2E9W"
 *
 * Explanation: The string S has been split into two parts, each part has 4
 * characters.
 * Note that the two extra dashes are not needed and can be removed.
 *
 * Example 2:
 * Input: S = "2-5g-3-J", K = 2
 * Output: "2-5G-3J"
 *
 * Explanation: The string S has been split into three parts, each part has 2
 * characters except the first part as it could be shorter as mentioned
 * above.
 *
 * Note:
 * The length of string S will not exceed 12,000, and K is a positive integer.
 * String S consists only of alphanumerical characters (a-z and/or A-Z and/or
 * 0-9) and dashes(-).
 * String S is non-empty.
 */
class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		string result;
		
		// get the length of the string
		int length = 0;
		for (char i : S) {
			if (i != '-') {
				++length;
			}
		}
		// process each char
		for (char i : S) {
			if (i == '-') {
				continue;
			}
			result += toupper(i);
			// handle '-' append
			if (!result.empty() && length - result.size() != 0 &&
			    (length - result.size()) % K == 0) {
				result += '-';
				length += 1;
			}
		}
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

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		string S = stringToString(line);
		getline(cin, line);
		int K = stringToInteger(line);
		
		string ret = Solution().licenseKeyFormatting(S, K);
		
		string out = (ret);
		cout << out << endl;
	}
	return 0;
}