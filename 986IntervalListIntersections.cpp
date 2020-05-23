//
// Created by Yuyang Huang on 5/23/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 *
 * https://leetcode.com/problems/interval-list-intersections/description/
 *
 * algorithms
 * Medium (64.15%)
 * Likes:    1114
 * Dislikes: 36
 * Total Accepted:    89.7K
 * Total Submissions: 134.7K
 * Testcase Example:  '[[0,2],[5,10],[13,23],[24,25]]\n[[1,5],[8,12],[15,24],[25,26]]'
 *
 * Given two lists of closed intervals, each list of intervals is pairwise
 * disjoint and in sorted order.
 *
 * Return the intersection of these two interval lists.
 *
 * (Formally, a closed interval [a, b] (with a <= b) denotes the set of real
 * numbers x with a <= x <= b.  The intersection of two closed intervals is a
 * set of real numbers that is either empty, or can be represented as a closed
 * interval.  For example, the intersection of [1, 3] and [2, 4] is [2,
 * 3].)
 *
 *
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: A = [[0,2],[5,10],[13,23],[24,25]], B =
 * [[1,5],[8,12],[15,24],[25,26]]
 * Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 * Reminder: The inputs and the desired output are lists of Interval objects,
 * and not arrays or lists.
 *
 *
 *
 *
 * Note:
 *
 *
 * 0 <= A.length < 1000
 * 0 <= B.length < 1000
 * 0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
 *
 *
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 *
 *
 */

// @lc code=start

/*
 * time complexity: O(n)
 */
class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B) {
		auto ita = A.begin(), itb = B.begin();
		vector<vector<int>> result;
		// go through the list to check intersection
		while (ita != A.end() && itb != B.end()) {
			int start = max((*ita)[0], (*itb)[0]);
			int end = min((*ita)[1], (*itb)[1]);
			if (end - start >= 0) {
				result.push_back({start, end});
			}
			
			// go to the next interval for the one ends first
			if ((*ita)[1] < (*itb)[1]) {
				++ita;
			} else {
				++itb;
			}
		}
		return result;
	}
};
// @lc code=end

int main() {
	vector<vector<int>> A = {{0,  2},
	                         {5,  10},
	                         {13, 23},
	                         {24, 25}}, B = {{1,  5},
	                                         {8,  12},
	                                         {15, 24},
	                                         {25, 26}}, result = {{1,  2},
	                                                              {5,  5},
	                                                              {8,  10},
	                                                              {15, 23},
	                                                              {24, 24},
	                                                              {25, 25}};
	Solution solution;
	auto ans = solution.intervalIntersection(A, B);
	assert(ans == result);
	Complete();
}

