//
// Created by Yuyang Huang on 6/4/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (64.42%)
 * Likes:    1346
 * Dislikes: 672
 * Total Accepted:    717.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters char[].
 *
 * Do not allocate extra space for another array, you must do this by modifying
 * the input arrayÂ in-place with O(1) extra memory.
 *
 * You may assume all the characters consist of printable ascii
 * characters.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
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
	void reverseString(vector<char>& s) {
		reverse(s.begin(),s.end());
	}
};
// @lc code=end

