//
// Created by Yuyang Huang on 10/21/19.
//

#include "LeetCodeLib.h"

/*
 * Design a Tic-tac-toe game that is played between two players on a n x n grid.
 * You may assume the following rules:
 * A move is guaranteed to be valid and is placed on an empty block.
 * Once a winning condition is reached, no more moves is allowed.
 * A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
 * Follow up:
 * Could you do better than O(n2) per move() operation?
 */

class TicTacToe {
public:
	/** Initialize your data structure here.
	 * since win iff a col/row/diagonal full of one player's chess
	 * so use count to check
	 *
	 * */
	vector<int> rowCount;
	vector<int> colCount;
	int diagUp = 0;
	int diagDown = 0;
	int size;
	
	TicTacToe(int n) {
		rowCount = vector<int>(n, 0);
		colCount = vector<int>(n, 0);
		size = n;
	}
	
	/** Player {player} makes a move at ({row}, {col}).
		@param row The row of the board.
		@param col The column of the board.
		@param player The player, can be either 1 or 2.
		@return The current winning condition, can be either:
				0: No one wins.
				1: Player 1 wins.
				2: Player 2 wins. */
	int move(int row, int col, int player) {
		rowCount[row] += updateScore(player);
		if (rowCount[row] == size) {
			return 1;
		}
		if (rowCount[row] == -size) {
			return 2;
		}
		
		colCount[col] += updateScore(player);
		if (colCount[col] == size) {
			return 1;
		}
		if (colCount[col] == -size) {
			return 2;
		}
		
		if (row == col) {
			diagUp += updateScore(player);
		}
		if (row + col + 1 == size) {
			diagDown += updateScore(player);
		}
		
		if (diagUp == size || diagDown == size) {
			return 1;
		}
		if (diagUp == -size || diagDown == -size) {
			return 2;
		}
		return 0;
		
	}
	
	int updateScore(int player) {
		if (player == 1) {
			return 1;
		} else {
			return -1;
		}
	}
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */