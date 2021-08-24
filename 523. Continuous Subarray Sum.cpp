//
// Created by Yuyang Huang on 8/24/21.
//

/*
 * 523. Continuous Subarray Sum
 * Medium
 *
 * Given an integer array nums and an integer k,
 * return true if nums has a continuous subarray of size
 * at least two whose elements sum up to a multiple of k, or false otherwise.
 *
 * An integer x is a multiple of k if there exists an integer n such that x = n * k.
 * 0 is always a multiple of k.
 *
 * Example 1:
 * Input: nums = [23,2,4,6,7], k = 6
 * Output: true
 * Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
 *
 * Example 2:
 * Input: nums = [23,2,6,4,7], k = 6
 * Output: true
 * Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
 * 42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
 *
 * Example 3:
 * Input: nums = [23,2,6,4,7], k = 13
 * Output: false
 *
 * Constraints:
 * 1 <= nums.length <= 105
 * 0 <= nums[i] <= 109
 * 0 <= sum(nums[i]) <= 231 - 1
 * 1 <= k <= 231 - 1
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * use modulo to get the remainder
	 */
	bool checkSubarraySum(vector<int> &nums, int k) {
		unordered_map<int, int> modIndexMap;
		// base case for 0
		modIndexMap[0] = -1;
		long long sum = 0;
		
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			int mod = sum % k;
			auto it = modIndexMap.find(mod);
			if (it != modIndexMap.end()) {
				if (i - it->second >= 2) {
					return true;
				}
			} else {
				modIndexMap[mod] = i;
			}
		}
		return false;
	}
};