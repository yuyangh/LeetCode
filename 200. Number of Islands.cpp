//
// Created by Yuyang Huang on 10/24/19.
//

/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (43.30%)
 * Likes:    3362
 * Dislikes: 123
 * Total Accepted:    454.7K
 * Total Submissions: 1M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 *
 * Example 1:
 *
 *
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Output: 3
 *
 */

// @lc code=start
#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * use DFS, time complexity: O(mn)
	 */
	int numIslands(vector<vector<char>> &grid) {
		if (grid.empty() || grid[0].empty()) {
			return 0;
		}
		
		int islands = 0;
		// check whether this is a new island
		for (int row = 0; row < grid.size(); ++row) {
			for (int col = 0; col < grid[0].size(); ++col) {
				islands += search(grid, row, col);
			}
		}
		return islands;
	}
	
	/**
	 * 'X' represent being searched
	 * @return find an island or not
	 */
	bool search(vector<vector<char>> &grid, int row, int col) {
		if (row < 0 || row >= grid.size()) {
			return false;
		}
		if (col < 0 || col >= grid[0].size()) {
			return false;
		}
		if (grid[row][col] == '1') {
			grid[row][col] = 'X';
			search(grid, row + 1, col);
			search(grid, row - 1, col);
			search(grid, row, col + 1);
			search(grid, row, col - 1);
			return true;
		}
		return false;
	}
};
// @lc code=end

int main() {
	
	vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
	                             {'1', '1', '0', '1', '0'},
	                             {'1', '1', '0', '0', '0'},
	                             {'0', '0', '0', '0', '0'}};
	Solution solution;
	auto result = solution.numIslands(grid);
	
	PrintSingleResult(result);
	return 0;
	
}

