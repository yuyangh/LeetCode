//
// Created by Yuyang Huang on 9/27/21.
//

/*
 * 1048. Longest String Chain
 * Medium
 *
 * You are given an array of words where each word consists of lowercase English letters.
 * wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA
 * without changing the order of the other characters to make it equal to wordB.
 *
 * For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
 * A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1,
 * where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on.
 * A single word is trivially a word chain with k == 1.
 *
 * Return the length of the longest possible word chain with words chosen from the given list of words.
 *
 * Example 1:
 * Input: words = ["a","b","ba","bca","bda","bdca"]
 * Output: 4
 * Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
 *
 * Example 2:
 * Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
 * Output: 5
 * Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
 *
 * Example 3:
 * Input: words = ["abcd","dbqca"]
 * Output: 1
 * Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
 * ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 *
 * Constraints:
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 16
 * words[i] only consists of lowercase English letters.
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * use recursion & memorization to remember the longest chain
	 */
	int longestStrChain(vector<string> &words) {
		unordered_map<int, vector<string>> lengthStringMap;
		unordered_map<string, int> stringChainLengthMap;
		for (auto &word: words) {
			lengthStringMap[word.size()].emplace_back(word);
		}
		
		int maxLength = 0;
		for (auto &word: words) {
			int length = helper(lengthStringMap, stringChainLengthMap, word);
			maxLength = max(maxLength, length);
		}
		
		return maxLength;
	}

private:
	int helper(unordered_map<int, vector<string>> &lengthStringMap,
	           unordered_map<string, int> &stringChainLengthMap, string &str) {
		auto currStrLength = str.size();
		auto followers = lengthStringMap[currStrLength + 1];
		
		// no next level
		if (followers.empty()) {
			stringChainLengthMap[str] = 1;
			return 1;
		}
		
		int longestChain = 0;
		// visit each possible follower
		for (auto &follower: followers) {
			int chainLength = 0;
			if (!isPredecessor(str, follower)) { continue; }
			
			// check from memorization
			if (stringChainLengthMap[follower] != 0) {
				chainLength = stringChainLengthMap[follower];
			} else {
				chainLength = helper(lengthStringMap, stringChainLengthMap, follower);
			}
			longestChain = max(longestChain, chainLength);
		}
		stringChainLengthMap[str] = longestChain + 1;
		
		return longestChain + 1;
	}
	
	bool isPredecessor(string &curr, string &next) {
		if (curr.size() + 1 != next.size()) {
			return false;
		}
		uint ci = 0, ni = 0;
		for (; ci < curr.size(); ci++) {
			if (curr[ci] != next[ni]) {
				// go to next char
				ni++;
				if (curr[ci] != next[ni]) {
					return false;
				}
			}
			ni++;
		}
		return true;
	}
};

int main() {
	Solution solution;
	vector<string> words;
	words = {"a", "b", "ba", "bca", "bda", "bdca"};
	PrintSingleResult(solution.longestStrChain(words));
	
	words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
	PrintSingleResult(solution.longestStrChain(words));
	
	words = {"abcd", "dbqca"};
	PrintSingleResult(solution.longestStrChain(words));
}