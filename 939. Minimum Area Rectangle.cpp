//
// Created by Yuyang Huang on 6/21/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=939 lang=cpp
 *
 * [939] Minimum Area Rectangle
 *
 * https://leetcode.com/problems/minimum-area-rectangle/description/
 *
 * algorithms
 * Medium (51.61%)
 * Likes:    631
 * Dislikes: 126
 * Total Accepted:    47.4K
 * Total Submissions: 91.2K
 * Testcase Example:  '[[1,1],[1,3],[3,1],[3,3],[2,2]]'
 *
 * Given a set of points in the xy-plane, determine the minimum area of a
 * rectangle formed from these points, with sides parallel to the x and y
 * axes.
 *
 * If there isn't any rectangle, return 0.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
 * Output: 4
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
 * Output: 2
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= points.length <= 500
 * 0 <=Â points[i][0] <=Â 40000
 * 0 <=Â points[i][1] <=Â 40000
 * All points are distinct.
 *
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(n*n)
 * use hash set and customized hash function to remember each point's location
 * then use diagonal to find potential other diagonal that can form a rectangle
 */
class Solution {
public:
	int minAreaRect(vector<vector<int>> &points) {
		auto hash = [](const pair<int, int> &p) { return p.first * 31 + p.second; };
		unordered_set<pair<int, int>, decltype(hash)> pointsSet(points.size(), hash);
		
		for (const auto &point : points) {
			pointsSet.emplace(make_pair(point[0], point[1]));
		}
		
		int minArea = INT_MAX;
		for (const auto &firstPoint : pointsSet) {
			for (const auto &secondPoint : pointsSet) {
				// avoid overlap edge situation
				if (firstPoint.first == secondPoint.first ||
				    firstPoint.second == secondPoint.second) {
					continue;
				}
				
				// find possible rectangle points
				if (pointsSet.count(make_pair(firstPoint.first, secondPoint.second)) &&
				    pointsSet.count(make_pair(secondPoint.first, firstPoint.second))) {
					int area = abs(firstPoint.first - secondPoint.first) *
					           abs(firstPoint.second - secondPoint.second);
					minArea = min(minArea, area);
				}
			}
		}
		return minArea == INT_MAX ? 0 : minArea;
	}
};
// @lc code=end

int main() {
	Solution solution;
	
	vector<vector<int>> points;
	points = {{1, 1},
	          {1, 3},
	          {3, 1},
	          {3, 3},
	          {2, 2}};
	assert(solution.minAreaRect(points) == 4);
	
	points = {{1, 1},
	          {1, 3},
	          {3, 1},
	          {3, 3},
	          {4, 1},
	          {4, 3}};
	assert(solution.minAreaRect(points) == 2);
	
	Complete();
}