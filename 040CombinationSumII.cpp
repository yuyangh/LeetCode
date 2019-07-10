#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (41.77%)
 * Likes:    866
 * Dislikes: 47
 * Total Accepted:    227.8K
 * Total Submissions: 541.3K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 * Example 1:
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 *
 * Example 2:
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 */
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		// empty combination is the answer for target = 0
		if (candidates.empty() && target != 0) {
			return result;
		}
		sort(candidates.begin(), candidates.end());
		vector<int> single;
		combine(candidates, single, 0, target);
		return result;
	}

private:
	vector<vector<int>> result;
	
	// backtracking by decrease distance and emplace number
	// if successful, jump over all identical number (because all numbers are positive)
	bool combine(vector<int> &candidates, vector<int> &single, int index, int distance) {
		// base case
		if (distance < 0) {
			return false;
		}
		if (distance == 0) {
			result.emplace_back(single);
			return true;
		}
		// handle out of bound
		if (distance > 0 && index >= candidates.size()) {
			return false;
		}
		bool trySuccessful = false;
		// go through each numbers at and after index
		for (int i = index; i < candidates.size(); ++i) {
			// backtracking
			single.emplace_back(candidates[i]);
			bool complete = combine(candidates, single, i + 1, distance - candidates[i]);
			trySuccessful |= complete;
			single.pop_back();
			// because all positiv numbers,
			// if the number is successful, same value would also be successful
			// so jump over same values, avoid duplicates
			if (complete) {
				while (i + 1 < candidates.size()) {
					if (candidates[i] == candidates[i + 1]) {
						++i;
					} else {
						break;
					}
				}
			}
		}
		return trySuccessful;
	}
};


int main() {
	vector<int> candidates = {1, 1, 2, 2, 3, 3, 3, 6, 7};
	int target = 7;
	Solution solution;
	auto result = solution.combinationSum2(candidates, target);
	for (const auto &item : result) {
		for (const auto &num : item) {
			cout << num << " ";
		}
		cout << endl;
	}
}