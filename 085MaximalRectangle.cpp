#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (33.82%)
 * Likes:    1563
 * Dislikes: 52
 * Total Accepted:    127.6K
 * Total Submissions: 376.2K
 * Testcase Example:  '[{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 *
 * Example:
 *
 *
 * Input:
 * [
 * ⁠ {"1","0","1","0","0"},
 * ⁠ {"1","0","1","1","1"},
 * ⁠ {"1","1","1","1","1"},
 * ⁠ {"1","0","0","1","0"}
 * ]
 * Output: 6
 *
 *
 */
class Solution {
public:
	/*
	 * This question is similar as [084 Largest Rectangle in Histogram]:
	 * maintain a row length of Integer array H recorded its height of '1's,
	 * and scan and update row by row to find out the largest rectangle of each row.
	 */
	int maximalRectangle(vector<vector<char>> &matrix) {
		if (matrix.empty()) {
			return 0;
		}
		int width = matrix[0].size();
		
		vector<int> heights(width, 0);
		int max_area = 0;
		
		for (auto &row : matrix) {
			// update available height
			for (int col = 0; col < width; ++col) {
				if (row[col] != '0') {
					++heights[col];
				} else {
					heights[col] = 0;
				}
			}
			
			/*
			 * use dynamic programming to memorize
			 * the left most and right most bound for one number
			 * if the jth element is larger than ith element,
			 * than i's bound must be larger than j's
			 */
			if (heights.size() == 1) {
				max_area = max(heights[0], max_area);
				continue;
			}
			
			vector<int> non_smaller_index_from_left(width, 0);
			vector<int> non_smaller_index_from_right(width, width - 1);
			
			for (int col = 0; col < width; ++col) {
				int left = col - 1;
				while (left >= 0 && heights[left] >= heights[col]) {
					// find the available left bound
					left = non_smaller_index_from_left[left];
					--left;
				}
				left = min(max(0, left + 1), col);
				// memorize the bound
				non_smaller_index_from_left[col] = left;
			}
			
			for (int col = width - 1; col >= 0; --col) {
				int right = col + 1;
				while (right <= width - 1 && heights[right] >= heights[col]) {
					right = non_smaller_index_from_right[right];
					++right;
				}
				right = max(min(width - 1, right - 1), col);
				non_smaller_index_from_right[col] = right;
			}
			
			for (int i = 0; i < heights.size(); ++i) {
				int area = CalculateArea(heights, i,
				                         non_smaller_index_from_left[i],
				                         non_smaller_index_from_right[i]);
				if (area > max_area) {
					max_area = area;
				}
			}
		}
		return max_area;
	}

private:
	int CalculateArea(vector<int> &heights, int index, int left, int right) {
		return heights[index] * (right - left + 1);
	}
};

int main() {
	vector<vector<string>> arr = {{"1", "0", "1", "0", "0"},
	                              {"1", "0", "1", "1", "1"},
	                              {"1", "1", "1", "1", "1"},
	                              {"1", "0", "0", "1", "0"}};
	
	arr = {{"1", "0", "1", "0", "0"},
	       {"0", "1", "1", "1", "1"},
	       {"1", "1", "1", "1", "1"},
	       {"1", "0", "0", "1", "0"}};
	
	vector<vector<char>> input(arr.size());
	for (int row = 0; row < arr.size(); ++row) {
		for (const auto &item : arr[row]) {
			input[row].emplace_back(item[0]);
		}
	}
	
	Solution solution;
	auto result = solution.maximalRectangle(input);
	PrintSingleResult(result);
	
	return 0;
}
