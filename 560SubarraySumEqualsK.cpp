//
// Created by Yuyang Huang on 10/26/19.
//

/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.03%)
 * Likes:    2641
 * Dislikes: 72
 * Total Accepted:    152.3K
 * Total Submissions: 353.9K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 *
 * Example 1:
 *
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 *
 *
 *
 * Note:
 *
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 *
 *
 *
 */

// @lc code=start

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * time complexit: O(n), space complexity:O(n)
	 * prefix sum technique, use hashmap to find target value
	 */
	int subarraySum(vector<int> &nums, int k) {
		// initialize
		unordered_map<int, long long> record;
		record[0] = 1;
		
		int result = 0;
		long long sum = 0;
		
		// do prefix sum
		for (auto &num : nums) {
			sum += num;
			// handle 1 0 0 case, which has many sub-arrays
			result += record[sum - k];
			// add a new entry, which record how many times that sum exist
			record[sum]++;
		}
		return result;
	}
};
// @lc code=end

