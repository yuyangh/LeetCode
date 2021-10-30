//
// Created by Yuyang Huang on 11/6/21.
//

/*
 * 260. Single Number III
Medium

Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.



Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]


Constraints:

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.
 */

#include "LeetCodeLib.h"

class Solution {
public:
	vector<int> singleNumber(vector<int> &nums) {
		int n = nums.size();
		vector<int> res{};
		int bucket1{}, bucket2{};
		long long int xr{};
		
		//Calculate xor of every number so that xr will have (x^y)
		for (int i{}; i < n; ++i)
			xr = xr ^ nums[i];
		
		// Compute rightmost set bit of xr, gives us the ith bit we need as a mask
		int mask = xr & (-xr);
		
		// Fill our buckets according to our intuition mentioned in above steps
		for (int i{}; i < n; ++i) {
			
			if (mask & nums[i])
				bucket1 ^= nums[i];
			
			else
				bucket2 ^= nums[i];
		}
		
		// bucket1 and bucket2 will contain x and y
		res.push_back(bucket1);
		res.push_back(bucket2);
		
		return res;
	}
};