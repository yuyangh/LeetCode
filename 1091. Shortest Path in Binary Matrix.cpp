//
// Created by Yuyang Huang on 10/23/21.
//

/*
 * 1091. Shortest Path in Binary Matrix
 * Medium
 *
 * Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix.
 * If there is no clear path, return -1.
 * A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0))
 * to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
 * All the visited cells of the path are 0.
 * All the adjacent cells of the path are 8-directionally connected
 * (i.e., they are different and they share an edge or a corner).
 * The length of a clear path is the number of visited cells of this path.
 *
 * Example 1:
 * Input: grid = [[0,1],[1,0]]
 * Output: 2
 *
 * Example 2:
 * Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
 * Output: 4
 *
 * Example 3:
 * Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
 * Output: -1
 *
 * Constraints:
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 100
 * grid[i][j] is 0 or 1
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * time complexity: O(mnlog(mn))
	 * use A* to find the shortest path
	 */
	int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
		if (grid.empty()) {
			return 0;
		}
		if (grid.front().front() == 1) {
			return -1;
		}
		
		int placeHolderValue = 999;
		int rows = grid.size(), cols = grid.front().size();
		vector<vector<int>> dist(rows, vector<int>(cols, placeHolderValue));
		
		// because pq's data cannot have side effect, so cannot pass dist into the comparator
		function<int(tuple<int, int, int>, tuple<int, int, int>)> comp = [rows, cols](tuple<int, int, int> lhs,
		                                                                              tuple<int, int, int> rhs) {
			return get<2>(lhs) + max(rows - get<0>(lhs), cols - get<1>(lhs)) >
			       get<2>(rhs) + max(rows - get<0>(rhs), cols - get<1>(rhs));
		};
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(comp)> pq(comp);
		
		pq.push({0, 0, 1});
		dist[0][0] = 1;
		
		vector<vector<int>> moves = {{1,  0},
		                             {-1, 0},
		                             {0,  1},
		                             {0,  -1},
		                             {1,  1},
		                             {-1, 1},
		                             {-1, -1},
		                             {1,  -1}};
		
		while (!pq.empty()) {
			auto point = pq.top();
			pq.pop();
			auto row = get<0>(point), col = get<1>(point);
			if (row == rows - 1 && col == cols - 1) {
				return dist[row][col];
			}
			for (auto &move: moves) {
				int nx = row + move[0], ny = col + move[1], ndist = dist[row][col] + 1;
				if (0 <= nx && nx < rows &&
				    0 <= ny && ny < cols &&
				    grid[nx][ny] == 0 &&
				    ndist < dist[nx][ny]) {
					// update the distance
					dist[nx][ny] = ndist;
					pq.push({nx, ny, ndist});
				}
			}
		}
		return -1;
	}
};

int main() {
	Solution solution;
	vector<vector<int>> grid;
	grid = {{0, 1},
	        {1, 0}};
	PrintSingleResult(solution.shortestPathBinaryMatrix(grid));
	
	grid = {{0, 0, 1, 0, 0, 0, 0},
	        {0, 1, 0, 0, 0, 0, 1},
	        {0, 0, 1, 0, 1, 0, 0},
	        {0, 0, 0, 1, 1, 1, 0},
	        {1, 0, 0, 1, 1, 0, 0},
	        {1, 1, 1, 1, 1, 0, 1},
	        {0, 0, 1, 0, 0, 0, 0}};
	PrintSingleResult(solution.shortestPathBinaryMatrix(grid));
	
	grid = {{0, 0, 0},
	        {1, 0, 0},
	        {1, 1, 0}};
	PrintSingleResult(solution.shortestPathBinaryMatrix(grid));
	
	grid = {{0, 1, 1, 0, 0, 0},
	        {0, 1, 0, 1, 1, 0},
	        {0, 1, 1, 0, 1, 0},
	        {0, 0, 0, 1, 1, 0},
	        {1, 1, 1, 1, 1, 0},
	        {1, 1, 1, 1, 1, 0}};
	PrintSingleResult(solution.shortestPathBinaryMatrix(grid));
}