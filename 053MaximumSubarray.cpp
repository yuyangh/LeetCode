#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (43.54%)
 * Likes:    4298
 * Dislikes: 145
 * Total Accepted:    533.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * Example:
 *
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * [-2,-3,-4] -2
 * [1,2,4,6,-10,6,-9,6,-11,1] 13
 * [1,2,4,6] 13
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 *
 */

/*
 * Time complexity: O(n)
 * use dp to choose nums[i] or nums[i]+ previous sum
 */
class Solution {
public:
	int maxSubArray(vector<int> &nums) {
		if (nums.empty()) {
			return 0;
		}
		vector<int> buffer;
		buffer.reserve(nums.size());
		
		// set the initial valuew
		int maxSum = max(INT_MIN, nums[0]);
		buffer.emplace_back(maxSum);
		
		// memorize the max value up until here
		for (int i = 1; i < nums.size(); i++) {
			buffer.emplace_back(max(nums[i], nums[i] + buffer[i - 1]));
			maxSum = max(maxSum, buffer.back());
		}
		return maxSum;
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}