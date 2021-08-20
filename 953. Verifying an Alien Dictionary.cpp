//
// Created by Yuyang Huang on 8/20/21.
//

/*
 * 953. Verifying an Alien Dictionary
 * Easy
 *
 * In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order.
 * The order of the alphabet is some permutation of lowercase letters.
 * Given a sequence of words written in the alien language, and the order of the alphabet,
 * return true if and only if the given words are sorted lexicographically in this alien language.
 *
 * Example 1:
 * Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
 * Output: true
 * Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
 *
 * Example 2:
 * Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
 * Output: false
 * Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
 *
 * Example 3:
 * Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
 * Output: false
 * Explanation: The first three characters "app" match, and the second string is shorter (in size.)
 * According to lexicographical rules "apple" > "app", because 'l' > '∅',
 * where '∅' is defined as the blank character which is less than any other character (More info).
 *
 * Constraints:
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 20
 * order.length == 26
 * All characters in words[i] and order are English lowercase letters.
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(NS)
	 * Build a transform mapping from order,
	 * Find all alien words with letters in normal order.
	 * For example, if we have order = "xyz..."
	 * We can map the word "xyz" to "abc" or "123"
	 * Then we check if all words are in sorted order.
	 */
	bool isAlienSorted(vector<string> &words, string order) {
		vector<char> mapping(order.size());
		for (int i=0;i<26;i++) {
			mapping[order[i] - 'a']=i;
		}
		
		// do the replacement
		for (auto &word:words) {
			for (auto &c:word) {
				c = mapping[c - 'a'];
			}
		}
		return is_sorted(words.begin(), words.end());
	}
};

int main() {
	Solution solution;
	vector<string> words;
	string order;
	
	words = {"hello", "leetcode"}, order = "hlabcdefgijkmnopqrstuvwxyz";
	PrintSingleResult(solution.isAlienSorted(words, order));
	
	words = {"word", "world", "row"}, order = "worldabcefghijkmnpqstuvxyz";
	PrintSingleResult(solution.isAlienSorted(words, order));
	
	words = {"apple", "app"}, order = "abcdefghijklmnopqrstuvwxyz";
	PrintSingleResult(solution.isAlienSorted(words, order));
}