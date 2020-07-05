//
// Created by Yuyang Huang on 7/5/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (70.73%)
 * Likes:    1782
 * Dislikes: 158
 * Total Accepted:    332.2K
 * Total Submissions: 459.2K
 * Testcase Example:  '1\n4'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 *
 * Given two integers x and y, calculate the Hamming distance.
 *
 * Note:
 * 0 â‰¤ x, y < 2^31.
 *
 *
 * Example:
 *
 * Input: x = 1, y = 4
 *
 * Output: 2
 *
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * â�       â†‘   â†‘
 *
 * The above arrows point to positions where the corresponding bits are
 * different.
 *
 *
 */

// @lc code=start
class Solution {
public:
	/*
	 * Time complexity: O(1)
	 */
	int hammingDistance(int x, int y) {
		bitset<32> num(x xor y);
		return num.count();
	}
};
// @lc code=end

int main(){
	Solution solution;
	PrintSingleResult(solution.hammingDistance(1,4));
}