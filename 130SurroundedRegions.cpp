#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (22.95%)
 * Likes:    779
 * Dislikes: 429
 * Total Accepted:    148.6K
 * Total Submissions: 642.8K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 *
 * Example:
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 *
 *
 * After running your function, the board should be:
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *
 *
 * Explanation:
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 *
 */

/*
 * Time complexity: O(n*n)
 * first find edge points that can be selected
 * then discover connected regions
 */
class Solution {
public:
	void solve(vector<vector<char>> &board) {
		if (board.empty()) {
			return;
		}
		findUnchangedPoints(board);
		explore(board);
		swapPoints(board);
	}

private:
	queue<pair<int, int>> pointsUnchanged;
	
	void findUnchangedPoints(vector<vector<char>> &board) {
		// find points that won't be changed
		// replace them into 'U' which meanings unchanged
		for (int row = 0; row < board.size(); row++) {
			if (board[row][0] == 'O') {
				board[row][0] = 'U';
				pointsUnchanged.emplace(row, 0);
			}
			if (board[row][board[0].size() - 1] == 'O') {
				board[row][board[0].size() - 1] = 'U';
				pointsUnchanged.emplace(row, board[0].size() - 1);
			}
		}
		for (int col = 0; col < board[0].size(); ++col) {
			if (board[0][col] == 'O') {
				board[0][col] = 'U';
				pointsUnchanged.emplace(0, col);
			}
			if (board[board.size() - 1][col] == 'O') {
				board[board.size() - 1][col] = 'U';
				pointsUnchanged.emplace(board.size() - 1, col);
			}
		}
	}
	
	void explore(vector<vector<char>> &board) {
		// do DFS on points will not change
		while (!pointsUnchanged.empty()) {
			auto point = pointsUnchanged.front();
			pointsUnchanged.pop();
			
			int row = point.first, col = point.second;
			
			if (row - 1 >= 0 && board[row - 1][col] == 'O') {
				board[row - 1][col] = 'U';
				pointsUnchanged.emplace(row - 1, col);
			}
			if (row + 1 < board.size() && board[row + 1][col] == 'O') {
				board[row + 1][col] = 'U';
				pointsUnchanged.emplace(row + 1, col);
			}
			if (col - 1 >= 0 && board[row][col - 1] == 'O') {
				board[row][col - 1] = 'U';
				pointsUnchanged.emplace(row, col - 1);
			}
			if (col + 1 < board[0].size() && board[row][col + 1] == 'O') {
				board[row][col + 1] = 'U';
				pointsUnchanged.emplace(row, col + 1);
			}
		}
	}
	
	void swapPoints(vector<vector<char>> &board) {
		// swap remaining 'O' points into 'X'
		for (auto &row : board) {
			for (auto &point : row) {
				if (point == 'O') {
					point = 'X';
				}
			}
		}
		// swap 'U' points into 'O'
		for (auto &row : board) {
			for (auto &point : row) {
				if (point == 'U') {
					point = 'O';
				}
			}
		}
	}
	
	inline unsigned long long generatePos(int row, int col) {
		return static_cast<unsigned long long>(row) << 32 | col;
	}
	
	inline pair<int, int> getPos(unsigned long long key) {
		int first = key >> 32;
		int second = key & (~0);
		return make_pair(first, second);
	}
};

int main() {
	vector<vector<char>> matrix = {{'X', 'X', 'X'},
	                               {'X', 'O', 'X'},
	                               {'O', 'X', 'X'}};
	Solution solution;
	solution.solve(matrix);
	PrintVectorVector(matrix);
	
}
