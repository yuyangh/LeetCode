//
// Created by Yuyang Huang on 5/24/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (30.72%)
 * Likes:    2256
 * Dislikes: 156
 * Total Accepted:    236.7K
 * Total Submissions: 768.6K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 *
 * Example:
 *
 *
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 *
 *
 * Note:
 *
 *
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 *
 *
 */

/*
 * time complexity: O(n)
 * sliding window approach
 * record count of each char in the string, if the char count >= required char count, mark that char as satisfied
 * if the number of satisfied == uniqueChars in t, then it is one window
 */
class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, unsigned int> charCountMap;
		unordered_map<char, bool> charSatisfiedMap;
		vector<int> requiredChars(128, 0);
		int uniqueChars = 0;
		bool find = false;
		string result;
		
		// record letter and count in t
		for (const auto &letter : t) {
			requiredChars[letter]++;
		}
		// record unique number of letters in t
		for (const auto &item : requiredChars) {
			if (item > 0) {
				uniqueChars++;
			}
		}
		
		int start, cur;
		for (start = 0, cur = 0; cur < s.size(); ++cur) {
			if (requiredChars[s[cur]]) {
				charCountMap[s[cur]]++;
				// mark that char being satisfied
				if (charCountMap[s[cur]] >= requiredChars[s[cur]]) {
					charSatisfiedMap[s[cur]] = true;
				}
				
				// record and shrink the window from left side
				while (start <= cur && charSatisfiedMap.size() == uniqueChars) {
					if (!find || cur - start + 1 < result.size()) {
						result = s.substr(start, cur - start + 1);
						find = true;
					}
					
					if (requiredChars[s[start]]) {
						charCountMap[s[start]]--;
						if (charCountMap[s[start]] < requiredChars[s[start]]) {
							charSatisfiedMap.erase(s[start]);
						}
					}
					start++;
				}
			}
		}
		return result;
	}
};

int main() {
	Solution solution;
	assert(solution.minWindow("ADOBECODEBANC", "ABC") == "BANC");
	assert(solution.minWindow("a", "a") == "a");
	assert(solution.minWindow("aa", "aa") == "aa");
	Complete();
	
}

