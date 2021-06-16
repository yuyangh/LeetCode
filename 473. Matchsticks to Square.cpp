//
// Created by Yuyang Huang on 6/15/21.
//

/*
 * 473. Matchsticks to Square
 * Medium
 *
 * You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick.
 * You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up,
 * and each matchstick must be used exactly one time.
 *
 * Return true if you can make this square and false otherwise.
 *
 * Example 1:
 * Input: matchsticks = [1,1,2,2,2]
 * Output: true
 * Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
 *
 * Example 2:
 * Input: matchsticks = [3,3,3,3,4]
 * Output: false
 * Explanation: You cannot find a way to form a square with all the matchsticks.
 *
 * Constraints:
 * 1 <= matchsticks.length <= 15
 * 0 <= matchsticks[i] <= 109
 */

#include "LeetCodeLib.h"

class Solution {
public:
	bool makesquare(vector<int>& matchsticks) {
		return canPartitionKSubsets(matchsticks,4);
	}
	
	bool canPartitionKSubsets(vector<int> &nums, int k) {
		if (k == 1) {
			return true;
		}
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % k != 0) {
			return false;
		}
		sort(nums.begin(), nums.end(), std::greater<int>());
		vector<bool> visited(nums.size(), false);
		return canPartitionKSubsetsHelper(nums, visited, 0, 0, 0, k, sum / k);
		
	}
	
	bool canPartitionKSubsetsHelper(vector<int> &nums, vector<bool> &visited, int startIdx, int currSum, int currNum,
	                                int kRemain,
	                                int target) {
		// as all other sets are satisfied, then the last one must satisfied
		if (kRemain == 1) {
			return true;
		}
		
		// check there are numbers within the set that sums to target
		if (currSum == target && currNum > 0) {
			return canPartitionKSubsetsHelper(nums, visited, 0, 0, 0, kRemain - 1, target);
		}
		for (int i = startIdx; i < nums.size(); ++i) {
			// check the number is able to visit and within the sum
			if (!visited[i] && currSum + nums[i]<=target) {
				visited[i] = true;
				if (canPartitionKSubsetsHelper(nums, visited, i + 1, currSum + nums[i], currNum + 1, kRemain, target)) {
					return true;
				}
				visited[i] = false;
			}
		}
		return false;
	}
};