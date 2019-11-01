//
// Created by Yuyang Huang on 10/31/19.
//

/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (39.90%)
 * Likes:    580
 * Dislikes: 162
 * Total Accepted:    148.1K
 * Total Submissions: 371K
 * Testcase Example:  '[1,3,5]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 *
 * Find the minimum element.
 *
 * The array may contain duplicates.
 *
 * Example 1:
 *
 *
 * Input: [1,3,5]
 * Output: 1
 *
 * Example 2:
 *
 *
 * Input: [2,2,2,0,1]
 * Output: 0
 *
 * Note:
 *
 *
 * This is a follow up problem to Find Minimum in Rotated Sorted Array.
 * Would allow duplicates affect the run-time complexity? How and why?
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
		int start=0,end=nums.size()-1;
		
		while (start<=end) {
			// if the first member is less than the last member,
			// there's no rotation in the array.
			// So we could directly return the first element in this subarray.
			if (nums[start]<nums[end])
				return nums[start];
			
			int mid = (start+end)/2;
			
			// If value of the element in the middle is larger than the end element,
			// we know the rotation is at the second half of this array.
			// Else, it is in the first half in the array.
			if (nums[mid]>nums[end]) {
				start = mid+1;
			} else if(nums[mid]<nums[end]){
				end = mid;
			}else{
				end--;
			}
		}
		
		return nums[start];
	}
};
// @lc code=end

