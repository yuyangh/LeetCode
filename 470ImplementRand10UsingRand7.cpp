//
// Created by Yuyang Huang on 10/24/19.
//

/*
 * @lc app=leetcode id=470 lang=cpp
 *
 * [470] Implement Rand10() Using Rand7()
 *
 * https://leetcode.com/problems/implement-rand10-using-rand7/description/
 *
 * algorithms
 * Medium (45.28%)
 * Likes:    267
 * Dislikes: 89
 * Total Accepted:    13.3K
 * Total Submissions: 29.4K
 * Testcase Example:  '1'
 *
 * Given a function rand7 which generates a uniform random integer in the range
 * 1 to 7, write a function rand10 which generates a uniform random integer in
 * the range 1 to 10.
 *
 * Do NOT use system's Math.random().
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: 1
 * Output: [7]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: 2
 * Output: [8,4]
 *
 *
 *
 * Example 3:
 *
 *
 * Input: 3
 * Output: [8,1,10]
 *
 *
 *
 *
 * Note:
 *
 *
 * rand7 is predefined.
 * Each testcase has one argument: n, the number of times that rand10 is
 * called.
 *
 *
 *
 *
 * Follow up:
 *
 *
 * What is the expected value for the number of calls to rand7() function?
 * Could you minimize the number of calls to rand7()?
 *
 *
 *
 *
 *
 */

#include "LeetCodeLib.h"

// @lc code=start
// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7
/*
 * Think of rand7() as having a 7 sided die.
 * Since we need rand10() (a 10 sided die) and 10 is greater than 7, we need to roll the 7 sided die multiple times.
 * Rolling the 7 sided die twice yields 49 different combinations, but multiplication is not uniform
 *    1  2  3  4  5  6  7
 * 1  1  2  3  4  5  6  7
 * 2  8  9  10 1  2  3  4
 * 3
 * 4
 * 5
 * 6
 * 7
 *
 * position (1,1) maps to outcome 1.
 * Position (1,2) maps to outcome 2.
 * ...
 * Position (1,7) maps to outcome 7.
 * Position (2,1) maps to outcome 8.
 * for positions larger than 40, we ignore that
 *
 * formula: result= (7*(row-1) + col-1) % 10 + 1
 *
 * time complexity: geometric series
 */
class Solution {
public:
	int rand10() {
		int result = 40;
		while (result >= 40) {
			result = 7 * (rand7() - 1) + rand7() - 1;
		}
		return result % 10 + 1;
	}
};
// @lc code=end


