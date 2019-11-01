//
// Created by Yuyang Huang on 10/31/19.
//

/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (43.77%)
 * Likes:    1310
 * Dislikes: 187
 * Total Accepted:    335.8K
 * Total Submissions: 767K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 *
 * Example 1:
 *
 *
 * Input: [3,4,5,1,2]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 *
 *
 */

// @lc code=start

#include "LeetCodeLib.h"

class Solution {
public:
	int findMin(vector<int>& nums) {
		if(nums.empty()){
			return 0;
		}
		if(nums.size()==1){
			return nums.back();
		}
		
		int start=0,end=nums.size()-1;
		
		while (start<=end) {
			// if the first member is less than the last member,
			// there's no rotation in the array.
			// So we could directly return the first element in this subarray.
			if (nums[start]<=nums[end])
				return nums[start];
			
			int mid = (start+end)/2;
			
			// If value of the element in the middle is larger than the end element,
			// we know the rotation is at the second half of this array.
			// Else, it is in the first half in the array.
			if (nums[mid]>nums[end]) {
				start = mid+1;
			} else if(nums[mid]<=nums[end]){
				end = mid;
			}
		}
		
		return nums[start];
	}
};
// @lc code=end


