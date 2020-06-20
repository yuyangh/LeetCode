//
// Created by Yuyang Huang on 6/20/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 *
 * https://leetcode.com/problems/jewels-and-stones/description/
 *
 * algorithms
 * Easy (83.89%)
 * Likes:    2058
 * Dislikes: 362
 * Total Accepted:    505.4K
 * Total Submissions: 586.8K
 * Testcase Example:  '"aA"\n"aAAbbbb"'
 *
 * You're given strings J representing the types of stones that are jewels, and
 * S representing the stones you have.Â  Each character in S is a type of stone
 * you have.Â  You want to know how many of the stones you have are also
 * jewels.
 *
 * The letters in J are guaranteed distinct, and all characters in J and S are
 * letters. Letters are case sensitive, so "a" is considered a different type
 * of stone from "A".
 *
 * Example 1:
 *
 *
 * Input: J = "aA", S = "aAAbbbb"
 * Output: 3
 *
 *
 * Example 2:
 *
 *
 * Input: J = "z", S = "ZZ"
 * Output: 0
 *
 *
 * Note:
 *
 *
 * S and J will consist of letters and have length at most 50.
 * The characters in J are distinct.
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(n)
 */
class Solution {
public:
	int numJewelsInStones(string J, string S) {
		vector<bool> existence(128, false);
		for (auto item : J) {
			existence[item] = true;
		}
		
		int result = 0;
		for (auto s : S) {
			result += existence[s] ? 1 : 0;
		}
		return result;
	}
};
// @lc code=end

int main() {
	Solution solution;
	string J = "aA", S = "aAAbbbb";
	assert(solution.numJewelsInStones(J, S) == 3);
	J = "z", S = "ZZ";
	assert(solution.numJewelsInStones(J, S) == 0);
	Complete();
}
