//
// Created by Yuyang Huang on 6/8/21.
//
/*
 * 505. The Maze II
 * Medium
 * There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1).
 * The ball can go through the empty spaces by rolling up, down, left or right,
 * but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
 *
 * Given the m x n maze, the ball's start position and the destination,
 * where start = [startrow, startcol] and destination = [destinationrow, destinationcol],
 * return the shortest distance for the ball to stop at the destination.
 * If the ball cannot stop at destination, return -1.
 *
 * The distance is the number of empty spaces traveled by the ball
 * from the start position (excluded) to the destination (included).
 * You may assume that the borders of the maze are all walls (see examples).
 *
 * Example 1:
 * Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
 * Output: 12
 * Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
 * The length of the path is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
 *
 *
 * Example 2:
 * Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
 * Output: -1
 * Explanation: There is no way for the ball to stop at the destination.
 * Notice that you can pass through the destination but you cannot stop there.
 *
 * Example 3:
 * Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
 * Output: -1
 *
 * Constraints:
 * m == maze.length
 * n == maze[i].length
 * 1 <= m, n <= 100
 * maze[i][j] is 0 or 1.
 * start.length == 2
 * destination.length == 2
 * 0 <= startrow, destinationrow <= m
 * 0 <= startcol, destinationcol <= n
 * Both the ball and the destination exist in an empty space, and they will not be in the same position initially.
 * The maze contains at least 2 empty spaces.
 */


#include "LeetCodeLib.h"

/*
 * Time complexity: O(m*n*max(m,n))
 * use depth first search to search for all valid points
 * then check destination point whether valid or not
 */
class Solution {
public:
	int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
		if (start[0] == destination[0] && start[1] == destination[1]) {
			return 0;
		}
		vector<vector<int>> distance(maze.size(), vector<int>(maze.back().size(), INT_MAX));
		
		mazeWalker(maze, distance, start[0], start[1], 0);
		
		// check destination
		if (distance[destination[0]][destination[1]] == INT_MAX) {
			return -1;
		} else {
			return distance[destination[0]][destination[1]];
		}
	}
	
	void mazeWalker(vector<vector<int>> &maze, vector<vector<int>> &distance, int x, int y, int currDist) {
		int row, col, dist;
		row = x, col = y, dist = 0;
		
		// able to move up
		while (row - 1 >= 0 and maze[row - 1][col] != 1) {
			row--;
			dist++;
		}
		checkMove(x, y, currDist, row, col, dist, maze, distance);
		
		row = x, col = y, dist = 0;
		while (row + 1 < maze.size() and maze[row + 1][col] != 1) {
			row++;
			dist++;
		}
		checkMove(x, y, currDist, row, col, dist, maze, distance);
		
		row = x, col = y, dist = 0;
		while (col - 1 >= 0 and maze[row][col - 1] != 1) {
			col--;
			dist++;
		}
		checkMove(x, y, currDist, row, col, dist, maze, distance);
		
		row = x, col = y, dist = 0;
		while (col + 1 < maze.front().size() and maze[row][col + 1] != 1) {
			col++;
			dist++;
		}
		checkMove(x, y, currDist, row, col, dist, maze, distance);
	}
	
	void checkMove(int x, int y, int currDist, int row, int col, int dist,
	               vector<vector<int>> &maze, vector<vector<int>> &distance) {
		if (row != x or col != y) {
			if (currDist + dist < distance[row][col]) {
				distance[row][col] = min(distance[row][col], currDist + dist);
				mazeWalker(maze, distance, row, col, distance[row][col]);
			}
		}
	}
};

int main() {
	Solution solution;
	vector<vector<int>> maze = {{0, 0, 1, 0, 0},
	                            {0, 0, 0, 0, 0},
	                            {0, 0, 0, 1, 0},
	                            {1, 1, 0, 1, 1},
	                            {0, 0, 0, 0, 0}};
	vector<int> start = {0, 4};
	vector<int> destination = {4, 4};
	auto result = solution.shortestDistance(maze, start, destination);
	PrintSingleResult(result);
	
	maze = {{0, 0, 1, 0, 0},
	        {0, 0, 0, 0, 0},
	        {0, 0, 0, 1, 0},
	        {1, 1, 0, 1, 1},
	        {0, 0, 0, 0, 0}};
	start = {0, 4};
	destination = {3, 2};
	result = solution.shortestDistance(maze, start, destination);
	PrintSingleResult(result);
	
	maze = {{0, 0, 0, 0, 0},
	        {1, 1, 0, 0, 1},
	        {0, 0, 0, 0, 0},
	        {0, 1, 0, 0, 1},
	        {0, 1, 0, 0, 0}}, start = {4, 3}, destination = {0, 1};
	result = solution.shortestDistance(maze, start, destination);
	PrintSingleResult(result);
	
	Complete();
}