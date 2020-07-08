//
// Created by Yuyang Huang on 7/7/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 *
 * https://leetcode.com/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (62.01%)
 * Likes:    1987
 * Dislikes: 116
 * Total Accepted:    213.9K
 * Total Submissions: 328.5K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * You are given a map in form of a two-dimensional integer grid where 1
 * represents land and 0 represents water.
 *
 * Grid cells are connected horizontally/vertically (not diagonally). The grid
 * is completely surrounded by water, and there is exactly one island (i.e.,
 * one or more connected land cells).
 *
 * The island doesn't have "lakes" (water inside that isn't connected to the
 * water around the island). One cell is a square with side length 1. The grid
 * is rectangular, width and height don't exceed 100. Determine the perimeter
 * of the island.
 *
 *
 *
 * Example:
 *
 *
 * Input:
 * [[0,1,0,0],
 * ⁠[1,1,1,0],
 * ⁠[0,1,0,0],
 * ⁠[1,1,0,0]]
 *
 * Output: 16
 *
 * Explanation: The perimeter is the 16 yellow stripes in the image below:
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
public:
	/*
	 * Time complexity: O(mn)
	 * we only need to check left and above cells,
	 * if there are adjacent cells then minus 2 for adjacency
	 */
	int islandPerimeter(vector<vector<int>> &grid) {
		int perimeter = 0;
		for (int row = 0; row < grid.size(); ++row) {
			for (int col = 0; col < grid[0].size(); ++col) {
				if (grid[row][col]) {
					perimeter += 4;
					if (row > 0) {
						if (grid[row - 1][col]) { perimeter -= 2; }
					}
					if (col > 0) {
						if (grid[row][col - 1]) { perimeter -= 2; }
					}
				}
			}
		}
		return perimeter;
	}
};
// @lc code=end

int main() {
	Solution solution;
	vector<vector<int>> grid;
	
	grid = {{0, 1, 0, 0},
	        {1, 1, 1, 0},
	        {0, 1, 0, 0},
	        {1, 1, 0, 0}};
	PrintSingleResult(solution.islandPerimeter(grid));
	
	grid = {{}};
	PrintSingleResult(solution.islandPerimeter(grid));
	
	grid = {{1}};
	PrintSingleResult(solution.islandPerimeter(grid));
	
	grid = {{0}};
	PrintSingleResult(solution.islandPerimeter(grid));
	
	Complete();
}