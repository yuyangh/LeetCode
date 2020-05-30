#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (39.71%)
 * Likes:    3472
 * Dislikes: 168
 * Total Accepted:    380.7K
 * Total Submissions: 906.4K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 *
 *
 * Example 1:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation:Â There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 *
 * Example 2:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation:Â There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 *
 *
 *
 * Constraints:
 *
 *
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 1 <=Â numCourses <= 10^5
 *
 *
 */

/*
 * Time complexity: O(V+E)
 * Topological sort works on multi-edge
 * Adjacent list vs. Adjacent matrix
 */
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
		vector<int> numPrerequisite(numCourses, 0);
		vector<vector<int>> adjList(numCourses);
		
		// construct dependency graph
		for (const auto &prerequisite : prerequisites) {
			int from = prerequisite[0], to = prerequisite[1];
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
		
		// topological sort
		while (!bag.empty()) {
			int fromCourseId = bag.front();
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
				return false;
			}
		}
		return true;
	}
};

int main() {
	vector<vector<int>> prerequisites = {{0, 1}};
	Solution solution;
	assert(solution.canFinish(2, prerequisites));
	prerequisites = {{0, 1},
	                 {1, 0}};
	assert(!solution.canFinish(2, prerequisites));
	Complete();
}