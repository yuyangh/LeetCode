//
// Created by Yuyang Huang on 9/7/21.
//

/*
 * TODO: not completed
 */

/*
 * 1263. Minimum Moves to Move a Box to Their Target Location
 * Hard
 *
 * A storekeeper is a game in which the player pushes boxes around in a warehouse
 * trying to get them to target locations.
 *
 * The game is represented by an m x n grid of characters grid where each element is a wall, floor, or box.
 * Your task is to move the box 'B' to the target position 'T' under the following rules:
 * The character 'S' represents the player.
 * The player can move up, down, left, right in grid if it is a floor (empty cell).
 * The character '.' represents the floor which means a free cell to walk.
 * The character '#' represents the wall which means an obstacle (impossible to walk there).
 * There is only one box 'B' and one target cell 'T' in the grid.
 * The box can be moved to an adjacent free cell by standing next to the box
 * and then moving in the direction of the box. This is a push.
 *
 * The player cannot walk through the box.
 * Return the minimum number of pushes to move the box to the target.
 * If there is no way to reach the target, return -1.
 *
 * Example 1:
 * Input: grid =
 * [["#","#","#","#","#","#"],
 * ["#","T","#","#","#","#"],
 * ["#",".",".","B",".","#"],
 * ["#",".","#","#",".","#"],
 * ["#",".",".",".","S","#"],
 * ["#","#","#","#","#","#"]]
 * Output: 3
 * Explanation: We return only the number of times the box is pushed.
 *
 * Example 2:
 * Input: grid = [["#","#","#","#","#","#"],
 * ["#","T","#","#","#","#"],
 * ["#",".",".","B",".","#"],
 * ["#","#","#","#",".","#"],
 * ["#",".",".",".","S","#"],
 * ["#","#","#","#","#","#"]]
 * Output: -1
 *
 * Example 3:
 * Input: grid = [["#","#","#","#","#","#"],
 * ["#","T",".",".","#","#"],
 * ["#",".","#","B",".","#"],
 * ["#",".",".",".",".","#"],
 * ["#",".",".",".","S","#"],
 * ["#","#","#","#","#","#"]]
 * Output: 5
 * Explanation:  push the box down, left, left, up and up.
 *
 * Example 4:
 * Input: grid =
 * [["#","#","#","#","#","#","#"],
 * ["#","S","#",".","B","T","#"],
 * ["#","#","#","#","#","#","#"]]
 * Output: -1
 *
 * Constraints:
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 20
 * grid contains only characters '.', '#', 'S', 'T', or 'B'.
 * There is only one character 'S', 'B', and 'T' in the grid.
 */
#include "LeetCodeLib.h"

class Solution {
public:
	int minPushBox(vector<vector<char>> &grid) {
		vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), 100));
		
		auto targetLoc = findTarget(grid, 'T');
		dist[targetLoc.first][targetLoc.second] = 0;
		
		queue<pair<int, int>> points;
		points.emplace(targetLoc);
		queue<pair<int, int>> pushPoints;
		pushPoints.emplace(targetLoc);
		
		while (!points.empty()) {
			int x, y;
			auto point = points.front();
			points.pop();
			auto pushPoint = pushPoints.front();
			pushPoints.pop();
			
			x = point.first;
			y = point.second;
			
			if (grid[x][y] == 'B') {
				if (playerToBrick(grid, pushPoint)) { return dist[x][y]; }
				continue;
			}
			
			for (auto &move: moves) {
				int boxLocX, boxLocY, playerLocX, playerLocY;
				boxLocX = x + move[0];
				boxLocY = y + move[1];
				playerLocX = x + 2 * move[0];
				playerLocY = y + 2 * move[1];
				
				if (validPoint(boxLocX, boxLocY, grid.size(), grid.front().size())
				    && validLocation(boxLocX, boxLocY, grid)
				    && validPoint(playerLocX, playerLocY, grid.size(), grid.front().size())
				    && validLocation(playerLocX, playerLocY, grid)) {
					
					if (dist[x][y] + 1 < dist[boxLocX][boxLocY]) {
						dist[boxLocX][boxLocY] = min(dist[x][y] + 1, dist[boxLocX][boxLocY]);
						
						points.emplace(make_pair(boxLocX, boxLocY));
						pushPoints.emplace(make_pair(playerLocX, playerLocY));
					}
				}
			}
			// PrintVectorVector(dist);
			// cout << endl;
		}
		return -1;
	}

