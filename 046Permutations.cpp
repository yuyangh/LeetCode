#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (55.40%)
 * Likes:    2038
 * Dislikes: 59
 * Total Accepted:    384.7K
 * Total Submissions: 694.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 *
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 *
 *
 */
class Solution {
public:
	vector<vector<int>> result;
	
	vector<vector<int>> permute(vector<int> &nums) {
		if (nums.empty()) {
			return result;
		}
		permute(nums, 0);
		return result;
	}
	
	// for permutations, think about backtracking
	void permute(vector<int> &nums, int pos) {
		if (nums.size() == pos + 1) {
			result.emplace_back(nums);
			return;
		}
		// swap and re-swap back
		for (int i = 0; i < nums.size() - pos; i++) {
			swap(nums[pos], nums[pos + i]);
			permute(nums, pos + 1);
			swap(nums[pos], nums[pos + i]);
		}
	}
};
