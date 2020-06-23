//
// Created by Yuyang Huang on 5/25/20.
//

#include "LeetCodeLib.h"

/*
 * 159. Longest Substring with At Most Two Distinct Characters
 *
 * Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.
 * Example 1:
 * Input: "eceba"
 * Output: 3
 * Explanation: t is "ece" which its length is 3.
 *
 * Example 2:
 * Input: "ccaabbb"
 * Output: 5
 * Explanation: t is "aabbb" which its length is 5.
 */

/*
 * Time complexity: O(n)
 * sliding window
 */
class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		unordered_map<char, int> charCountMap;
		int start, cur;
		for (start = 0, cur = 0; cur < s.size(); ++cur) {
			charCountMap[s[cur]]++;
			// find the maximum window
			if (charCountMap.size() > 2) {
				charCountMap[s[start]]--;
				if (charCountMap[s[start]] == 0) {
					charCountMap.erase(s[start]);
				}
				start++;
			}
		}
		return cur - start;
	}
};

int main() {
	Solution solution;
	assert(solution.lengthOfLongestSubstringTwoDistinct("eceba") == 3);
	Complete();
}