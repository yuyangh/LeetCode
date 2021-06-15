//
// Created by Yuyang Huang on 6/14/21.
//

/*
 * 336. Palindrome Pairs
 * Hard
 *
 * Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list,
 * so that the concatenation of the two words words[i] + words[j] is a palindrome.
 *
 * Example 1:
 * Input: words = ["abcd","dcba","lls","s","sssll"]
 * Output: [[0,1],[1,0],[3,2],[2,4]]
 * Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
 *
 * Example 2:
 * Input: words = ["bat","tab","cat"]
 * Output: [[0,1],[1,0]]
 * Explanation: The palindromes are ["battab","tabbat"]
 *
 * Example 3:
 * Input: words = ["a",""]
 * Output: [[0,1],[1,0]]
 *
 * Constraints:
 * 1 <= words.length <= 5000
 * 0 <= words[i].length <= 300
 * words[i] consists of lower-case English letters.
 */

#include "LeetCodeLib.h"

/*
 * Time Complexity: O(nk)
 * use a hashtable to find possible prefix or suffix that can constitute a palindrome
 */
class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string> &words) {
		vector<vector<int>> result;
		
		unordered_map<string, int> stringIndexMap;
		for (int i = 0; i < words.size(); ++i) {
			stringIndexMap.emplace(words[i], i);
		}
		
		for (const auto &word : words) {
			ExactPalindrome(stringIndexMap, result, word);
			SuffixPalindrome(stringIndexMap, result, word);
			PrefixPalindrome(stringIndexMap, result, word);
		}
		return result;
	}

private:
	void ExactPalindrome(unordered_map<string, int> &stringIndexMap, vector<vector<int>> &result, const string &word) {
		if (checkPalindrome(word)) {
			// self palindrome case
			auto targetIt = stringIndexMap.find("");
			if (targetIt != stringIndexMap.end() &&
			    targetIt->second != stringIndexMap.find(word)->second) {
				result.push_back({stringIndexMap.find(word)->second, targetIt->second});
				result.push_back({ targetIt->second,stringIndexMap.find(word)->second});
			}
		} else {
			// find exact reverse match
			string reversedWord = word;
			reverse(reversedWord.begin(), reversedWord.end());
			auto targetIt = stringIndexMap.find(reversedWord);
			if (targetIt != stringIndexMap.end() &&
			    targetIt->second != stringIndexMap.find(word)->second) {
				result.push_back({stringIndexMap.find(word)->second, targetIt->second});
			}
		}
	}
	
	/*
	 * Suffix is a palindrome, and look for a match for prePalindromePart
	 */
	void SuffixPalindrome(unordered_map<string, int> &stringIndexMap, vector<vector<int>> &result, const string &word) {
		for (int i = 1; i < word.size(); ++i) {
			string middlePart = word.substr(i);
			if (checkPalindrome(middlePart)) {
				auto prePalindromePart=word.substr(0, i);
				reverse(prePalindromePart.begin(), prePalindromePart.end());
				auto targetIt = stringIndexMap.find(prePalindromePart);
				if (targetIt != stringIndexMap.end() &&
				    targetIt->second != stringIndexMap.find(word)->second) {
					result.push_back({stringIndexMap.find(word)->second, targetIt->second});
				}
			}
		}
	}
	
	void PrefixPalindrome(unordered_map<string, int> &stringIndexMap, vector<vector<int>> &result, const string &word) {
		for (int i = static_cast<int>(word.size()) - 1; i >= 1; --i) {
			string middlePart = word.substr(0, i);
			if (checkPalindrome(middlePart)) {
				auto postPalindromePart=word.substr(i);
				reverse(postPalindromePart.begin(), postPalindromePart.end());
				auto targetIt = stringIndexMap.find(postPalindromePart);
				if (targetIt != stringIndexMap.end() &&
				    targetIt->second != stringIndexMap.find(word)->second) {
					result.push_back({targetIt->second, stringIndexMap.find(word)->second});
				}
			}
		}
	}
	
	bool checkPalindrome(const string &word) {
		for (int i = 0; i < word.size() / 2; ++i) {
			if (word[i] != word[word.size() - 1 - i]) {
				return false;
			}
		}
		return true;
	}
};

int main(){
	Solution solution;
	vector<string > words;
	
	PrintSingleResult("");
	words= {"abcd","dcba","lls","s","sssll"};
	PrintVectorVector(solution.palindromePairs(words));
	
	PrintSingleResult("");
	words = {"bat","tab","cat"};
	PrintVectorVector(solution.palindromePairs(words));
	
	PrintSingleResult("");
	words = {"a",""};
	PrintVectorVector(solution.palindromePairs(words));
	
	Complete();
}