#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (47.84%)
 * Likes:    777
 * Dislikes: 46
 * Total Accepted:    204.8K
 * Total Submissions: 427.7K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 *
 * Example:
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 */
class Solution {
public:
	vector<vector<int>> result;
	
	vector<vector<int>> combine(int n, int k) {
		vector<int> buffer;
		buffer.reserve(k);
		combine(buffer, 1, n - k + 1, k);
		return result;
	}
	
	/**
	 * produce the combination
	 * @param nums
	 * @param lower smallest number that can be added in
	 * @param upper largest number that can be added in
	 * @param remain numbers left to add
	 */
	void combine(vector<int> &nums, int lower, int upper, int remain) {
		// base case
		if (remain == 0) {
			result.emplace_back(nums);
			return;
		}
		for (int i = lower; i <= upper; i++) {
			nums.emplace_back(i);
			// combine with numbers larger
			combine(nums, i + 1, upper + 1, remain - 1);
			nums.pop_back();
		}
	}
};

