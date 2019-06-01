#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (48.00%)
 * Likes:    518
 * Dislikes: 55
 * Total Accepted:    97.1K
 * Total Submissions: 202.2K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 *
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 *
 * Note:
 * Assume the length of given string will not exceed 1,010.
 *
 * Example:
 * Input:
 * "abccccdd"
 *
 * Output:
 * 7
 *
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 */
class Solution {
public:
	int longestPalindrome(string s) {
		if (s.empty()) {
			return 0;
		}
		
		// memorize the number of existence for each char
		unordered_map<char, int> charMap;
		for (size_t i = 0; i < s.size(); i++) {
			auto find = charMap.find(s[i]);
			if (find == charMap.end()) {
				charMap.emplace(s[i], 1);
			} else {
				find->second++;
			}
		}
		
		int evenLength = 0;
		int partialOddLength = 0;
		bool hasOdd = false;
		
		// accumulate even existence
		for (auto it = charMap.begin(); it != charMap.end(); ++it) {
			if (it->second % 2 == 0) {
				evenLength += it->second;
			} else {
				hasOdd = true;
				partialOddLength += it->second - 1;
			}
		}
		// add single char at middle
		if (hasOdd) {
			partialOddLength++;
		}
		return evenLength + partialOddLength;
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
		string s = stringToString(line);
		
		int ret = Solution().longestPalindrome(s);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}
