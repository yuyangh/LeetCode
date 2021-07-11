//
// Created by Yuyang Huang on 7/11/21.
//

/*
 * 576. Out of Boundary Paths
 * Medium
 * There is an m x n grid with a ball.
 * The ball is initially at the position [startRow, startColumn].
 * You are allowed to move the ball to one of the four adjacent cells in the grid
 * (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
 *
 * Given the five integers m, n, maxMove, startRow, startColumn,
 * return the number of paths to move the ball out of the grid boundary.
 * Since the answer can be very large, return it modulo 10^9 + 7.
 *
 * Example 1:
 * Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
 * Output: 6
 *
 * Example 2:
 * Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
 * Output: 12
 *
 * Constraints:
 * 1 <= m, n <= 50
 * 0 <= maxMove <= 50
 * 0 <= startRow < m
 * 0 <= startColumn < n
 */
#include "LeetCodeLib.h"

class Solution {
public:
	int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
		unsigned long mod = 1e9 + 7;
		
		// number of exits for each point
		vector<vector<unsigned long>> numExits(m, vector<unsigned long>(n));
		for (int row = 0; row < m; ++row) {
			for (int col = 0; col < n; ++col) {
				if (row - 1 < 0) {
					numExits[row][col]++;
				}
				if (row + 1 >= m) {
					numExits[row][col]++;
				}
				if (col - 1 < 0) {
					numExits[row][col]++;
				}
				if (col + 1 >= n) {
					numExits[row][col]++;
				}
			}
		}
		
		// memorize number of total ways
		vector<vector<vector<unsigned long>>> dp(maxMove + 1,
		                                         vector<vector<unsigned long>>(m, vector<unsigned long>(n, 0)));
		for (int move = 1; move <= maxMove; ++move) {
			for (int row = 0; row < m; ++row) {
				for (int col = 0; col < n; ++col) {
					unsigned long numComing = 0;
					if (row - 1 >= 0) {
						numComing += dp[move - 1][row - 1][col];
					}
					if (row + 1 < m) {
						numComing += dp[move - 1][row + 1][col];
					}
					if (col - 1 >= 0) {
						numComing += dp[move - 1][row][col - 1];
					}
					if (col + 1 < n) {
						numComing += dp[move - 1][row][col + 1];
					}
					// recurrence formula
					dp[move][row][col] = (numExits[row][col] + numComing) % mod;
				}
			}
		}
		
		
		return dp[maxMove][startRow][startColumn] % mod;
	}
};

int main() {
	Solution solution;
	
	int m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0;
	PrintSingleResult(solution.findPaths(m, n, maxMove, startRow, startColumn));
	
	m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1;
	PrintSingleResult(solution.findPaths(m, n, maxMove, startRow, startColumn));
	
	m = 8, n = 50, maxMove = 23, startRow = 5, startColumn = 26;
	PrintSingleResult(solution.findPaths(m, n, maxMove, startRow, startColumn));
}