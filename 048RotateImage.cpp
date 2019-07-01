#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (48.70%)
 * Likes:    1642
 * Dislikes: 154
 * Total Accepted:    261.4K
 * Total Submissions: 532.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Note:
 *
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 *
 * Example 1:
 * Given input matrix =
 * [
 * ⁠ [1,2,3],
 * ⁠ [4,5,6],
 * ⁠ [7,8,9]
 * ],
 *
 * rotate the input matrix in-place such that it becomes:
 * [
 * ⁠ [7,4,1],
 * ⁠ [8,5,2],
 * ⁠ [9,6,3]
 * ]
 *
 *
 * Example 2:
 * Given input matrix =
 * [
 * ⁠ [ 5, 1, 9,11],
 * ⁠ [ 2, 4, 8,10],
 * ⁠ [13, 3, 6, 7],
 * ⁠ [15,14,12,16]
 * ],
 *
 * rotate the input matrix in-place such that it becomes:
 * [
 * ⁠ [15,13, 2, 5],
 * ⁠ [14, 3, 4, 1],
 * ⁠ [12, 6, 8, 9],
 * ⁠ [16, 7,10,11]
 * ]
 *
 *
 */
class Solution {
public:
	void rotate(vector<vector<int>> &matrix) {
		if (matrix.empty()) {
			return;
		}
		size_ = matrix.size();
		int columnLimit = size_;
		int halfSize = ceil(0.5 * size_);
		for (int row = 0; row < halfSize; ++row) {
			for (int col = row; col < size_ - 1 - row; ++col) {
				int x = row, y = col;
				pair<int, int> nextPos;
				int currValue;
				int prevValue = matrix[x][y];
				for (int side = 0; side < 4; ++side) {
					nextPos = rotate(x, y);
					currValue = matrix[nextPos.first][nextPos.second];
					matrix[nextPos.first][nextPos.second] = prevValue;
					x = nextPos.first;
					y = nextPos.second;
					prevValue = currValue;
				}
			}
		}
	}

private:
	int size_;
	
	inline pair<int, int> rotate(int row, int col) {
		return make_pair(col, -row + size_ - 1);
	}
};

int main() {
	int length = 9;
	vector<vector<int>> matrix(length, vector<int>(length, 0));
	
	for (int row = 0; row < length; ++row) {
		for (int col = 0; col < length; ++col) {
			matrix[row][col] = row * length + col + 1;
		}
	}
	cout << "original:" << endl;
	PrintVectorVector(matrix);
	Solution solution;
	solution.rotate(matrix);
	cout << "transformed:" << endl;
	PrintVectorVector(matrix);
}

