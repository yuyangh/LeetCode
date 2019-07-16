#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (43.22%)
 * Likes:    871
 * Dislikes: 320
 * Total Accepted:    243.6K
 * Total Submissions: 560.2K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 *
 *
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without
 * repetition.
 *
 *
 *
 * A partially filled sudoku which is valid.
 *
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * ⁠ ["5","3",".",".","7",".",".",".","."],
 * ⁠ ["6",".",".","1","9","5",".",".","."],
 * ⁠ [".","9","8",".",".",".",".","6","."],
 * ⁠ ["8",".",".",".","6",".",".",".","3"],
 * ⁠ ["4",".",".","8",".","3",".",".","1"],
 * ⁠ ["7",".",".",".","2",".",".",".","6"],
 * ⁠ [".","6",".",".",".",".","2","8","."],
 * ⁠ [".",".",".","4","1","9",".",".","5"],
 * ⁠ [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: true
 *
 *
 * Example 2:
 * Input:
 * [
 * ["8","3",".",".","7",".",".",".","."],
 * ["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being
 * ⁠   modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 *
 *
 * Note:
 *
 *
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 * The given board contain only digits 1-9 and the character '.'.
 * The given board size is always 9x9.
 *
 *
 */
class Solution {
public:
	bool isValidSudoku(vector<vector<char>> &board) {
		// in default, all cells are false
		vector<bool> cell(10, false);
		vector<vector<bool>> sudokuRow(board.size(), cell);
		for (int i = 0; i < board.size(); ++i) {
			board.emplace_back(sudokuRow);
		}
		
		// check rows
		for (int row = 0; row < board.size(); row++) {
			vector<bool> available(10, true);
			for (int col = 0; col < board[0].size(); ++col) {
				// for number case
				if (board[row][col] != '.') {
					status[row][col][digit(board, row, col)] = true;
					// check duplicates
					if (!available[digit(board, row, col)]) {
						return false;
					} else {
						available[digit(board, row, col)] = false;
					}
				}
			}
			// update blanks to be available
			for (int col = 0; col < board[0].size(); ++col) {
				if (board[row][col] == '.') {
					status[row][col] = available;
				}
			}
		}
		
		for (int col = 0; col < board[0].size(); ++col) {
			vector<bool> available(10, true);
			for (int row = 0; row < board.size(); ++row) {
				if (board[row][col] != '.') {
					// check duplicate
					if (!available[digit(board, row, col)]) {
						return false;
					} else {
						available[digit(board, row, col)] = false;
					}
					
				}
			}
			for (int row = 0; row < board.size(); ++row) {
				if (board[row][col] == '.') {
					for (int i = 0; i < available.size(); i++) {
						status[row][col][digit(board, row, col)] =
								status[row][col][digit(board, row, col)] & available[i];
					}
				}
			}
		}
		
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
			
			}
		}
		
	}
	
	inline int digit(vector<vector<char>> &board, int row, int col) {
		return board[row][col] - '0';
		
	}

private:
	vector<vector<vector<bool>>> status;
};

