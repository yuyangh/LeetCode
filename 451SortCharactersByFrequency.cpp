//
// Created by Yuyang Huang on 5/22/20.
//

#include "LeetCodeLib.h"


/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 *
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (57.64%)
 * Likes:    1409
 * Dislikes: 116
 * Total Accepted:    174.8K
 * Total Submissions: 282.3K
 * Testcase Example:  '"tree"'
 *
 * Given a string, sort it in decreasing order based on the frequency of
 * characters.
 *
 * Example 1:
 *
 * Input:
 * "tree"
 *
 * Output:
 * "eert"
 *
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * "cccaaa"
 *
 * Output:
 * "cccaaa"
 *
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 *
 *
 *
 * Example 3:
 *
 * Input:
 * "Aabb"
 *
 * Output:
 * "bbAa"
 *
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 *
 *
 */

// @lc code=start

/*
 * time complexity O(n)
 */
class Solution {
public:
	string frequencySort(string s) {
		// store char into array
		vector<pair<char, unsigned int>> charCountArr(128);
		for (int i = 0; i < charCountArr.size(); ++i) {
			charCountArr[i] = make_pair(i, 0);
		}
		string result;
		result.reserve(s.size());
		// accumulate the count
		for (const auto &character : s) {
			charCountArr[character].second++;
		}
		// sort in descending order
		sort(charCountArr.begin(), charCountArr.end(),
		     [&charCountArr](pair<char, unsigned int> &lhs, pair<char, unsigned int> &rhs) {
			     return (lhs.second > rhs.second);
		     });
		
		for (const auto &item : charCountArr) {
			if (item.second == 0) {
				break;
			}
			for (int i = 0; i < item.second; ++i) {
				result += item.first;
			}
		}
		return result;
	}
};
// @lc code=end

int main() {
	Solution solution;
	assert(solution.frequencySort("tree") == "eetr");
	assert(solution.frequencySort("cccaaa") == "cccaaa");
	Complete();
}

