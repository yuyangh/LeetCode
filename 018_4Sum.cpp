#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (30.62%)
 * Likes:    1115
 * Dislikes: 220
 * Total Accepted:    241.1K
 * Total Submissions: 782.9K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 *
 * Note:
 * The solution set must not contain duplicate quadruplets.
 *
 * Example:
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 */
class Solution {
public:
	vector<vector<int>> fourSum(vector<int> &nums, int target) {
		if (nums.empty() || nums.size() < 4) {
			return vector<vector<int>>();
		}
		goal = target;
		
		// sort numbers in ascending order
		sort(nums.begin(), nums.end());
		
		nonDuplicateNums.reserve(nums.size());
		valueCountPosMap.reserve(nums.size() * nums.size());
		
		auto it = valueCountPosMap.begin();
		for (int num : nums) {
			it = valueCountPosMap.find(num);
			if (it == valueCountPosMap.end()) {
				// record number of existence and position in nonDuplicateNums
				valueCountPosMap[num] = make_pair(1, nonDuplicateNums.size());
				nonDuplicateNums.push_back(num);
			} else {
				++valueCountPosMap[num].first;
			}
		}
		vector<int> single;
		sum(nums, single, 0, 4);
		return result;
	}

private:
	vector<int> nonDuplicateNums;
	// key is number's value, value is <count,position in nonDuplicateNums>
	unordered_map<int, pair<int, int>> valueCountPosMap;
	vector<vector<int>> result;
	int goal;
	
	void sum(vector<int> &nums, vector<int> &single, int index, int remain) {
		// base case
		if (remain == 1) {
			int arrSum = accumulate(single.begin(), single.end(), 0);
			auto it = valueCountPosMap.find(goal - arrSum);
			// invalid
			if (it == valueCountPosMap.end()) {
				return;
			}
			// last number has choice
			if (it->second.first > 0) {
				// last number is after current ones
				if (it->second.second < index) {
					return;
				}
				single.emplace_back(it->first);
				result.emplace_back(single);
				single.pop_back();
			}
			return;
		}
		
		for (int pos = index; pos < nonDuplicateNums.size(); ++pos) {
			if (valueCountPosMap[nonDuplicateNums[pos]].first <= 0) {
				continue;
			}
			// backtracking
			single.emplace_back(nonDuplicateNums[pos]);
			--valueCountPosMap[nonDuplicateNums[pos]].first;
			sum(nums, single, pos, remain - 1);
			++valueCountPosMap[nonDuplicateNums[pos]].first;
			single.pop_back();
		}
	}
	
	inline unsigned long long combine(int a, int b) {
		return static_cast<long long >(a) << 32 | b;
	}
};

int main() {
	vector<int> input = {-1, -1, -1, -1, 0, 0, 1, 2, 3};
	// input={-1,0,1,2,-1,-4};
	int target = 2;
	Solution solution;
	auto result = solution.fourSum(input, target);
	PrintVectorVector(result);
	return 0;
}

