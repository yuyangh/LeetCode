//
// Created by Yuyang Huang on 10/28/19.
//

/*
 * Given an input string , reverse the string word by word.
 * Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
 * Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
 *
 * Note:
 * A word is defined as a sequence of non-space characters.
 * The input string does not contain leading or trailing spaces.
 * The words are always separated by a single space.
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * time complexity: O(n)
	 */
	void reverseWords(vector<char> &s) {
		if (s.empty() || s.size() <= 1) {
			return;
		}
		int left = 0, right = left + 1;
		while (left < s.size()) {
			while (right < s.size() && s[right] != ' ') {
				right++;
			}
			// reverse single word
			reverse(s.begin() + left, s.begin() + right);
			right++;
			left = right;
		}
		// reverse whole sentence
		reverse(s.begin(), s.end());
	}
};