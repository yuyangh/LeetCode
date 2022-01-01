//
// Created by Yuyang Huang on 1/2/22.
//

/*
 * 1712. Ways to Split Array Into Three Subarrays
 * Medium
 *
 * A split of an integer array is good if:
 * The array is split into three non-empty contiguous subarrays
 * - named left, mid, right respectively from left to right.
 * The sum of the elements in left is less than or equal to the sum of the elements in mid,
 * and the sum of the elements in mid is less than or equal to the sum of the elements in right.
 * Given nums, an array of non-negative integers, return the number of good ways to split nums.
 * As the number may be too large, return it modulo 109 + 7.
 *
 * Example 1:
 * Input: nums = [1,1,1]
 * Output: 1
 * Explanation: The only good way to split nums is [1] [1] [1].
 *
 * Example 2:
 * Input: nums = [1,2,2,2,5,0]
 * Output: 3
 * Explanation: There are three good ways of splitting nums:
 * [1] [2] [2,2,5,0]
 * [1] [2,2] [2,5,0]
 * [1,2] [2,2] [5,0]
 *
 * Example 3:
 * Input: nums = [3,2,1]
 * Output: 0
 * Explanation: There is no good way to split nums.
 *
 * Constraints:
 * 3 <= nums.length <= 105
 * 0 <= nums[i] <= 104
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * i is the boundary for the left array
	 * low and high are boundaries for the mid array, high is not inclusive (means high is the begin of right)
	 * prefix[low]-prefix[i] >= prefix[i]
	 * prefix.back() - prefix[high] >= prefix[high] - prefix[i]
	 * for a point i, we can build high-low subarrays satisfying the problem requirements.
	 * Final thing is to realize that low and high will only move forward, which result in a linear-time solution.
	 * another approach is binary search
	 */
	int waysToSplit(vector<int> &nums) {
		vector<int> prefix(nums.size(), 0);
		
		partial_sum(nums.begin(), nums.end(), prefix.begin());
		int result = 0;
		
		for (int i = 0, low = 1, high = 1; i < nums.size() - 2; i++) {
			low=max(i+1,low);
			while (low < nums.size() - 1 &&
			       prefix[i] > prefix[low] - prefix[i]) {
				++low;
			}
			high=max(low,high);
			while (high < nums.size() - 1 &&
			       prefix[high] - prefix[i] <= prefix.back() - prefix[high]) {
				++high;
			}
			result = (result + high - low) % 1000000007;
		}
		
		return result;
	}
};

int main() {
	Solution solution;
	vector<int> nums;
	nums={1,1,1};
	PrintSingleResult(solution.waysToSplit(nums));
	nums = {1, 2, 2, 2, 5, 0};
	PrintSingleResult(solution.waysToSplit(nums));
	nums = {3, 2, 1};
	PrintSingleResult(solution.waysToSplit(nums));
}