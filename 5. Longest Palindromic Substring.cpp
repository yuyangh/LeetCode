//
// Created by Yuyang Huang on 10/22/19.
//

#include "LeetCodeLib.h"

/*
 * 5. Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 *
 * Example 1:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 * Input: "cbbd"
 * Output: "bb"
 */

// @lc code=start

/*
 * time complexity O(n*n)
 * check palindrome expand from center with odd and even length
 */
class Solution {
public:
	string longestPalindrome(string s) {
		string result;
		int length;
		for (size_t i = 0; i < s.size(); i++) {
			// Expand Around Center with odd and even expansion
			auto evenResult = checkPalindrome(s, i, i + 1);
			auto oddResult = checkPalindrome(s, i, i);
			
			length = evenResult.second - evenResult.first + 1;
			if (evenResult.first != -1 && length > result.size()) {
				result = s.substr(evenResult.first, length);
			}
			
			length = oddResult.second - oddResult.first + 1;
			if (oddResult.first != -1 && length > result.size()) {
				result = s.substr(oddResult.first, length);
			}
		}
		return result;
	}
	
	/**
	 * check palindrome starts from left to left, from right to right
	 * @param s string
	 * @param left left starting index to check palindrome
	 * @param right right starting index
	 * @return the start position and end position of the palindrome
	 */
	pair<int, int> checkPalindrome(string &s, int left, int right) {
		// memorize previous left and right
		int prevLeft = -1, prevRight = -1;
		while (!(left < 0 || right >= s.size())
		       && s[left] == s[right]) {
			prevLeft = left;
			prevRight = right;
			left--;
			right++;
		}
		return {prevLeft, prevRight};
	}
};
// @lc code=end


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
	// Solution solution;
	// solution.longestPalindrome("ababd");
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);
		
		string ret = Solution().longestPalindrome(s);
		
		string out = (ret);
		cout << out << endl;
	}
	return 0;
}


