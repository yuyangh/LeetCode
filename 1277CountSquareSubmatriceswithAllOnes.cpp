//
// Created by Yuyang Huang on 5/21/20.
//

/*
 * Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
 * Example 1:
 * Input: matrix =
 * [[0,1,1,1],
 * [1,1,1,1],
 * [0,1,1,1]]
 * Output: 15
 * Explanation:
 * There are 10 squares of side 1.
 * There are 4 squares of side 2.
 * There is  1 square of side 3.
 * Total number of squares = 10 + 4 + 1 = 15.
 *
 * Example 2:
 * Input: matrix =[
 * [1,0,1],
 * [1,1,0],
 * [1,1,0]]
 * Output: 7
 * Explanation:
 * There are 6 squares of side 1.
 * There is 1 square of side 2.
 * Total number of squares = 6 + 1 = 7.
 * Constraints:
 * 1 <= arr.length <= 300
 * 1 <= arr[0].length <= 300
 * 0 <= arr[i][j] <= 1
 * */

#include "LeetCodeLib.h"

/*
 * 1. dp[i][j] means the size of biggest square with A[i][j] as bottom-right corner.
 * 2. dp[i][j] also means the number of squares with A[i][j] as bottom-right corner.
 */
class Solution {
public:
	int countSquares(vector<vector<int>> &matrix) {
		vector<vector<int>> data(matrix);
		int result = 0;
		for (int row = 0; row < data.size(); ++row) {
			for (int col = 0; col < data[0].size(); ++col) {
				// if current number is 1, it can make a new square iff left, left up, and up are 1
				if (data[row][col] > 0 && row > 0 && col > 0) {
					data[row][col] += min({data[row - 1][col],
					                       data[row][col - 1],
					                       data[row - 1][col - 1]});
				}
				result += data[row][col];
			}
		}
		return result;
	}
};

int main() {
	Solution solution;
	vector<vector<int>> matrix;
	matrix = {
			{0, 1, 1, 1},
			{1, 1, 1, 1},
			{0, 1, 1, 1}
	};
	assert(solution.countSquares(matrix) == 15);
	Complete();
}