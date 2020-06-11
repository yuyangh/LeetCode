//
// Created by Yuyang Huang on 6/10/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 *
 * https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
 *
 * algorithms
 * Easy (70.21%)
 * Likes:    603
 * Dislikes: 1113
 * Total Accepted:    152.5K
 * Total Submissions: 213.7K
 * Testcase Example:  '[0,1,0]'
 *
 * Let's call an array A a mountain if the following properties hold:
 *
 *
 * A.length >= 3
 * There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] <
 * A[i] > A[i+1] > ... > A[A.length - 1]
 *
 *
 * Given an array that is definitely a mountain, return any i such that A[0] <
 * A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
 *
 * Example 1:
 *
 *
 * Input: [0,1,0]
 * Output: 1
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [0,2,1,0]
 * Output: 1
 *
 *
 * Note:
 *
 *
 * 3 <= A.length <= 10000
 * 0 <= A[i] <= 10^6
 * A is a mountain, as defined above.
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(logn)
 * binary search, since the question ensure one and only one mountain
 */
class Solution {
public:
	int peakIndexInMountainArray(vector<int> &nums) {
		int left = 0, right = nums.size(), mid;
		while (left < right) {
			mid = (left + right) / 2;
			// left will move towards the peak
			if (nums[mid] < nums[mid + 1]) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		return left;
	}
};
// @lc code=end

int main() {
	Solution solution;
	vector<int> nums;
	nums = {1, 2, 3, 2, 1};
	assert(solution.peakIndexInMountainArray(nums) == 2);
	nums = {0, 2, 1, 0};
	assert(solution.peakIndexInMountainArray(nums) == 1);
	nums = {1, 2, 3, 2, 1, 0, -1};
	assert(solution.peakIndexInMountainArray(nums) == 2);
	nums = {-1, 0, 1, 2, 3, 2};
	assert(solution.peakIndexInMountainArray(nums) == 4);
	
	Complete();
}
