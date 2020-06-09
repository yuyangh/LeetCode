//
// Created by Yuyang Huang on 6/9/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 *
 * https://leetcode.com/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (47.62%)
 * Likes:    1329
 * Dislikes: 195
 * Total Accepted:    187.8K
 * Total Submissions: 384.2K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * Given a string s and a string t, check if s is subsequence of t.
 *
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ace" is a
 * subsequence of "abcde" while "aec" is not).
 *
 * Follow up:
 * If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you
 * want to check one by one to see if T has its subsequence. In this scenario,
 * how would you change your code?
 *
 * Credits:
 * Special thanks to @pbrother for adding this problem and creating all test
 * cases.
 *
 *
 * Example 1:
 * Input: s = "abc", t = "ahbgdc"
 * Output: true
 * Example 2:
 * Input: s = "axc", t = "ahbgdc"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 100
 * 0 <= t.length <= 10^4
 * Both strings consists only of lowercase characters.
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(m+n)
 * greedy approach
 */
class Solution {
public:
	bool isSubsequence(string s, string t) {
		if (s.empty() && t.empty()) {
			return true;
		}
		
		int sIdx = 0, tIdx = 0;
		for (tIdx = 0; tIdx < t.size(); ++tIdx) {
			if (s[sIdx] == t[tIdx]) {
				sIdx++;
			}
			if (sIdx >= s.size()) {
				return true;
			}
		}
		return false;
	}
};
// @lc code=end

int main() {
	Solution solution;
	string s, t;
	s = "abc";
	t = "ahbgdc";
	PrintSingleResult(solution.isSubsequence(s,t));
	PrintSingleResult(solution.isSubsequence("b","c"));
	PrintSingleResult(solution.isSubsequence("b","b"));
	
	Complete();
}
