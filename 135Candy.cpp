//
// Created by Yuyang Huang on 6/15/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 *
 * https://leetcode.com/problems/candy/description/
 *
 * algorithms
 * Hard (28.74%)
 * Likes:    542
 * Dislikes: 120
 * Total Accepted:    106K
 * Total Submissions: 367.9K
 * Testcase Example:  '[1,0,2]'
 *
 * There are N children standing in a line. Each child is assigned a rating
 * value.
 *
 * You are giving candies to these children subjected to the following
 * requirements:
 *
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 *
 *
 * What is the minimum candies you must give?
 *
 * Example 1:
 *
 *
 * Input: [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2,
 * 1, 2 candies respectively.
 *
 *
 * Example 2:
 *
 *
 * Input: [1,2,2]
 * Output: 4
 * Explanation: You can allocate to the first, second and third child with 1,
 * 2, 1 candies respectively.
 * â             The third child gets 1 candy because it satisfies the above two
 * conditions.
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(n)
 */
class Solution {
public:
	int candy(vector<int> &ratings) {
		int count = 1;
		int up = 0, down = 0, peak = 0;
		for (int i = 1; i < ratings.size(); ++i) {
			if (ratings[i - 1] < ratings[i]) {
				up++;
				down = 0;
				// count consecutive ups
				peak = up;
				count += up + 1;
			} else if (ratings[i - 1] == ratings[i]) {
				// for a plane, two person get same amount
				up = 0;
				down = 0;
				peak = 0;
				count += 1;
			} else if (ratings[i - 1] > ratings[i]) {
				up = 0;
				down++;
				count += 1 + down;
				if (peak >= down) {
					// decrease the need to matching height for the peak
					count -= 1;
				}
			}
		}
		return count;
	}
};
// @lc code=end

