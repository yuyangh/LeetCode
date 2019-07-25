#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (31.25%)
 * Likes:    1982
 * Dislikes: 54
 * Total Accepted:    180.8K
 * Total Submissions: 573.9K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 *
 *
 *
 *
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 *
 *
 *
 *
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 *
 *
 *
 * Example:
 * Input: [2,1,5,6,2,3]
 * Output: 10
 *
 *
 */
class Solution {
public:
	/*
	 * use dynamic programming to memorize
	 * the left most and right most bound for one number
	 * if the jth element is larger than ith element,
	 * than i's bound must be larger than j's
	 */
	int largestRectangleArea(vector<int> &heights) {
		if (heights.empty()) {
			return 0;
		}
		if (heights.size() == 1) {
			return heights[0];
		}
		
		vector<int> non_smaller_index_from_left(heights.size(), 0);
		vector<int> non_smaller_index_from_right(heights.size(), heights.size() - 1);
		
		for (int col = 0; col < heights.size(); ++col) {
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
		
		for (int col = heights.size() - 1; col >= 0; --col) {
			int right = col + 1;
			while (right <= heights.size() - 1 && heights[right] >= heights[col]) {
				right = non_smaller_index_from_right[right];
				++right;
			}
			right = max(min((int) (heights.size() - 1), right - 1), col);
			non_smaller_index_from_right[col] = right;
		}
		
		int max_area = 0;
		for (int i = 0; i < heights.size(); ++i) {
			int area = CalculateArea(heights, i,
			                         non_smaller_index_from_left[i],
			                         non_smaller_index_from_right[i]);
			if (area > max_area) {
				max_area = area;
			}
		}
		
		return max_area;
	}

private:
	int CalculateArea(vector<int> &heights, int index, int left, int right) {
		return heights[index] * (right - left + 1);
	}
};


void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> heights = stringToIntegerVector(line);
		
		int ret = Solution().largestRectangleArea(heights);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}