#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (54.80%)
 * Likes:    2788
 * Dislikes: 172
 * Total Accepted:    343.4K
 * Total Submissions: 623.2K
 * Testcase Example:  '3'
 *
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 *
 */
class Solution {
public:
	vector<string> result;
	
	vector<string> generateParenthesis(int n) {
		result.reserve(n * n);
		generate("", n, n);
		return result;
	}
	
	// base on the left and right remaining,
	// add "(" or ")" accordingly
	void generate(string str, int left, int right) {
		if (left == 0) {
			while (right > 0) {
				str += ')';
				right--;
			}
			result.emplace_back(str);
			return;
		}
		if (left < right) {
			generate(str + '(', left - 1, right);
			generate(str + ')', left, right - 1);
		} else {
			if (left == right) {
				generate(str + '(', left - 1, right);
			}
		}
		
	}
};

