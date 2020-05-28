//
// Created by Yuyang Huang on 5/28/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Medium (65.91%)
 * Likes:    2466
 * Dislikes: 153
 * Total Accepted:    263.9K
 * Total Submissions: 384.8K
 * Testcase Example:  '2'
 *
 * Given a non negative integer number num. For every numbers i in the range 0
 * â‰¤ i â‰¤ num calculate the number of 1's in their binary representation and
 * return them as an array.
 *
 * Example 1:
 *
 *
 * Input: 2
 * Output: [0,1,1]
 *
 * Example 2:
 *
 *
 * Input: 5
 * Output: [0,1,1,2,1,2]
 *
 *
 * Follow up:
 *
 *
 * It is very easy to come up with a solution with run time
 * O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a
 * single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like
 * __builtin_popcount in c++ or in any other language.
 *
 */

// @lc code=start
/*
 * Time complexity: O(n)
 */
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> bitsCount(num + 1, 0);
		
		// get the count for the upper part in binary + lower bit
		for (unsigned int i = 1; i <= num; ++i) {
			bitsCount[i] = bitsCount[i >> 1] + i % 2;
		}
		
		return bitsCount;
	}
};
// @lc code=end

int main() {
	Solution solution;
	PrintVector(solution.countBits(0));
	PrintVector(solution.countBits(1));
	PrintVector(solution.countBits(2));
	PrintVector(solution.countBits(5));
	Complete();
}