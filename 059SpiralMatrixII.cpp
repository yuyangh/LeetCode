#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (46.74%)
 * Likes:    467
 * Dislikes: 81
 * Total Accepted:    139.6K
 * Total Submissions: 296.6K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n^2 in spiral order.
 *
 * Example:
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 */
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		if (n == 0) {
			return vector<vector<int>>();
		}
		vector<vector<int>> result(n, vector<int>(n, 0));
		num_ = 1;
		// boundary for spiraling
		width_lower_ = 0, height_lower_ = 0;
		width_upper_ = n, height_upper_ = n;
		direction = RIGHT;
		
		int row = 0, col = 0;
		bool able;
		do {
			result[row][col] = num_;
			++num_;
			// update direction at corner
			if (direction == RIGHT && col + 1 >= width_upper_) {
				direction = DOWN;
				++height_lower_;
			}
			if (direction == DOWN && row + 1 >= height_upper_) {
				direction = LEFT;
				--width_upper_;
			}
			if (direction == LEFT && col - 1 < width_lower_) {
				direction = UP;
				--height_upper_;
			}
			if (direction == UP && row - 1 < height_lower_) {
				direction = RIGHT;
				++width_lower_;
			}
			able = (width_lower_ < width_upper_) && (height_lower_ < height_upper_);
			switch (direction) {
				case RIGHT: {
					++col;
					break;
				}
				case DOWN: {
					++row;
					break;
				}
				case LEFT: {
					--col;
					break;
				}
				case UP: {
					--row;
					break;
				}
			}
			
		} while (able);
		return result;
	}

private:
	enum Direction {
		UP, DOWN, RIGHT, LEFT
	};
	int num_;
	Direction direction;
	int width_lower_, width_upper_, height_lower_, height_upper_;
};

int main() {
	int size = 5;
	Solution solution;
	auto result = solution.generateMatrix(size);
	PrintVectorVector(result);
	return 0;
}

