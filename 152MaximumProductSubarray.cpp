//
// Created by Yuyang Huang on 6/11/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (30.25%)
 * Likes:    3876
 * Dislikes: 150
 * Total Accepted:    324.5K
 * Total Submissions: 1M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer arrayÂ nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 *
 * Example 1:
 *
 *
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation:Â [2,3] has the largest product 6.
 *
 *
 * Example 2:
 *
 *
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation:Â The result cannot be 2, because [-2,-1] is not a subarray.
 *
 */

// @lc code=start
/*
 * Time complexity:O(n)
 * dynamic programming
 */
class Solution {
public:
	int maxProduct(vector<int> &nums) {
		int result = nums[0];
		int minimum = result, maximum = result;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] < 0) {
				swap(minimum, maximum);
			}
			minimum = min(nums[i], minimum * nums[i]);
			maximum = max(nums[i], maximum * nums[i]);
			
			result = max(result, maximum);
		}
		return result;
	}
};
// @lc code=end

int main() {
	Solution solution;
	vector<int> nums = {2, 3, -2, 4};
	assert(solution.maxProduct(nums) == 6);
	nums = {-2, 0, -1};
	assert(solution.maxProduct(nums) == 0);
	
	Complete();
}