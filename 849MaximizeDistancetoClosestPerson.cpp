//
// Created by Yuyang Huang on 5/27/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=849 lang=cpp
 *
 * [849] Maximize Distance to Closest Person
 *
 * https://leetcode.com/problems/maximize-distance-to-closest-person/description/
 *
 * algorithms
 * Easy (41.73%)
 * Likes:    715
 * Dislikes: 99
 * Total Accepted:    58.8K
 * Total Submissions: 138.4K
 * Testcase Example:  '[1,0,0,0,1,0,1]'
 *
 * In a row of seats, 1 represents a person sitting in that seat, and 0
 * represents that the seat is empty.Â 
 *
 * There is at least one empty seat, and at least one person sitting.
 *
 * Alex wants to sit in the seat such that the distance between him and the
 * closest person to him is maximized.Â 
 *
 * Return that maximum distance to closest person.
 *
 *
 * Example 1:
 *
 *
 * Input: [1,0,0,0,1,0,1]
 * Output: 2
 * Explanation:
 * If Alex sits in the second open seat (seats[2]), then the closest person has
 * distance 2.
 * If Alex sits in any other open seat, the closest person has distance 1.
 * Thus, the maximum distance to the closest person is 2.
 *
 *
 * Example 2:
 *
 *
 * Input: [1,0,0,0]
 * Output: 3
 * Explanation:
 * If Alex sits in the last seat, the closest person is 3 seats away.
 * This is the maximum distance possible, so the answer is 3.
 *
 *
 * Note:
 *
 *
 * 1 <= seats.length <= 20000
 * seatsÂ contains only 0s or 1s, at least one 0, and at least one 1.
 *
 *
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(n)
 * space complexity: O(1)
 */
class Solution {
public:
	int maxDistToClosest(vector<int> &seats) {
		int lastOnePos = -1, begin, between = 0, end;
		
		// beginning part
		for (int i = 0; i < seats.size(); ++i) {
			if (seats[i] == 1) {
				lastOnePos = i;
				break;
			}
		}
		begin = lastOnePos;
		
		// between part
		for (int j = lastOnePos + 1; j < seats.size(); ++j) {
			if (seats[j] == 1) {
				between = max((j - lastOnePos) / 2, between);
				lastOnePos = j;
			}
		}
		// end part
		end = static_cast<int>(seats.size()) - lastOnePos - 1;
		return max({begin, between, end});
	}
};
// @lc code=end

int main() {
	Solution solution;
	vector<int> arr = {1, 0, 0, 0, 1, 0, 1};
	assert(solution.maxDistToClosest(arr) == 2);
	arr = {1, 0, 0, 0};
	assert(solution.maxDistToClosest(arr) == 3);
	arr = {0, 0, 1, 0, 0};
	assert(solution.maxDistToClosest(arr) == 2);
	arr = {1, 0, 0, 1};
	assert(solution.maxDistToClosest(arr) == 1);
	Complete();
}