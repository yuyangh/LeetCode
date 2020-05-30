//
// Created by Yuyang Huang on 5/29/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (36.77%)
 * Likes:    1909
 * Dislikes: 126
 * Total Accepted:    242.3K
 * Total Submissions: 620K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, return
 * the ordering of courses you should take to finish all courses.
 *
 * There may be multiple correct orders, you just need to return one of them.
 * If it is impossible to finish all courses, return an empty array.
 *
 * Example 1:
 *
 *
 * Input: 2, [[1,0]]
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished
 * course 0. So the correct course order is [0,1] .
 *
 * Example 2:
 *
 *
 * Input: 4, [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,1,2,3] or [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both
 * ⁠            courses 1 and 2. Both courses 1 and 2 should be taken after you
 * finished course 0.
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3] .
 *
 * Note:
 *
 *
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(V+E)
 * Topological sort works on multi-edge
 * Adjacent list vs. Adjacent matrix
 */
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> numPrerequisite(numCourses, 0);
		vector<vector<int>> adjList(numCourses);
		
		// construct dependency graph
		for (const auto &prerequisite : prerequisites) {
			int from = prerequisite[1], to = prerequisite[0];
			// topological sort works on duplicate case
			numPrerequisite[to]++;
			adjList[from].emplace_back(to);
		}
		
		queue<int> bag;
		for (int courseId = 0; courseId < numCourses; ++courseId) {
			if (numPrerequisite[courseId] == 0) {
				bag.push(courseId);
			}
		}
		
		vector<int> courseOrders;
		
		// topological sort
		while (!bag.empty()) {
			int fromCourseId = bag.front();
			courseOrders.emplace_back(fromCourseId);
			bag.pop();
			for (const auto &toCourseId : adjList[fromCourseId]) {
				numPrerequisite[toCourseId]--;
				if (numPrerequisite[toCourseId] == 0) {
					bag.push(toCourseId);
				}
			}
		}
		
		// check any course remain
		for (const auto &num : numPrerequisite) {
			if (num != 0) {
				return {};
			}
		}
		return courseOrders;
	}
};
// @lc code=end


int main() {
	vector<vector<int>> prerequisites = {{1, 0}};
	Solution solution;
	PrintVector(solution.findOrder(2, prerequisites));
	prerequisites = {{1,0},{2,0},{3,1},{3,2}};
	PrintVector(solution.findOrder(4, prerequisites));
	Complete();
}