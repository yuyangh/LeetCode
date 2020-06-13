//
// Created by Yuyang Huang on 6/13/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 *
 * https://leetcode.com/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (35.55%)
 * Likes:    1141
 * Dislikes: 55
 * Total Accepted:    76.9K
 * Total Submissions: 208.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct positive integers, find the largest subset such that
 * every pair (Si, Sj) of elements in this subset satisfies:
 *
 * Si % Sj = 0 or Sj % Si = 0.
 *
 * If there are multiple solutions, return any subset is fine.
 *
 * Example 1:
 *
 *
 *
 * Input: [1,2,3]
 * Output: [1,2] (of course, [1,3] will also be ok)
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [1,2,4,8]
 * Output: [1,2,4,8]
 *
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(n*n)
 * sort and find parent with longest path
 */
class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int> &nums) {
		if (nums.empty()) {
			return {};
		}
		
		vector<int> parents;
		vector<int> numParents;
		vector<int> result;
		int longestEndIdx = 0;
		
		// base case
		sort(nums.begin(), nums.end());
		parents.emplace_back(-1);
		numParents.emplace_back(1);
		parents.reserve(nums.size());
		numParents.reserve(nums.size());
		
		for (int cur = 1; cur < nums.size(); ++cur) {
			int currNum = nums[cur];
			int parent = -1, numParent = 1;
			// find parent with longest path
			for (int prev = cur - 1; prev >= 0; --prev) {
				if (currNum % nums[prev] == 0 && numParent < numParents[prev] + 1) {
					parent = prev;
					numParent = numParents[parent] + 1;
				}
			}
			
			parents.emplace_back(parent);
			numParents.emplace_back(numParent);
			
			if (numParent > numParents[longestEndIdx]) {
				longestEndIdx = cur;
			}
		}
		
		// retrospect to get the path
		int idx = longestEndIdx;
		while (idx != -1) {
			result.emplace_back(nums[idx]);
			idx = parents[idx];
		}
		reverse(result.begin(), result.end());
		return result;
	}
};
// @lc code=end

int main() {
	Solution solution;
	vector<int> nums;
	// nums = {1, 2, 3};
	// PrintVector(solution.largestDivisibleSubset(nums));
	// nums = {1, 2, 4, 8};
	// PrintVector(solution.largestDivisibleSubset(nums));
	nums = {4, 8, 10, 240};
	PrintVector(solution.largestDivisibleSubset(nums));
	
	Complete();
}
