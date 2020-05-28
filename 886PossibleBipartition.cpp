//
// Created by Yuyang Huang on 5/27/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 *
 * https://leetcode.com/problems/possible-bipartition/description/
 *
 * algorithms
 * Medium (41.54%)
 * Likes:    695
 * Dislikes: 21
 * Total Accepted:    37.6K
 * Total Submissions: 87.8K
 * Testcase Example:  '4\n[[1,2],[1,3],[2,4]]'
 *
 * Given a set of NÂ people (numbered 1, 2, ..., N), we would like to split
 * everyone into two groups of any size.
 *
 * Each person may dislike some other people, and they should not go into the
 * same group.Â 
 *
 * Formally, if dislikes[i] = [a, b], it means it is not allowed to put the
 * people numbered a and b into the same group.
 *
 * Return trueÂ if and only if it is possible to split everyone into two groups
 * in this way.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
 * Output: true
 * Explanation: group1 [1,4], group2 [2,3]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
 * Output: false
 *
 *
 *
 * Example 3:
 *
 *
 * Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
 * Output: false
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= N <= 2000
 * 0 <= dislikes.length <= 10000
 * 1 <= dislikes[i][j] <= N
 * dislikes[i][0] < dislikes[i][1]
 * There does not exist i != j for which dislikes[i] == dislikes[j].
 *
 *
 *
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(n)
 * Two color problem, DFS
 */
class Solution {
public:
	bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
		if (dislikes.empty()) {
			return true;
		}
		unordered_map<int, vector<int>> numDisLikeMap;
		vector<int> group(N + 1, -1);
		stack<int> nums;
		// two numbers need to disklike each other, thus, bidirectional
		for (const auto &item : dislikes) {
			numDisLikeMap[item[0]].emplace_back(item[1]);
			numDisLikeMap[item[1]].emplace_back(item[0]);
		}
		
		// insert keys into stack to ensure cover all sub graphs
		for (const auto &disLikeMap : numDisLikeMap) {
			nums.push(disLikeMap.first);
		}
		
		// DFS
		while (!nums.empty()) {
			int num = nums.top();
			nums.pop();
			int currentGroupNum = (group[num] == -1) ? 0 : group[num];
			for (const auto &dislikeNum : numDisLikeMap[num]) {
				if (group[dislikeNum] == currentGroupNum) {
					return false;
				} else {
					if (group[dislikeNum] != -1) {
						continue;
					}
					group[dislikeNum] = abs(currentGroupNum - 1);
					nums.emplace(dislikeNum);
				}
			}
		}
		return true;
	}
};
// @lc code=end

int main() {
	Solution solution;
	vector<vector<int>> disLikes = {{1, 2},
	                                {1, 3},
	                                {2, 4}};
	assert(solution.possibleBipartition(4, disLikes) == true);
	disLikes = {{1, 2},
	            {1, 3},
	            {2, 3}};
	assert(solution.possibleBipartition(3, disLikes) == false);
	disLikes = {{1, 2},
	            {2, 3},
	            {3, 4},
	            {4, 5},
	            {1, 5}};
	assert(solution.possibleBipartition(5, disLikes) == false);
	
	disLikes = {{4, 7},
	            {4, 8},
	            {5, 6},
	            {1, 6},
	            {3, 7},
	            {2, 5},
	            {5, 8},
	            {1, 2},
	            {4, 9},
	            {6, 10},
	            {8, 10},
	            {3, 6},
	            {2, 10},
	            {9, 10},
	            {3, 9},
	            {2, 3},
	            {1, 9},
	            {4, 6},
	            {5, 7},
	            {3, 8},
	            {1, 8},
	            {1, 7},
	            {2, 4}};
	assert(solution.possibleBipartition(10, disLikes) == true);
	Complete();
}