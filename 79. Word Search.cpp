#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (31.38%)
 * Likes:    1771
 * Dislikes: 87
 * Total Accepted:    287.1K
 * Total Submissions: 914.2K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 *
 * Example:
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 *
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 */
class Solution {
public:
	/* DFS can do search for exist or not
	 * this is a backtracking problem
	 */
	bool exist(vector<vector<char>> &board, string word) {
		if (board.empty()) {
			return false;
		}
		
		// initialize the visited to be not visited
		visited.reserve(board.size());
		for (int row = 0; row < board.size(); ++row) {
			visited.emplace_back(vector<bool>(board[0].size(), false));
		}
		
		// find word on board by checking on each cell
		for (int row = 0; row < board.size(); ++row) {
			for (int col = 0; col < board[0].size(); ++col) {
				if (exist(board, row, col, 0, word)) {
					return true;
				}
			}
		}
		return false;
	}

private:
	vector<vector<bool>> visited;
	
	bool exist(vector<vector<char>> &board, int row, int col, int wordIndex, string &word) {
		// check for bounds
		if (row < 0 || row >= board.size()) {
			return false;
		}
		if (col < 0 || col >= board[0].size()) {
			return false;
		}
		
		// check for equal and not visited
		if (board[row][col] == word[wordIndex] && !visited[row][col]) {
			if (wordIndex == word.size() - 1) {
				return true;
			}
			// backtracking
			visited[row][col] = true;
			
			// check all directions
			bool up, down, right, left;
			wordIndex++;
			up = exist(board, row - 1, col, wordIndex, word);
			down = exist(board, row + 1, col, wordIndex, word);
			left = exist(board, row, col - 1, wordIndex, word);
			right = exist(board, row, col + 1, wordIndex, word);
			if (up || down || right || left) {
				return true;
			} else {
				// will not visit here
				visited[row][col] = false;
				return false;
			}
		} else {
			return false;
		}
	}
};

int main() {
	vector<vector<char>> data = {{'A', 'B', 'C', 'E'},
	                             {'S', 'F', 'C', 'S'},
	                             {'A', 'D', 'E', 'E'}};
	string word = "ABCCED";
	Solution solution;
	auto result = solution.exist(data, word);
	cout << "result:" << result << endl;
}