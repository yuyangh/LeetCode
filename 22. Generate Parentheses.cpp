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

/*
 * Time complexity: O(2^(n/2))
 * recursion with condition
 */
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		addPar(res, "", n, 0);
		return res;
	}
	
	void addPar(vector<string> &v, string str, int left, int right) {
		if (left == 0 && right == 0) {
			v.push_back(str);
			return;
		}
		
		if (right > 0) { addPar(v, str + ")", left, right - 1); }
		
		// if we add a left parenthesis, we need to add a right one as well
		if (left > 0) { addPar(v, str + "(", left - 1, right + 1); }
	}
};

class OwnSolution {
public:
	vector<string> generateParenthesis(int n) {
		result.reserve(n * n);
		generate("", n, n);
		return result;
	}
	
	/*
	 * base on the left and right remaining, add "(" or ")" accordingly
	 */
	void generate(string str, int leftRemain, int rightRemain) {
		// base case
		if (rightRemain + leftRemain == 0) {
			while (rightRemain > 0) {
				str += ')';
				rightRemain--;
			}
			result.emplace_back(str);
			return;
		}
		
		if (leftRemain < rightRemain) {
			generate(str + '(', leftRemain - 1, rightRemain);
			generate(str + ')', leftRemain, rightRemain - 1);
		} else {
			if (leftRemain == rightRemain) {
				generate(str + '(', leftRemain - 1, rightRemain);
			}
		}
	}

private:
	vector<string> result;
};

