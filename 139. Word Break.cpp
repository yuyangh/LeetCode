//
// Created by Yuyang Huang on 8/22/21.
//

/*
 * 139. Word Break
 * Medium
 *
 * Given a string s and a dictionary of strings wordDict, return true
 * if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 * Note that the same word in the dictionary may be reused multiple times in the segmentation.
 *
 * Example 1:
 * Input: s = "leetcode", wordDict = ["leet","code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet code".
 *
 * Example 2:
 * Input: s = "applepenapple", wordDict = ["apple","pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
 * Note that you are allowed to reuse a dictionary word.
 *
 * Example 3:
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: false
 *
 * Constraints:
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s and wordDict[i] consist of only lowercase English letters.
 * All the strings of wordDict are unique.
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time Complexity: O(n^3)
	 * use dynamic programming to memorize places that can be made up by word dictionary
	 */
	bool wordBreak(string s, vector<string> &wordDict) {
		vector<bool> dp(s.size() + 1, false);
		dp.front() = true;
		
		unordered_set<string> wordSet;
		for (auto &word: wordDict) {
			wordSet.insert(word);
		}
		
		for (int i = 1; i < dp.size(); ++i) {
			for (int prevIdx = 0; prevIdx < i; prevIdx++) {
				// for each available index, check substring match dictionary
				if (dp[prevIdx]) {
					auto substring = s.substr(prevIdx, i - prevIdx);
					if (wordSet.count(substring) > 0) {
						dp[i] = true;
						break;
					}
				}
			}
			
		}
		return dp.back();
	}
};

int main() {
	Solution solution;
	string s;
	vector<string> wordDict;
	s = "leetcode", wordDict = {"leet", "code"};
	PrintSingleResult(solution.wordBreak(s, wordDict));
	
	s = "applepenapple", wordDict = {"apple", "pen"};
	PrintSingleResult(solution.wordBreak(s, wordDict));
	
	s = "catsandog", wordDict = {"cats", "dog", "sand", "and", "cat"};
	PrintSingleResult(solution.wordBreak(s, wordDict));
}
