//
// Created by Yuyang Huang on 6/25/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (51.42%)
 * Likes:    4540
 * Dislikes: 558
 * Total Accepted:    330.6K
 * Total Submissions: 604.7K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * Given an array nums containing n + 1 integers where each integer is between
 * 1 and n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 *
 * Example 1:
 *
 *
 * Input: [1,3,4,2,2]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: [3,1,3,4,2]
 * Output: 3
 *
 * Note:
 *
 *
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n^2).
 * There is only one duplicate number in the array, but it could be repeated
 * more than once.
 *
 *
 */

// @lc code=start

class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * space complexity: O(1)
	 * The idea is to reduce the problem to Linked List Cycle II
	 * The cycle appears because nums contains duplicates. The duplicate node is a cycle entrance.
	 */
	int findDuplicate(vector<int> nums) {
		// Find the intersection point of the two runners.
		int slow = nums[0];
		int fast = nums[0];
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);
		
		// Find the "entrance" to the cycle.
		slow = nums[0];
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}
		
		return fast;
	}
};
// @lc code=end

