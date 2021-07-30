//
// Created by Yuyang Huang on 7/29/21.
//

/*
 * 542. 01 Matrix
 *
 * Medium
 *
 * Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
 * The distance between two adjacent cells is 1.
 *
 * Example 1:
 * Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: [[0,0,0],[0,1,0],[0,0,0]]
 *
 * Example 2:
 * Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
 * Output: [[0,0,0],[0,1,0],[1,2,1]]
 *
 * Constraints:
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 104
 * 1 <= m * n <= 104
 * mat[i][j] is either 0 or 1.
 * There is at least one 0 in mat.
 */

#include "LeetCodeLib.h"

/*
 * Time complexity: O(mn)
 * use bfs to identify shortest distance to nearest 0
 */
class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
		vector<vector<int>> distance(mat.size(), vector<int>(mat.front().size(), INT_MAX));
		
		queue<vector<int>> points;
		for (int row = 0; row < mat.size(); ++row) {
			for (int col = 0; col < mat.front().size(); ++col) {
				if (mat[row][col] == 0) {
					distance[row][col]=0;
					points.push({row, col, 0});
				}
			}
		}
		
		while (!points.empty()) {
			auto point = points.front();
			points.pop();
			int x = point[0], y = point[1], dist = point[2];
			distance[x][y] = min(dist, distance[x][y]);
			
			if (isValid(x - 1, y, mat.size(), mat.front().size()) && distance[x - 1][y] ==INT_MAX) {
				points.push({x - 1, y, dist + 1});
			}
			if (isValid(x + 1, y, mat.size(), mat.front().size()) && distance[x + 1][y] ==INT_MAX) {
				points.push({x + 1, y, dist + 1});
			}
			if (isValid(x, y - 1, mat.size(), mat.front().size()) && distance[x][y - 1] ==INT_MAX) {
				points.push({x, y - 1, dist + 1});
			}
			if (isValid(x, y + 1, mat.size(), mat.front().size()) && distance[x][y + 1] ==INT_MAX) {
				points.push({x, y + 1, dist + 1});
			}
		}
		return distance;
	}
	
	static bool isValid(int row, int col, int rowLimit, int colLimit) {
		return row >= 0 && col >= 0 && row < rowLimit && col < colLimit;
	}
};

int main() {
	Solution solution;
	vector<vector<int>> mat;
	mat = {{0, 1, 0},
	       {0, 1, 0},
	       {0, 1, 0}};
	PrintVectorVector(solution.updateMatrix(mat));
	
	mat = {{0, 0, 0},
	       {0, 1, 0},
	       {0, 0, 0}};
	PrintVectorVector(solution.updateMatrix(mat));
	
	mat = {{0, 0, 0},
	       {0, 1, 0},
	       {1, 1, 1}};
	PrintVectorVector(solution.updateMatrix(mat));
}