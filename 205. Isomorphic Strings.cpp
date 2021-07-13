//
// Created by Yuyang Huang on 6/17/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 *
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 *
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 *
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 *
 * Note:
 * You may assume both sÂ and tÂ have the same length.
 */

// @lc code=start

/*
 * Time complexity: O(n)
 */
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size()) {
			return false;
		}
		
		// check whether char in t has already been mapped
		vector<bool> mappedTChars(128, false);
		
		unordered_map<char, char> charMap;
		for (int i = 0; i < s.size(); ++i) {
			auto it = charMap.find(s[i]);
			if (it == charMap.end()) {
				if (mappedTChars[t[i]]) {
					return false;
				}
				charMap[s[i]] = t[i];
				mappedTChars[t[i]] = true;
			} else {
				if (it->second == t[i]) {
					continue;
				} else {
					return false;
				}
			}
		}
		return true;
	}
};
// @lc code=end

int main() {
	Solution solution;
	
	assert(!solution.isIsomorphic("aa", "ab"));
	assert(solution.isIsomorphic("egg", "add"));
	assert(!solution.isIsomorphic("foo", "bar"));
	assert(solution.isIsomorphic("paper", "title"));
	
	Complete();
}
