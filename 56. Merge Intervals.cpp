#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * 56. Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium 
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * Example 1:
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 *
 *
 * Example 2:
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 *
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 *
 */

/*
 * Time complexity: O(nlogn)
 * greedy approach with priority queue
 */
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals) {
		if (intervals.empty()) {
			return vector<vector<int>>();
		}
		// sort's comp is different from priority_queue's comp
		// smaller content would be at the front with std::less<int>
		sort(intervals.begin(), intervals.end(), [](vector<int> &lhs, vector<int> &rhs) {
			return lhs[0] < rhs[0];
		});
		
		// use an additional vector to keep the result
		vector<vector<int>> result;
		result.push_back(intervals.front());
		
		for (int idx = 1; idx < intervals.size(); idx++) {
			if (result.back()[1] >= intervals[idx][0]) {
				result.back()[1] = max(result.back()[1], intervals[idx][1]);
			} else {
				result.push_back(intervals[idx]);
			}
		}
		return result;
	}
};

