//
// Created by Yuyang Huang on 8/23/21.
//

/*
 * 1428. Leftmost Column with at Least a One
 * Medium
 *
 * (This problem is an interactive problem.)
 * A row-sorted binary matrix means that all elements are 0 or 1
 * and each row of the matrix is sorted in non-decreasing order.
 *
 * Given a row-sorted binary matrix binaryMatrix,
 * return the index (0-indexed) of the leftmost column with a 1 in it.
 * If such an index does not exist, return -1.
 *
 * You can't access the Binary Matrix directly. You may only access the matrix using a BinaryMatrix interface:
 * BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
 * BinaryMatrix.dimensions() returns the dimensions of the matrix as a list of 2 elements [rows, cols],
 * which means the matrix is rows x cols.
 * Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.
 * Also, any solutions that attempt to circumvent the judge will result in disqualification.
 * For custom testing purposes, the input will be the entire binary matrix mat.
 * You will not have access to the binary matrix directly.
 *
 * Example 1:
 * Input: mat = [[0,0],[1,1]]
 * Output: 0
 *
 * Example 2:
 * Input: mat = [[0,0],[0,1]]
 * Output: 1
 *
 * Example 3:
 * Input: mat = [[0,0],[0,0]]
 * Output: -1
 *
 * Example 4:
 * Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
 * Output: 1
 *
 * Constraints:
 * rows == mat.length
 * cols == mat[i].length
 * 1 <= rows, cols <= 100
 * mat[i][j] is either 0 or 1.
 * mat[i] is sorted in non-decreasing order.
 */

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

#include "LeetCodeLib.h"

class BinaryMatrix {
public:
	int get(int row, int col);
	
	vector<int> dimensions();
};

class Solution {
public:
	/*
	 * Time complexity: O(m+n)
	 * Go from top right to left bottom
	 * if there is a 1 goes left, 0 goes down
	 *
	 * alternative is binary search
	 */
	int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
		auto dim = binaryMatrix.dimensions();
		int rowLimit = dim[0], colLimit = dim[1];
		int row = 0, col = colLimit - 1;
		
		while (row < rowLimit && col >= 0) {
			bool isOne = binaryMatrix.get(row, col);
			if (isOne) {
				col--;
			} else {
				row++;
			}
		}
		
		// all zero case
		if (col == colLimit-1 && row == rowLimit) {
			return -1;
		}
		return col + 1;
	}
};