//
// Created by Yuyang Huang on 10/14/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 *
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/
 *
 * algorithms
 * Medium (57.82%)
 * Likes:    748
 * Dislikes: 17
 * Total Accepted:    44.5K
 * Total Submissions: 77.8K
 * Testcase Example:  '"abcd"\n2'
 *
 * Given a string s, a k duplicate removal consists of choosing k adjacent and
 * equal letters from s and removing them causing the left and the right side
 * of the deleted substring to concatenate together.
 *
 * We repeatedly make k duplicate removals on s until we no longer can.
 *
 * Return the final string after all such duplicate removals have been made.
 *
 * It is guaranteed that the answer is unique.
 *
 *
 * Example 1:
 * Input: s = "abcd", k = 2
 * Output: "abcd"
 * Explanation: There's nothing to delete.
 *
 * Example 2:
 * Input: s = "deeedbbcccbdaa", k = 3
 * Output: "aa"
 * Explanation:
 * First delete "eee" and "ccc", get "ddbbbdaa"
 * Then delete "bbb", get "dddaa"
 * Finally delete "ddd", get "aa"
 *
 * Example 3:
 * Input: s = "pbbcggttciiippooaais", k = 2
 * Output: "ps"
 *
 *
 *
 * Constraints:
 * 1 <= s.length <= 10^5
 * 2 <= k <= 10^4
 * s only contains lower case English letters.
 *
 *
 */

// @lc code=start
/*
 * Time complexity: O(n)
 */
class Solution {
public:
	string removeDuplicates(string s, int k) {
		vector<pair<char, int>> charCountArr;
		string result;
		
		for (const auto &c : s) {
			processChar(charCountArr, c, k);
		}
		
		// reconstruct the string
		for (const auto &item : charCountArr) {
			if (item.second >= k) {
				continue;
			}
			for (int i = 0; i < item.second; ++i) {
				result += item.first;
			}
		}
		return result;
	}
	
	void processChar(vector<pair<char, int>> &charCountArr, char c, int k) {
		if (charCountArr.empty()) {
			charCountArr.emplace_back(c, 1);
			return;
		}
		
		auto item = charCountArr.back();
		if (item.first == c) {
			charCountArr.back().second++;
			// check if we reach k repetitions
			if (charCountArr.back().second == k) {
				charCountArr.pop_back();
			}
		} else {
			charCountArr.emplace_back(c, 1);
		}
	}
};
// @lc code=end

