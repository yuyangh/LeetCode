//
// Created by Yuyang Huang on 6/29/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (39.68%)
 * Likes:    1530
 * Dislikes: 128
 * Total Accepted:    141.6K
 * Total Submissions: 354.2K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given an unsorted array return whether an increasing subsequence of length 3
 * exists or not in the array.
 *
 * Formally the function should:
 *
 * Return true if there exists i, j, k
 * such that arr[i] < arr[j] < arr[k] given 0 â‰¤ i < j < k â‰¤ n-1 else return
 * false.
 *
 * Note: Your algorithm should run in O(n) time complexity and O(1) space
 * complexity.
 *
 *
 * Example 1:
 *
 *
 * Input: [1,2,3,4,5]
 * Output: true
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [5,4,3,2,1]
 * Output: false
 *
 *
 *
 */

// @lc code=start
class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * space complexity: O(1)
	 */
	bool increasingTriplet(vector<int> &nums) {
		int c1 = INT_MAX, c2 = INT_MAX;
		for (int x : nums) {
			// go to the next condition iff the num is greater than existing one
			if (x <= c1) {
				c1 = x;           // c1 is min seen so far (it's a candidate for 1st element)
			} else if (x <= c2) { // here when x > c1, i.e. x might be either c2 or c3
				c2 = x;           // x is better than the current c2, store it
			} else {              // here when we have/had c1 < c2 already and x > c2
				return true;      // the increasing subsequence of 3 elements exists
			}
		}
		return false;
	}
};
// @lc code=end

int main() {
	Solution solution;
	vector<int> nums = {1, 2, 3, 4, 5};
	assert(solution.increasingTriplet(nums));
	nums = {5, 4, 3, 2, 1};
	assert(!solution.increasingTriplet(nums));
	nums = {1, 2, 2, 4, 5};
	assert(solution.increasingTriplet(nums));
	nums = {1, 2, 2, 4, 4};
	assert(solution.increasingTriplet(nums));
	nums = {1, 2, 1, 4};
	assert(solution.increasingTriplet(nums));
	
	Complete();
}