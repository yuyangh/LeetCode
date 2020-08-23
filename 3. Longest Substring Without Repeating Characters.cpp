#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.35%)
 * Likes:    5550
 * Dislikes: 309
 * Total Accepted:    931.8K
 * Total Submissions: 3.3M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 * Example 1:
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 * Example 2:
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 * Example 3:
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 */


/*
 * Time complexity: O(n)
 * update the location of each char and the max length
 */
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unsigned int maxLength = 0;
		unordered_map<char, unsigned int> charPosMap;
		for (unsigned int start = 0, cur = 0; cur < s.size(); cur++) {
			char currChar = s[cur];
			if (charPosMap.find(currChar) != charPosMap.end()) {
				// update the start as an increasing variable
				start = max(start, charPosMap[currChar] + 1);
			}
			
			charPosMap[currChar] = cur;
			maxLength = max(cur - start + 1, maxLength);
		}
		return maxLength;
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
		
		int ret = Solution().lengthOfLongestSubstring(s);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}