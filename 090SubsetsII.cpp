#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (42.53%)
 * Likes:    920
 * Dislikes: 49
 * Total Accepted:    209K
 * Total Submissions: 488.3K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 *
 *
 */
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		
		vector<int> single;
		// create subset in ascending size order
		for (int element_count = 0; element_count <= nums.size(); ++element_count) {
			recursion(nums, single, 0, element_count);
		}
		return result_;
	}
	
	vector<vector<int> > subsetsWithDupIterative(vector<int> &nums) {
		vector<vector<int> > totalset = {{}};
		sort(nums.begin(), nums.end());
		
		// append elements one by one
		for (int i = 0; i < nums.size();) {
			int count = 0; // num of elements are the same
			while (count + i < nums.size() && nums[count + i] == nums[i]) {
				count++;
			}
			
			int previousN = totalset.size();
			for (int k = 0; k < previousN; k++) {
				// copy from previous level
				vector<int> instance = totalset[k];
				
				// append elements to the copied one
				for (int j = 0; j < count; j++) {
					instance.push_back(nums[i]);
					totalset.push_back(instance);
				}
			}
			i += count;
		}
		return totalset;
	}

private:
	vector<vector<int>> result_;
	
	void recursion(vector<int> &nums, vector<int> &single, int index, int remain) {
		if (remain == 0) {
			result_.emplace_back(single);
			return;
		}
		for (int i = index; i < nums.size(); ++i) {
			// go over duplicate numbers
			if (i > index && nums[i] == nums[i - 1]) {
				continue;
			}
			// backtracking
			single.emplace_back(nums[i]);
			recursion(nums, single, i + 1, remain - 1);
			single.pop_back();
		}
	}
};

int main() {
	vector<int> arr = {1, 2, 2};
	Solution solution;
	auto result = solution.subsetsWithDup(arr);
	PrintVectorVector(result);
	return 0;
}

