//
// Created by Yuyang Huang on 7/15/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (18.25%)
 * Likes:    1096
 * Dislikes: 2913
 * Total Accepted:    421.5K
 * Total Submissions: 2M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string, reverse the string word by word.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "the sky is blue"
 * Output: "blue is sky the"
 *
 *
 * Example 2:
 *
 *
 * Input: "  hello world!  "
 * Output: "world! hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 *
 *
 * Example 3:
 *
 *
 * Input: "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 *
 *
 *
 *
 * Note:
 *
 *
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. However, your reversed
 * string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in
 * the reversed string.
 *
 *
 *
 *
 * Follow up:
 *
 * For C programmers, try to solve it in-place in O(1) extra space.
 */

// @lc code=start
class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * Reverse word in place, then reverse entire string
	 */
	string reverseWords(string s) {
		if (s.empty()) {
			return "";
		}
		
		// reverse word in place
		size_t nonEmptyIdx = s.find_first_not_of(' ');
		while (nonEmptyIdx != string::npos) {
			size_t emptyIdx = s.find_first_of(' ', nonEmptyIdx);
			if (emptyIdx == string::npos) {
				emptyIdx = s.size();
			}
			reverseWord(nonEmptyIdx, emptyIdx, s);
			nonEmptyIdx = s.find_first_not_of(' ', emptyIdx);
		}
		
		// reverse entire string
		string result;
		int firstNonBlankIdx = s.find_first_not_of(' ');
		if (firstNonBlankIdx == string::npos) { firstNonBlankIdx = 0; }
		for (int i = s.find_last_not_of(' '); i >= firstNonBlankIdx; --i) {
			if (s[i] != ' ') {
				result += s[i];
			} else if (s[i + 1] != ' ') {
				result += ' ';
			}
		}
		
		return result;
	}

private:
	void reverseWord(int start, int end, string &str) {
		for (int idx = 0; idx < (end - start) / 2; ++idx) {
			swap(str[start + idx], str[end - 1 - idx]);
		}
	}
};
// @lc code=end

