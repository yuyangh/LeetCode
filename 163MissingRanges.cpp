//
// Created by Yuyang Huang on 5/27/20.
//

#include "LeetCodeLib.h"

/*
 * Given a sorted integer array nums,
 * where the range of elements are in the inclusive range [lower, upper],
 * return its missing ranges.
 * Example:
 * Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
 * Output: ["2", "4->49", "51->74", "76->99"]
 */

/*
 * Time complexity: O(n)
 */
class Solution {
public:
	vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
		if (nums.empty()) {
			return {formRange(lower, upper)};
		}
		
		vector<string> result;
		
		// lower to nums's lowest
		if (lower < nums[0]) {
			result.emplace_back(formRange(lower, nums[0] - 1));
		}
		
		// ranges in nums
		for (int i = 1; i < nums.size(); ++i) {
			// handle two consecutive INT_MAX case
			if (nums[i] != nums[i - 1] && nums[i] > nums[i - 1] + 1) {
				result.emplace_back(formRange(nums[i - 1] + 1, nums[i] - 1));
			}
		}
		
		// back to upper
		if (upper > nums.back()) {
			result.emplace_back(formRange(nums.back() + 1, upper));
		}
		return result;
	}

private:
	string formRange(int low, int high) {
		return low == high ? to_string(low) : (to_string(low) + "->" + to_string(high));
	}
};

int main() {
	vector<int> arr = {0, 1, 3, 50, 75};
	Solution solution;
	PrintVector(solution.findMissingRanges(arr, 0, 99));
	Complete();
}