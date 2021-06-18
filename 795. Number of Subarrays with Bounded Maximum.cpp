//
// Created by Yuyang Huang on 6/17/21.
//

/*
 * 795. Number of Subarrays with Bounded Maximum
 *
 * Medium
 *
 * We are given an array nums of positive integers, and two positive integers left and right (left <= right).
 *
 * Return the number of (contiguous, non-empty) subarrays
 * such that the value of the maximum array element in that subarray is at least left and at most right.
 *
 * Example:
 * Input:
 * nums = [2, 1, 4, 3]
 * left = 2
 * right = 3
 * Output: 3
 *
 * Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
 *
 * Note:
 * left, right, and nums[i] will be an integer in the range [0, 109].
 * The length of nums will be in the range of [1, 50000].
 */

#include "LeetCodeLib.h"

/*
 * Time Complexity: O(n)
 * Space Complexity: O(n), can be optimized to O(1) with state compression
 * use dp to memorize number of sub-arrays ending at index i
 */
class Solution {
public:
	int numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
		vector<int> numArrayEndAtIdx(nums.size(),0);
		int prevInvalidSubArrayIdx=-1;
		for (int idx = 0; idx < nums.size(); ++idx) {
			if(nums[idx]<left && idx>0){
				numArrayEndAtIdx[idx]=numArrayEndAtIdx[idx-1];
			}
			if(right<nums[idx]){
				numArrayEndAtIdx[idx]=0;
				prevInvalidSubArrayIdx=idx;
			}
			if(left<=nums[idx] && nums[idx]<=right){
				numArrayEndAtIdx[idx]=idx-prevInvalidSubArrayIdx;
			}
		}
		return accumulate(numArrayEndAtIdx.begin(),numArrayEndAtIdx.end(),0);
	}
};

int main(){
	Solution solution;
	
	vector<int >nums = {2, 1, 4, 3};
	int left = 2, right = 3;
	
	PrintSingleResult(solution.numSubarrayBoundedMax(nums,left,right));
	
	Complete();
}