//
// Created by Yuyang Huang on 8/21/21.
//

/*
 * 680. Valid Palindrome II
 * Easy
 *
 * Given a string s, return true if the s can be palindrome after deleting at most one character from it.
 *
 * Example 1:
 * Input: s = "aba"
 * Output: true
 *
 * Example 2:
 * Input: s = "abca"
 * Output: true
 * Explanation: You could delete the character 'c'.
 *
 * Example 3:
 * Input: s = "abc"
 * Output: false
 *
 * Constraints:
 * 1 <= s.length <= 105
 * s consists of lowercase English letters.
 */
#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * check palindrome until there is a conflict
	 * then check with either deleting left or right
	 */
	bool validPalindrome(string s) {
		int left = 0, right = s.size() - 1;
		while (left <= right) {
			if (s[left] != s[right]) {
				bool checkLeft = checkPalindrome(s, left + 1, right);
				bool checkRight = checkPalindrome(s, left, right - 1);
				return checkLeft || checkRight;
			}
			left++;
			right--;
		}
		return true;
	}
	
	bool checkPalindrome(string str, int left, int right) {
		while (left <= right) {
			if (str[left] != str[right]) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
};