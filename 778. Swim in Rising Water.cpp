//
// Created by Yuyang Huang on 6/21/21.
//

/*
 * 778. Swim in Rising Water
 * Hard
 *
 * On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).
 * Now rain starts to fall. At time t, the depth of the water everywhere is t.
 * You can swim from a square to another 4-directionally adjacent square if and only if
 * the elevation of both squares individually are at most t. You can swim infinite distance in zero time.
 * Of course, you must stay within the boundaries of the grid during your swim.
 *
 * You start at the top left square (0, 0).
 * What is the least time until you can reach the bottom right square (N-1, N-1)?
 *
 * Example 1:
 * Input: [[0,2],[1,3]]
 * Output: 3
 * Explanation:
 * At time 0, you are in grid location (0, 0).
 * You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
 * You cannot reach point (1, 1) until time 3.
 * When the depth of water is 3, we can swim anywhere inside the grid.
 *
 * Example 2:
 * Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
 * Output: 16
 * Explanation:
 * 0  1  2  3  4
 * 24 23 22 21  5
 * 12 13 14 15 16
 * 11 17 18 19 20
 * 10  9  8  7  6
 *
 * The final route is marked in bold.
 * We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 * Note:
 *
 * 2 <= N <= 50.
 * grid[i][j] is a permutation of [0, ..., N*N - 1].
 */

#include "LeetCodeLib.h"

/*
 * Time Complexity: O(n*n*log(n))
 * use priority queue to find the best route
 */
class Solution {
public:
	int swimInWater(vector<vector<int>> &grid) {
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
		visited[0][0] = true;
		
		
		auto comp = [](tuple<int, int, int> &lhs, tuple<int, int, int> &rhs) {
			return get<2>(lhs) > get<2>(rhs);
		};
		
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(comp)> pq(comp);
		pq.push(make_tuple(0, 0, grid[0][0]));
		
		int cost = 0;
		while (!pq.empty()) {
			auto point = pq.top();
			pq.pop();
			if (get<2>(point) > cost) {
				cost = get<2>(point);
			}
			visited[get<0>(point)][get<1>(point)] = true;
			
			// reach the destination
			if (get<0>(point) + 1 == grid.size() && get<1>(point) + 1 == grid[0].size()) {
				return cost;
			}
			auto points = addNearByPoints(grid, point, visited);
			for (const auto &item : points) {
				pq.emplace(item);
			}
			
			
		}
		return cost;
	}
	
	vector<tuple<int, int, int>>
	addNearByPoints(vector<vector<int>> &grid, tuple<int, int, int> &point, vector<vector<bool>> &visited) {
		int row = get<0>(point);
		int col = get<1>(point);
		vector<tuple<int, int, int>> availablePoints;
		
		if (row > 0 && !visited[row - 1][col]) {
			availablePoints.emplace_back(row - 1, col, grid[row - 1][col]);
		}
		if (row + 1 < grid.size() && !visited[row + 1][col]) {
			availablePoints.emplace_back(row + 1, col, grid[row + 1][col]);
		}
		if (col > 0 && !visited[row][col - 1]) {
			availablePoints.emplace_back(row, col - 1, grid[row][col - 1]);
		}
		if (col + 1 < grid[0].size() && !visited[row][col + 1]) {
			availablePoints.emplace_back(row, col + 1, grid[row][col + 1]);
		}
		return availablePoints;
	}
};

int main() {
	Solution solution;
	vector<vector<int>> grid({{0}});
	PrintSingleResult(solution.swimInWater(grid));
	
	grid = {{0, 2},
	        {1, 3}};
	PrintSingleResult(solution.swimInWater(grid));
	
	grid = {{0,  1,  2,  3,  4},
	        {24, 23, 22, 21, 5},
	        {12, 13, 14, 15, 16},
	        {11, 17, 18, 19, 20},
	        {10, 9,  8,  7,  6}};
	PrintSingleResult(solution.swimInWater(grid));
	
	Complete();
}