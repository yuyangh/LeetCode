#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (34.96%)
 * Likes:    621
 * Dislikes: 76
 * Total Accepted:    140.6K
 * Total Submissions: 401.8K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 *
 * Example 1:
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 *
 * Example 2:
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 *
 * Example 3:
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 *
 * Example 4:
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 *
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters that may be separated by a single space.
 */
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		if (pattern.empty() || str.empty()) {
			return false;
		}
		
		// convert str into an ordered uppercase pattern
		stringstream ss(str);
		unordered_map<string, char> mapping;
		string temp, result;
		int count = 0;
		while (ss >> temp) {
			auto find = mapping.find(temp);
			if (find == mapping.end()) {
				char ch = 'A' + count;
				mapping.emplace(temp, ch);
				count++;
				result += ch;
			} else {
				result += find->second;
			}
		}
		
		// convert pattern into ordered uppercase pattern
		int cnt = 0;
		string converted;
		unordered_map<char, char> convert;
		for (const auto &item : pattern) {
			auto find = convert.find(item);
			if (find == convert.end()) {
				char ch = (char) ('A' + cnt);
				convert.emplace(item, ch);
				converted += ch;
				cnt++;
			} else {
				converted += find->second;
			}
		}
		
		return converted == result;
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
		string pattern = stringToString(line);
		getline(cin, line);
		string str = stringToString(line);
		
		bool ret = Solution().wordPattern(pattern, str);
		
		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}