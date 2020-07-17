//
// Created by Yuyang Huang on 7/16/20.
//

#include "LeetCodeLib.h"

/*
 * Given an array nums of n integers where n > 1,
 * return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 *
 * Example:
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 *
 * Constraint: It's guaranteed that the product of the elements of any prefix or
 * suffix of the array (including the whole array) fits in a 32 bit integer.
 *
 * Note: Please solve it without division and in O(n).
 * Follow up:
 * Could you solve it with constant space complexity?
 * (The output array does not count as extra space for the purpose of space complexity analysis.)
 */

class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * do the left accumulate product and right accumulate product
	 * the number is the left prod * right prod
	 */
	vector<int> productExceptSelf(vector<int> &nums) {
		// base case
		if (nums.size() <= 1) {
			return nums;
		}
		
		vector<int> leftProd(nums.size(), 1), rightProd(nums.size(), 1), result(nums.size(), 1);
		
		// accumulate for the left
		for (int i = 1; i < nums.size(); ++i) {
			leftProd[i] = leftProd[i - 1] * nums[i - 1];
		}
		for (int i = nums.size() - 2; i >= 0; --i) {
			rightProd[i] = rightProd[i + 1] * nums[i + 1];
		}
		
		for (int i = 0; i < nums.size(); ++i) {
			result[i] = leftProd[i] * rightProd[i];
		}
		
		return result;
	}
};

int main() {
	Solution solution;
	vector<int> nums;
	
	nums = {1, 2, 3, 4};
	PrintVector(solution.productExceptSelf(nums));
	nums = {1, 2};
	PrintVector(solution.productExceptSelf(nums));
	nums = {1};
	PrintVector(solution.productExceptSelf(nums));
	nums = {0};
	PrintVector(solution.productExceptSelf(nums));
	
	Complete();
}