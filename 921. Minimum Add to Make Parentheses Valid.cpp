//
// Created by Yuyang Huang on 9/1/21.
//

/*
 * 921. Minimum Add to Make Parentheses Valid
 * Medium
 *
 * A parentheses string is valid if and only if:
 * It is the empty string,
 * It can be written as AB (A concatenated with B), where A and B are valid strings, or
 * It can be written as (A), where A is a valid string.
 *
 * You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
 * For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
 * Return the minimum number of moves required to make s valid.
 *
 * Example 1:
 * Input: s = "())"
 * Output: 1
 *
 * Example 2:
 * Input: s = "((("
 * Output: 3
 *
 * Example 3:
 * Input: s = "()"
 * Output: 0
 *
 * Example 4:
 * Input: s = "()))(("
 * Output: 4
 *
 * Constraints:
 * 1 <= s.length <= 1000
 * s[i] is either '(' or ')'.
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(n)
	 */
	int minAddToMakeValid(string s) {
		int total = 0, unbalance = 0;
		for (auto &c:s) {
			if (c == '(') {
				unbalance++;
			}
			if (c == ')') {
				if (unbalance > 0) {
					unbalance--;
				} else {
					total++;
				}
			}
		}
		return total + unbalance;
	}
};