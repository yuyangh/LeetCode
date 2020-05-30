//
// Created by Yuyang Huang on 5/29/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 *
 * https://leetcode.com/problems/k-closest-points-to-origin/description/
 *
 * algorithms
 * Medium (61.19%)
 * Likes:    1491
 * Dislikes: 107
 * Total Accepted:    238K
 * Total Submissions: 381.6K
 * Testcase Example:  '[[1,3],[-2,2]]\n1'
 *
 * We have a list of points on the plane.  Find the K closest points to the
 * origin (0, 0).
 *
 * (Here, the distance between two points on a plane is the Euclidean
 * distance.)
 *
 * You may return the answer in any order.  The answer is guaranteed to be
 * unique (except for the order that it is in.)
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: points = [[1,3],[-2,2]], K = 1
 * Output: [[-2,2]]
 * Explanation:
 * The distance between (1, 3) and the origin is sqrt(10).
 * The distance between (-2, 2) and the origin is sqrt(8).
 * Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
 * We only want the closest K = 1 points from the origin, so the answer is just
 * [[-2,2]].
 *
 *
 *
 * Example 2:
 *
 *
 * Input: points = [[3,3],[5,-1],[-2,4]], K = 2
 * Output: [[3,3],[-2,4]]
 * (The answer [[-2,4],[3,3]] would also be accepted.)
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= K <= points.length <= 10000
 * -10000 < points[i][0] < 10000
 * -10000 < points[i][1] < 10000
 *
 *
 *
 */

// @lc code=start

/*
 * Time Complexity: O(n)
 */
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
		// calculate the squared distance to origin
		for (auto &point : points) {
			point.emplace_back(point[0] * point[0] + point[1] * point[1]);
		}
		
		// first K elements are smaller than K
		nth_element(points.begin(), points.begin() + K - 1, points.end(),
		            [](vector<int> &lhs, vector<int> &rhs) {
			            return lhs.back() < rhs.back();
		            });
		
		vector<vector<int>> result;
		result.reserve(K);
		for (int i = 0; i < K; ++i) {
			result.push_back(points[i]);
			result.back().pop_back();
		}
		
		return result;
	}
};
// @lc code=end

int main() {
	Solution solution;
	vector<vector<int>> points;
	int K;
	points = {{1,  3},
	          {-2, 2}};
	K = 1;
	PrintVectorVector(solution.kClosest(points, K));
	points = {{3,  3},
	          {5,  -1},
	          {-2, 4}};
	K = 2;
	PrintVectorVector(solution.kClosest(points, K));
	Complete();
}
