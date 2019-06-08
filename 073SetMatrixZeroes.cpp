#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (39.75%)
 * Likes:    1056
 * Dislikes: 191
 * Total Accepted:    210.7K
 * Total Submissions: 528.3K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output:
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output:
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 *
 *
 * Follow up:
 *
 *
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 */
class Solution {
public:
	/**
	 * O(1) space utilization
	 * @param matrix
	 */
	void setZeroes(vector<vector<int>> &matrix) {
		if (matrix.empty()) {
			return;
		}
		bool firstRowZero = false, firstColZero = false;
		// check 0, if it is,
		// update firstRowZero and firstColZero
		// set matrix[row][0]=0 and matrix[0][col]=0
		for (int row = 0; row < matrix.size(); row++) {
			for (int col = 0; col < matrix[0].size(); col++) {
				if (matrix[row][col] == 0) {
					if (row == 0) {
						firstRowZero = true;
						continue;
					}
					if (col == 0) {
						firstColZero = true;
						continue;
					}
					matrix[row][0] = 0;
					matrix[0][col] = 0;
				}
			}
		}
		
		// update corresponding row to 0
		for (int row = 1; row < matrix.size(); row++) {
			if (matrix[row][0] == 0) {
				for (int col = 0; col < matrix[0].size(); col++) {
					matrix[row][col] = 0;
				}
			}
		}
		
		// update corresponding col to 0
		for (int col = 1; col < matrix[0].size(); col++) {
			if (matrix[0][col] == 0) {
				for (int row = 0; row < matrix.size(); row++) {
					matrix[row][col] = 0;
				}
			}
		}
		if (matrix[0][0] == 0) {
			firstRowZero = true;
			firstColZero = true;
		}
		if (firstRowZero) {
			for (int col = 0; col < matrix[0].size(); col++) {
				matrix[0][col] = 0;
			}
		}
		if (firstColZero) {
			for (int row = 0; row < matrix.size(); row++) {
				matrix[row][0] = 0;
			}
		}
	}
};

