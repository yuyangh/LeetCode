//
// Created by Yuyang Huang on 5/27/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 *
 * https://leetcode.com/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (46.72%)
 * Likes:    1530
 * Dislikes: 81
 * Total Accepted:    205.1K
 * Total Submissions: 442.8K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * Given two strings S and T, return if they are equal when both are typed into
 * empty text editors. # means a backspace character.
 *
 * Note that after backspacing an empty text, the text will continue empty.
 *
 *
 * Example 1:
 *
 *
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 *
 *
 *
 * Example 2:
 *
 *
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 *
 *
 *
 * Example 3:
 *
 *
 * Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 *
 *
 *
 * Example 4:
 *
 *
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 *
 *
 * Note:
 *
 *
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S and T only contain lowercase letters and '#' characters.
 *
 *
 * Follow up:
 *
 *
 * Can you solve it in O(N) time and O(1) space?
 *
 *
 *
 *
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(n)
 */
class Solution {
public:
	bool backspaceCompare(string S, string T) {
		stack<char> ss, ts;
		for (const auto &c: S) {
			if (c != '#') {
				ss.push(c);
			}else{
				if(ss.empty()){
					continue;
				}
				ss.pop();
			}
		}
		
		for (const auto &c: T) {
			if (c != '#') {
				ts.push(c);
			}else{
				if(ts.empty()){
					continue;
				}
				ts.pop();
			}
		}
		
		if(ss.size()!=ts.size()){
			return false;
		}
		
		while(!ss.empty()){
			if(ss.top()!=ts.top()){
				return false;
			}
			ss.pop();
			ts.pop();
		}
		return true;
	}
};
// @lc code=end

int main() {
	Solution solution;
	assert(solution.backspaceCompare("ab#c", "ad#c"));
	assert(solution.backspaceCompare("ab##", "c#d#"));
	assert(solution.backspaceCompare("a#c", "b")==false);
	Complete();
}