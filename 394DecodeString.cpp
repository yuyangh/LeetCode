//
// Created by Yuyang Huang on 9/11/19.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (46.26%)
 * Likes:    1830
 * Dislikes: 99
 * Total Accepted:    127K
 * Total Submissions: 274.6K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 *
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 *
 * Examples:
 *
 *
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 */

class Solution {
public:
	string decodeString(string s) {
		// base case for empty
		if (s.empty()) {
			return "";
		}
		
		stack<string> strStack;
		stack<int> countStack;
		string result;
		
		// go through the contents in the string
		for (unsigned int i = 0; i < s.size(); i++) {
			if (isdigit(s[i])) {
				// accumulate the digits
				int num = 0;
				while (i < s.size() && isdigit(s[i])) {
					num = num * 10 + s[i] - '0';
					i++;
				}
				if (num != 0) {
					countStack.push((num));
				}
				// handle for loop's auto increase
				i--;
			} else {
				if (s[i] == '[') {
					// push prev result into stack
					// we are working on stuff in the []
					strStack.push(result);
					result = "";
					
				} else {
					// end bracket
					if (s[i] == ']') {
						string prev = strStack.top();
						strStack.pop();
						
						int times = countStack.top();
						countStack.pop();
						
						// construct the string that will be repeated for times
						string repeatedStr;
						for (int j = 0; j < times; j++) {
							repeatedStr += result;
						}
						
						// add the current part to the previous part
						result = prev + repeatedStr;
						
					} else {
						// handle alpha situation
						result += s[i];
					}
				}
			}
		}
		return result;
	}
};

int main() {
	Solution solution;
	
	string result;
	result = solution.decodeString("3[a]2[bc]");
	PrintSingleResult(result);
	result = solution.decodeString("3[a2[c]]");
	PrintSingleResult(result);
	
	result = solution.decodeString("2[abc]3[cd]ef");
	PrintSingleResult(result);
	
	return 0;
}