//
// Created by Yuyang Huang on 5/31/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (38.39%)
 * Likes:    2264
 * Dislikes: 34
 * Total Accepted:    183.9K
 * Total Submissions: 477.5K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 *
 * You have the following 3 operations permitted on a word:
 *
 *
 * Insert a character
 * Delete a character
 * Replace a character
 *
 *
 * Example 1:
 *
 *
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation:
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 *
 *
 * Example 2:
 *
 *
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation:
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(mn)
 * dynamic programing
 */
class Solution {
public:
	int minDistance(string word1, string word2) {
		// edit distance from word1[i] to word2[j]
		vector<vector<int>> distance(word1.size() + 1, vector<int>(word2.size() + 1));
		
		// initialize for empty word case
		for (int col = 0; col < distance[0].size(); ++col) {
			distance[0][col] = col;
		}
		for (int row = 0; row < distance.size(); ++row) {
			distance[row][0] = row;
		}
		
		// if word1[i]==word2[j], compare distance[i-1][j-1] with
		// +1 for from up or left because we have already use one of the word1[i] or word2[j]
		for (int word1idx = 1; word1idx < word1.size() + 1; ++word1idx) {
			for (int word2idx = 1; word2idx < word2.size() + 1; ++word2idx) {
				if (word1[word1idx - 1] == word2[word2idx-1]) {
					distance[word1idx][word2idx] = min({distance[word1idx - 1][word2idx] + 1,
					                                    distance[word1idx][word2idx - 1] + 1,
					                                    distance[word1idx-1][word2idx-1]});
				} else {
					distance[word1idx][word2idx] = 1 + min({distance[word1idx - 1][word2idx],
					                                        distance[word1idx][word2idx - 1],
					                                        distance[word1idx-1][word2idx-1]});
				}
			}
		}
		return distance.back().back();
	}
};

// @lc code=end
int main() {
	Solution solution;
	string word1 = "horse", word2 = "ros";
	assert(solution.minDistance(word1, word2) == 3);
	word1 = "intention", word2 = "execution";
	assert(solution.minDistance(word1, word2) == 5);
	Complete();
}
