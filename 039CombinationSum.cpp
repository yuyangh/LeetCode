#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (48.73%)
 * Likes:    2055
 * Dislikes: 59
 * Total Accepted:    349.9K
 * Total Submissions: 716.2K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 * Example 1:
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 * Example 2:
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 */
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		if (candidates.empty()) {
			return result;
		}
		// sort in ascending orders
		sort(candidates.begin(), candidates.end());
		vector<int> single;
		combine(candidates, single, 0, target);
		return result;
	}

private:
	vector<vector<int>> result;
	
	/*
	 * because numbers are distinct and all positive
	 * backtracking to add number, recursion(decrease goal), pop
	 */
	void combine(vector<int> &candidates, vector<int> &single, int start, int goal) {
		// base case
		if (goal == 0) {
			result.emplace_back(single);
			return;
		}
		// choose from this element and beyond to avoid duplication
		for (int i = start; i < candidates.size(); i++) {
			int dist = goal - candidates[i];
			if (dist >= 0) {
				// back tracking
				single.emplace_back(candidates[i]);
				combine(candidates, single, i, dist);
				single.pop_back();
			} else {
				// elements remaining will be even larger,
				// so don't need to consider
				return;
			}
		}
	}
};

int main() {
	vector<int> candidates = {2, 3, 6, 7};
	int target = 7;
	Solution solution;
	auto result = solution.combinationSum(candidates, target);
	for (const auto &item : result) {
		for (const auto &num : item) {
			cout << num << " ";
		}
		cout << endl;
	}
}

