//
// Created by Yuyang Huang on 6/18/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (34.74%)
 * Likes:    933
 * Dislikes: 173
 * Total Accepted:    110.9K
 * Total Submissions: 293.7K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n' +
  '[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle
 * defined by its upper left corner (row1, col1) and lower right corner (row2,
 * col2).
 *
 *
 *
 * The above rectangle (with the red border) is defined by (row1, col1) = (2,
 * 1) and (row2, col2) = (4, 3), which contains sum = 8.
 *
 *
 * Example:
 *
 * Given matrix = [
 * ⁠ [3, 0, 1, 4, 2],
 * ⁠ [5, 6, 3, 2, 1],
 * ⁠ [1, 2, 0, 1, 5],
 * ⁠ [4, 1, 0, 1, 7],
 * ⁠ [1, 0, 3, 0, 5]
 * ]
 *
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 *
 *
 *
 * Note:
 *
 * You may assume that the matrix does not change.
 * There are many calls to sumRegion function.
 * You may assume that row1 ≤ row2 and col1 ≤ col2.
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(1)
 * Space complexity:O(n*n)
 * use prefix sum: Sum(ABCD)=Sum(OD)−Sum(OB)−Sum(OC)+Sum(OA)
 */
class NumMatrix {
public:
	NumMatrix(vector<vector<int>> &matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return;
		}
		
		// add a layer of padding
		cumulativeSum = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1));
		
		for (int row = 1; row < matrix.size() + 1; ++row) {
			for (int col = 1; col < matrix[0].size() + 1; ++col) {
				cumulativeSum[row][col] = matrix[row - 1][col - 1] +
				                          cumulativeSum[row - 1][col] +
				                          cumulativeSum[row][col - 1] -
				                          cumulativeSum[row - 1][col - 1];
			}
		}
	}
	
	int sumRegion(int row1, int col1, int row2, int col2) {
		return cumulativeSum[row2 + 1][col2 + 1] - cumulativeSum[row1][col2 + 1] - cumulativeSum[row2 + 1][col1] +
		       cumulativeSum[row1][col1];
	}

private:
	vector<vector<int>> cumulativeSum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

int main() {
	vector<vector<int>> matrix = {
			{3, 0, 1, 4, 2},
			{5, 6, 3, 2, 1},
			{1, 2, 0, 1, 5},
			{4, 1, 0, 1, 7},
			{1, 0, 3, 0, 5}
	};
	NumMatrix numMatrix(matrix);
	
	PrintSingleResult(numMatrix.sumRegion(2, 1, 4, 3));
	PrintSingleResult(numMatrix.sumRegion(1, 1, 2, 2));
	PrintSingleResult(numMatrix.sumRegion(1, 2, 2, 4));
	
	vector<vector<int>> matrix2 = {{}};
	NumMatrix numMatrix2(matrix2);
	
	Complete();
}