#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (53.04%)
 * Likes:    1947
 * Dislikes: 50
 * Total Accepted:    371.3K
 * Total Submissions: 699.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 *
 */
class Solution {
public:
	/*
	 * Time complexity: O(2^n)
	 */
	vector<vector<int>> subsets(vector<int> &nums) {
		if (nums.empty()) {
			result.emplace_back(vector<int>());
			return result;
		}
		
		// find combination for various length
		for (int i = 0; i <= nums.size(); i++) {
			vector<int> comb;
			combination(comb, nums, 0, nums.size() - i, i);
		}
		return result;
	}
	
	void combination(vector<int> &comb, vector<int> &nums, int startPos, int endPos, int remain) {
		if (remain == 0) {
			result.emplace_back(comb);
			return;
		}
		// backtracking
		for (int i = startPos; i <= endPos; i++) {
			comb.emplace_back(nums[i]);
			combination(comb, nums, i + 1, endPos + 1, remain - 1);
			comb.pop_back();
		}
	}

private:
	vector<vector<int>> result;
};

