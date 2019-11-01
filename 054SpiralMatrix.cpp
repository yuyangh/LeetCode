#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (30.54%)
 * Likes:    1146
 * Dislikes: 420
 * Total Accepted:    242K
 * Total Submissions: 788.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 *
 * Example 1:
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 *
 *
 * Example 2:
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 */
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>> &matrix) {
		if (matrix.empty()) {
			return vector<int>();
		}
		height_lower_ = 0, width_lower_ = 0;
		height_upper_ = matrix.size();
		width_upper_ = matrix[0].size();
		// initial direction, going to the right
		direction = RIGHT;
		walk(matrix, 0, 0);
		return result;
	}

private:
	enum Direction {
		UP, DOWN, LEFT, RIGHT
	};
	int height_upper_, width_upper_;
	int height_lower_, width_lower_;
	Direction direction;
	vector<int> result;
	
	
	void walk(vector<vector<int>> &matrix, int row, int col) {
		bool able;
		do {
			result.emplace_back(matrix[row][col]);
			
			// only update bound and change direction at corner
			if (direction == RIGHT && col + 1 >= width_upper_) {
				// since we change direction from going right to going down,
				// the lower bound for height is increased
				direction = DOWN;
				++height_lower_;
			}
			if (direction == DOWN && row + 1 >= height_upper_) {
				direction = LEFT;
				--width_upper_;
			}
			if (direction == UP && row - 1 < height_lower_) {
				direction = RIGHT;
				++width_lower_;
			}
			if (direction == LEFT && col - 1 < width_lower_) {
				direction = UP;
				--height_upper_;
			}
			// decide whether can go next
			able = (width_lower_ < width_upper_) && (height_lower_ < height_upper_);
			// based on direction to update position
			switch (direction) {
				case DOWN: {
					++row;
					break;
				}
				case UP: {
					--row;
					break;
				}
				case RIGHT: {
					++col;
					break;
				}
				case LEFT: {
					--col;
					break;
				}
				default:
					printf("Error\n");
			}
		} while (able);
	}
};

int main() {
	int length = 5;
	vector<vector<int>> matrix(length, vector<int>(length, 0));
	
	for (int row = 0; row < length; ++row) {
		for (int col = 0; col < length; ++col) {
			matrix[row][col] = row * length + col + 1;
		}
	}
	cout << "original:" << endl;
	PrintVectorVector(matrix);
	Solution solution;
	auto result = solution.spiralOrder(matrix);
	cout << "transformed:" << endl;
	PrintVector(result);
}
