//
// Created by Yuyang Huang on 6/15/21.
//

/*
 * 698. Partition to K Equal Sum Subsets
 * Medium
 *
 * Given an integer array nums and an integer k,
 * return true if it is possible to divide this array into k non-empty subsets whose sums are all equal
 *
 * Example 1:
 * Input: nums = [4,3,2,3,5,2,1], k = 4
 * Output: true
 * Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 *
 * Example 2:
 * Input: nums = [1,2,3,4], k = 3
 * Output: false
 *
 * Constraints:
 * 1 <= k <= nums.length <= 16
 * 1 <= nums[i] <= 104
 * The frequency of each element is in the range [1, 4].
 */

#include "LeetCodeLib.h"

/*
 * Time Complexity:
 * Use backtracking to test whether each number can satisfy a set
 */
class Solution {
public:
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


int main(){
	Solution solution;
	vector<int> nums;
	int k;
	
	nums = {4,3,2,3,5,2,1}, k = 4;
	PrintSingleResult(solution.canPartitionKSubsets(nums,k));
	
	nums={1,2,3,4}, k = 3;
	PrintSingleResult(solution.canPartitionKSubsets(nums,k));
	
	Complete();
}











