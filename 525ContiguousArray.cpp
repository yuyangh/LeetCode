//
// Created by Yuyang Huang on 5/26/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 *
 * https://leetcode.com/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (43.87%)
 * Likes:    1967
 * Dislikes: 111
 * Total Accepted:    145.6K
 * Total Submissions: 348.1K
 * Testcase Example:  '[0,1]'
 *
 * Given a binary array, find the maximum length of a contiguous subarray with
 * equal number of 0 and 1.
 *
 *
 * Example 1:
 *
 * Input: [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with equal number of
 * 0 and 1.
 *
 *
 *
 * Example 2:
 *
 * Input: [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
 * number of 0 and 1.
 *
 *
 *
 * Note:
 * The length of the given binary array will not exceed 50,000.
 *
 */

// @lc code=start

/*
 * Time complexity: O(n)
 *
 *
 * In this approach, we make use of a countcount variable,
 * which is used to store the relative number of ones and zeros encountered so far while traversing the array.
 * The count variable is incremented by one for every \text{1}1 encountered
 * and the same is decremented by one for every \text{0}0 encountered.
 *
 * We start traversing the array from the beginning.
 * If at any moment, the count becomes zero,
 * it implies that we've encountered equal number of zeros and ones from the beginning till the current index of the array(i).
 * Not only this, another point to be noted is that if we encounter the same count twice
 * while traversing the array, it means that the number of zeros
 * and ones are equal between the indices corresponding to the equal count values.
 */
class Solution {
public:
	int findMaxLength(vector<int> &nums) {
		unordered_map<int, int> sumPosMap;
		sumPosMap[0] = -1;
		int sum = 0, maxLength = 0;
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i] ? 1 : -1;
			// if the value already exist, then emplace will not change
			sumPosMap.emplace(sum, i);
			maxLength = max(maxLength, i - sumPosMap[sum]);
		}
		return maxLength;
	}
};
// @lc code=end

int main() {
	Solution solution;
	vector<int> arr = {0, 1, 0};
	assert(solution.findMaxLength(arr) == 2);
	arr = {0, 1};
	assert(solution.findMaxLength(arr) == 2);
	Complete();
}