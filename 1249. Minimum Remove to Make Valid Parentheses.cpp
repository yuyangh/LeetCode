//
// Created by Yuyang Huang on 8/19/21.
//

/*
 * 1249. Minimum Remove to Make Valid Parentheses
 * Medium
 *
 * Given a string s of '(' , ')' and lowercase English characters.
 * Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions )
 * so that the resulting parentheses string is valid and return any valid string.
 *
 * Formally, a parentheses string is valid if and only if:
 * It is the empty string, contains only lowercase characters, or
 * It can be written as AB (A concatenated with B), where A and B are valid strings, or
 * It can be written as (A), where A is a valid string.
 *
 * Example 1:
 * Input: s = "lee(t(c)o)de)"
 * Output: "lee(t(c)o)de"
 * Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
 *
 * Example 2:
 * Input: s = "a)b(c)d"
 * Output: "ab(c)d"
 *
 * Example 3:
 * Input: s = "))(("
 * Output: ""
 * Explanation: An empty string is also valid.
 *
 * Example 4:
 * Input: s = "(a(b(c)d)"
 * Output: "a(b(c)d)"
 *
 * Constraints:
 * 1 <= s.length <= 10^5
 * s[i] is one of  '(' , ')' and lowercase English letters.
 */

#include "LeetCodeLib.h"

class Solution {
public:
	string minRemoveToMakeValid(string s) {
		stack<int> idxStack;
		unordered_set<int> idxToRemove;
		string result;
		
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') { idxStack.push(i); }
			if (s[i] == ')') {
				if (!idxStack.empty()) { idxStack.pop(); }
				else { idxToRemove.insert(i); }
			}
		}
		
		// collect idx to be removed
		while (!idxStack.empty()) {
			int idx = idxStack.top();
			idxStack.pop();
			idxToRemove.insert(idx);
		}
		
		for (int i = 0; i < s.size(); i++) {
			if (idxToRemove.count(i) == 0) {
				result.push_back(s[i]);
			}
		}
		
		return result;
	}
};

int main() {
	Solution solution;
	string result;
	PrintSingleResult(solution.minRemoveToMakeValid("))(("));
	
}