#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (46.81%)
 * Likes:    1354
 * Dislikes: 39
 * Total Accepted:    231.5K
 * Total Submissions: 493.3K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Example:
 *
 *
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 *
 *
 */
class Solution {
public:
	// directed path should think about DP
	int minPathSum(vector<vector<int>> &grid) {
		if (grid.empty()) {
			return 0;
		}
		// memorize the cost
		vector<vector<int>> cost(grid.size(), vector<int>(grid[0].size(), 0));
		
		// initial point
		cost[0][0] = grid[0][0];
		
		// initialize edge
		for (int i = 1; i < grid.size(); ++i) {
			cost[i][0] = cost[i - 1][0] + grid[i][0];
		}
		for (int i = 1; i < grid[0].size(); ++i) {
			cost[0][i] = cost[0][i - 1] + grid[0][i];
		}
		for (int row = 1; row < grid.size(); ++row) {
			for (int col = 1; col < grid[0].size(); ++col) {
				cost[row][col] = min(cost[row - 1][col], cost[row][col - 1])
				                 + grid[row][col];
			}
		}
		
		return cost[grid.size() - 1][grid[0].size() - 1];
	}
	
	
	// priority queue takes O(m*n*log(m*n))
	int minPathSumPQ(vector<vector<int>> &grid) {
		if (grid.empty()) {
			return 0;
		}
		auto comp = [](Point &lhs, Point &rhs) {
			if (lhs.cost > rhs.cost) {
				return true;
			} else {
				if (lhs.cost == rhs.cost &&
				    lhs.destDist() < rhs.destDist()) {
					return true;
				}
			}
			return false;
		};
		
		priority_queue<Point, vector<Point>, decltype(comp)> pq(comp);
		Point point(grid[0][0], 0, 0);
		pq.push(point);
		int destDist = grid.size() + grid[0].size() - 2;
		do {
			point = pq.top();
			pq.pop();
			if (point.x + 1 < grid.size()) {
				pq.push({point.cost + grid[point.x + 1][point.y],
				         point.x + 1, point.y});
			}
			if (point.y + 1 < grid[0].size()) {
				pq.push({point.cost + grid[point.x][point.y + 1],
				         point.x, point.y + 1});
			}
		} while (point.destDist() != destDist);
		return point.cost;
	}
	
	struct Point {
		int cost;
		int x;
		int y;
		
		Point(int c, int x, int y) :
				cost(c), x(x), y(y) {};
		
		int destDist() {
			return x + y;
		}
	};
};

int main() {
	vector<vector<int>> grid = {{1, 3, 1},
	                            {1, 5, 1},
	                            {4, 2, 1}};
	grid = {{100, 12, 1},
	        {1,   25, 0},
	        {34,  25, 19},
	        {1,   25, 0}};
	Solution solution;
	int ans = solution.minPathSum(grid);
	cout << ans << endl;
}

