#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (31.06%)
 * Likes:    589
 * Dislikes: 1726
 * Total Accepted:    358.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 *
 * Example 1:
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 *
 *
 * Example 2:
 * Input: "race a car"
 * Output: false
 */
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty()) {
			return true;
		}
		int begin = 0, end = s.size() - 1;
		while (begin <= end) {
			// if not alpha numeric, ignore
			while (!isalnum(s[begin])) {
				begin++;
				// avoid over bounds
				if (begin >= s.size()) {
					return true;
				}
			}
			while (!isalnum(s[end])) {
				end--;
				if (end < 0) {
					return true;
				}
			}
			if (tolower(s[begin]) == tolower(s[end])) {
				begin++;
				end--;
			} else {
				return false;
			}
		}
		return true;
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

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);
		
		bool ret = Solution().isPalindrome(s);
		
		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}
