#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (40.65%)
 * Likes:    1038
 * Dislikes: 44
 * Total Accepted:    250.3K
 * Total Submissions: 611.6K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 *
 * Example:
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 *
 *
 */
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int> &nums) {
		if (nums.empty()) {
			return result;
		}
		sort(nums.begin(), nums.end(), std::less<int>());
		vector<int> single;
		recursion(nums,0);
		// permute(nums, 0);
		return result;
	}

private:
	vector<vector<int>> result;
	
	// this one cannot avoid duplication, needs improve and thought
	void permute(vector<int> &nums, int index) {
		if (index == nums.size() - 1) {
			result.emplace_back(nums);
			return;
		}
		for (int i = index; i < nums.size(); ++i) {
			if (i != index && nums[i] == nums[index]) {
				continue;
			}
			swap(nums[i], nums[index]);
			permute(nums, index + 1);
			swap(nums[i], nums[index]);
			
		}
	}
	
	// swap different location to avoid duplication
	void recursion(vector<int> nums, int index) {
		if (index == nums.size() - 1) {
			result.emplace_back(nums);
			return;
		}
		for (int i = index; i < nums.size(); ++i) {
			if (i != index && nums[i] == nums[index]) {
				continue;
			}
			swap(nums[i], nums[index]);
			recursion(nums, index + 1);
		}
	}
};

int main() {
	vector<int> arr = {2,1, 2, 2};
	Solution solution;
	auto result = solution.permuteUnique(arr);
	PrintVectorVector(result);
	return 0;
}
