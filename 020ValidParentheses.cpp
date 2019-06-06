#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.47%)
 * Likes:    2924
 * Dislikes: 145
 * Total Accepted:    598.2K
 * Total Submissions: 1.6M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 * Input: "()"
 * Output: true
 *
 *
 * Example 2:
 * Input: "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 * Input: "(]"
 * Output: false
 *
 *
 * Example 4:
 * Input: "([)]"
 * Output: false
 *
 *
 * Example 5:
 * Input: "{[]}"
 * Output: true
 */
class Solution {
public:
	bool isValid(string s) {
		if (s.empty()) {
			return true;
		}
		unordered_map<char, char> mapping;
		mapping.emplace('(', ')');
		mapping.emplace('[', ']');
		mapping.emplace('{', '}');
		
		stack<char> para;
		// check each char if it match or not
		for (int i = 0; i < s.size(); i++) {
			auto it = mapping.find(s[i]);
			if (it != mapping.end()) {
				para.push(s[i]);
			} else {
				// handle extra right parentheses
				if (para.empty()) {
					return false;
				} else {
					// check match
					if (mapping.find(para.top())->second == s[i]) {
						para.pop();
					} else {
						return false;
					}
				}
			}
		}
		return para.empty();
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
		
		bool ret = Solution().isValid(s);
		
		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}