private:
	vector<vector<int>> moves = {{1,  0},
	                             {0,  1},
	                             {-1, 0},
	                             {0,  -1}};
	
	bool validPoint(int x, int y, int xLimit, int yLimit) {
		return 0 <= x && x < xLimit
		       && 0 <= y && y < yLimit;
	}
	
	bool validLocation(int x, int y, vector<vector<char>> &grid) {
		return grid[x][y] != '#';
	}
	
	pair<int, int> findTarget(vector<vector<char>> &grid, char target) {
		for (int row = 0; row < grid.size(); ++row) {
			for (int col = 0; col < grid[0].size(); ++col) {
				if (grid[row][col] == target) {
					return make_pair(row, col);
				}
			}
		}
		return make_pair(-1, -1);
	}
	
	bool playerToBrick(vector<vector<char>> &grid, pair<int, int> pushPos) {
		auto playerLoc = findTarget(grid, 'S');
		queue<pair<int, int>> points;
		points.push(make_pair(playerLoc.first, playerLoc.second));
		
		while (!points.empty()) {
			int x, y;
			auto point = points.front();
			points.pop();
			x = point.first;
			y = point.second;
			if (x == pushPos.first && y == pushPos.second) {
				return true;
			}
			
			
			for (auto &move: moves) {
				int nextX = x + move[0];
				int nextY = y + move[1];
				if (validPoint(nextX, nextY, grid.size(), grid.front().size())
				    && validLocation(nextX, nextY, grid)) {
					points.emplace(make_pair(nextX, nextY));
					
				}
			}
		}
		return false;
	}
};

int main() {
	Solution solution;
	vector<vector<char>> grid;
	
	grid = {{'#', '#', '#', '#', '#', '#'},
	        {'#', 'T', '#', '#', '#', '#'},
	        {'#', '.', '.', 'B', '.', '#'},
	        {'#', '.', '#', '#', '.', '#'},
	        {'#', '.', '.', '.', 'S', '#'},
	        {'#', '#', '#', '#', '#', '#'}};
	
	PrintSingleResult(solution.minPushBox(grid));
	
	grid = {{'#', '#', '#', '#', '#', '#'},
	        {'#', 'T', '#', '#', '#', '#'},
	        {'#', '.', '.', 'B', '.', '#'},
	        {'#', '#', '#', '#', '.', '#'},
	        {'#', '.', '.', '.', 'S', '#'},
	        {'#', '#', '#', '#', '#', '#'}};
	PrintSingleResult(solution.minPushBox(grid));
	
	grid = {{'#', '#', '#', '#', '#', '#'},
	        {'#', 'T', '.', '.', '#', '#'},
	        {'#', '.', '#', 'B', '.', '#'},
	        {'#', '.', '.', '.', '.', '#'},
	        {'#', '.', '.', '.', 'S', '#'},
	        {'#', '#', '#', '#', '#', '#'}};
	PrintSingleResult(solution.minPushBox(grid));
	
	grid = {{'#', '#', '#', '#', '#', '#', '#'},
	        {'#', 'S', '#', '.', 'B', 'T', '#'},
	        {'#', '#', '#', '#', '#', '#', '#'}};
	PrintSingleResult(solution.minPushBox(grid));
	
	grid = {{'#', '.', '.', '#', '#', '#', '#', '#'},
	        {'#', '.', '.', 'T', '#', '.', '.', '#'},
	        {'#', '.', '.', '.', '#', 'B', '.', '#'},
	        {'#', '.', '.', '.', '.', '.', '.', '#'},
	        {'#', '.', '.', '.', '#', '.', 'S', '#'},
	        {'#', '.', '.', '#', '#', '#', '#', '#'}};
	
}