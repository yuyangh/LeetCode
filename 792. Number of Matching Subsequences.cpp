//
// Created by Yuyang Huang on 6/22/21.
//

/*
 * 792. Number of Matching Subsequences
 * Medium
 *
 * Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
 * A subsequence of a string is a new string generated from the original string with some characters (can be none)
 * deleted without changing the relative order of the remaining characters.
 *
 * For example, "ace" is a subsequence of "abcde".
 *
 * Example 1:
 * Input: s = "abcde", words = ["a","bb","acd","ace"]
 * Output: 3
 * Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
 *
 * Example 2:
 * Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
 * Output: 2
 *
 * Constraints:
 * 1 <= s.length <= 5 * 104
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 50
 * s and words[i] consist of only lowercase English letters.
 */

#include "LeetCodeLib.h"

/*
 * Time Complexity: O(nlogk), n the length of string s, k is the length of word
 * use lower_bound to get first larger index element
 */
class Solution {
public:
	int numMatchingSubseq(string s, vector<string> &words) {
		vector<vector<int>> charPosArr(26, vector<int>());
		for (int i = 0; i < s.size(); ++i) {
			charPosArr[s[i] - 'a'].emplace_back(i);
		}
		
		int count = 0;
		for (const auto &word : words) {
			int prevLetterPos = -1;
			bool find = true;
			for (auto letter : word) {
				// prevLetterPos + 1 is avoiding searching on same position again
				auto it = lower_bound(charPosArr[letter - 'a'].begin(), charPosArr[letter - 'a'].end(),
				                      prevLetterPos + 1);
				if (it == charPosArr[letter - 'a'].end()) {
					find = false;
					break;
				}
				prevLetterPos = *it;
			}
			
			if (!find) {
				continue;
			}
			count++;
		}
		return count;
		
	}
};

int main() {
	Solution solution;
	string s;
	vector<string> words;
	
	s = "abcde", words = {"a", "bb", "acd", "ace"};
	PrintSingleResult(solution.numMatchingSubseq(s, words));
	
	
	s = "dsahjpjauf", words = {"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"};
	PrintSingleResult(solution.numMatchingSubseq(s, words));
	
	Complete();
	
}

