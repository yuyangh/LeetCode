#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (31.95%)
 * Likes:    882
 * Dislikes: 1307
 * Total Accepted:    431.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 * Example 1:
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 *
 *
 * Example 2:
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 *
 *
 * Clarification:
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 */
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) {
			return 0;
		}
		int pos = 0;
		// check match of each char
		for (int i = 0; i < haystack.size(); i++) {
			for (int j = 0; j < needle.size(); j++) {
				if (haystack[i] == needle[j]) {
					pos = i;
					do {
						i++;
						j++;
						if (j == needle.size()) {
							return pos;
						}
						if (i >= haystack.size() || j > needle.size()) {
							break;
						}
					} while (haystack[i] == needle[j]);
					i = pos;
				}
				// if any char diff, stop checking
				break;
			}
		}
		return -1;
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
		string haystack = stringToString(line);
		getline(cin, line);
		string needle = stringToString(line);
		
		int ret = Solution().strStr(haystack, needle);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}