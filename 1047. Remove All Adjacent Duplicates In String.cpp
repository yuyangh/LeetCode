//
// Created by Yuyang Huang on 6/28/21.
//

/*
 * 1047. Remove All Adjacent Duplicates In String
 * Easy
 *
 * You are given a string s consisting of lowercase English letters.
 * A duplicate removal consists of choosing two adjacent and equal letters and removing them.
 *
 * We repeatedly make duplicate removals on s until we no longer can.
 * Return the final string after all such duplicate removals have been made.
 * It can be proven that the answer is unique.
 *
 * Example 1:
 * Input: s = "abbaca"
 * Output: "ca"
 * Explanation:
 * For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal,
 * and this is the only possible move.  The result of this move is that the string is "aaca",
 * of which only "aa" is possible, so the final string is "ca".
 *
 * Example 2:
 * Input: s = "azxxzy"
 * Output: "ay"
 *
 * Constraints:
 * 1 <= s.length <= 105
 * s consists of lowercase English letters.
 */

#include "LeetCodeLib.h"

class Solution {
public:
	string removeDuplicates(string s) {
		stack<char> charStack;
		for (const auto &c : s) {
			if (charStack.empty()) {
				charStack.push(c);
				continue;
			}
			if (charStack.top() == c) {
				charStack.pop();
			} else {
				charStack.push(c);
			}
		}
		
		string result = "";
		while (!charStack.empty()) {
			result += charStack.top();
			charStack.pop();
		}
		reverse(result.begin(), result.end());
		
		return result;
	}
};

int main() {
	Solution solution;
	string s;
	s = "abbaca";
	PrintSingleResult(solution.removeDuplicates(s));
	
	s = "azxxzy";
	PrintSingleResult(solution.removeDuplicates(s));
}