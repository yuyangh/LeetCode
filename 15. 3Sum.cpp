#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.98%)
 * Likes:    3780
 * Dislikes: 425
 * Total Accepted:    552.8K
 * Total Submissions: 2.3M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 *
 * Note:
 * The solution set must not contain duplicate triplets.
 *
 * Example:
 * Given array nums = [-1, 0, 1, 2, -1, -4], input as: -1, 0, 1, 2, -1, -4
 *
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 */


class Solution {
public:
	/*
	 * Time complexity: O(n*n)
	 * two pointers fow the lowest level
	 */
	vector<vector<int>> threeSum(vector<int> &nums) {
		vector<vector<int>> result;
		
		sort(nums.begin(), nums.end());
		
		// there must be one non-positive num in the triplet
		for (int firstIdx = 0; firstIdx < nums.size() && nums[firstIdx] <= 0; ++firstIdx) {
			// avoid duplication
			if (firstIdx == 0 || nums[firstIdx] != nums[firstIdx - 1]) {
				twoSum(nums, firstIdx, result);
			}
		}
		return result;
	}

private:
	/*
	 * Time complexity: O(n)
	 * find remaining 2 integers that can sum to zero
	 */
	void twoSum(vector<int> &nums, int firstIdx, vector<vector<int>> &result) {
		int secondIdx = firstIdx + 1, thirdIdx = nums.size() - 1;
		
		while (secondIdx < thirdIdx) {
			int sum = nums[firstIdx] + nums[secondIdx] + nums[thirdIdx];
			if (sum > 0 || (thirdIdx < nums.size() - 1 && nums[thirdIdx] == nums[thirdIdx + 1])) {
				thirdIdx--;
			} else if (sum < 0 ||(secondIdx > firstIdx + 1 && nums[secondIdx] == nums[secondIdx - 1]) ) {
				secondIdx++;
			} else {
				result.emplace_back(vector<int>{nums[firstIdx], nums[secondIdx], nums[thirdIdx]});
				secondIdx++;
				thirdIdx--;
			}
		}
	}
};

int main(int argc, char **argv) {
	Solution solution;
	vector<int> nums;
	
	nums = {-1, 0, 1, 2, -1, -4};
	PrintVectorVector(solution.threeSum(nums));
	
	nums = {1, -1, -1, 0};
	PrintVectorVector(solution.threeSum(nums));
	
	Complete();
	
}