//
// Created by Yuyang Huang on 7/9/21.
//

/*
 * 1004. Max Consecutive Ones III
 * Medium
 *
 * Given a binary array nums and an integer k,
 * return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
 *
 * Example 1:
 * Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * Output: 6
 * Explanation: [1,1,1,0,0,1,1,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 *
 * Example 2:
 * Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
 * Output: 10
 * Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 *
 * Constraints:
 * 1 <= nums.length <= 105
 * nums[i] is either 0 or 1.
 * 0 <= k <= nums.length
 */

#include "LeetCodeLib.h"

/*
 * Time Complexity: O(n)
 * decrease buffer size for obstacles
 * entirely move right when buffer is not enough
 */
class Solution {
public:
	int longestOnes(vector<int> &nums, int k) {
		int start = 0, end = 0, buffer = k;
		for (; end < nums.size(); ++end) {
			if (nums[end] == 0) { buffer--; }
			if (buffer < 0) {
				if (nums[start] == 0) { buffer++; }
				start++;
			}
		}
		return end - start;
	}
};

int main() {
	Solution solution;
	vector<int> nums;
	int k;
	
	nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, k = 2;
	PrintSingleResult(solution.longestOnes(nums, k));
	
	nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, k = 3;
	PrintSingleResult(solution.longestOnes(nums, k));
}