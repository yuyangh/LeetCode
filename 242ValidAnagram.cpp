//
// Created by Yuyang Huang on 6/8/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (53.96%)
 * Likes:    1434
 * Dislikes: 136
 * Total Accepted:    549.2K
 * Total Submissions: 976.4K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and tÂ , write a function to determine if t is an anagram
 * of s.
 *
 * Example 1:
 *
 *
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "rat", t = "car"
 * Output: false
 *
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 *
 */

// @lc code=start

/*
 * Time complexity: O(n)
 * use +1 and -1 to compare char difference
 */
class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) {
			return false;
		}
		vector<int> countChar(26, 0);
		for (int i = 0; i < s.size(); ++i) {
			countChar[s[i] - 'a']++;
			countChar[t[i] - 'a']--;
		}
		for (const auto &item : countChar) {
			if (item != 0) {
				return false;
			}
		}
		return true;
	}
};
// @lc code=end

