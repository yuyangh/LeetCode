#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (44.77%)
 * Likes:    3411
 * Dislikes: 448
 * Total Accepted:    389.5K
 * Total Submissions: 863.5K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49.
 *
 *
 * Example:
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 *
 */
class Solution {
public:
	// Two pointers apprach
	// the area formed between the lines will always be
	// limited by the height of the shorter line.
	// Further, the farther the lines, the more will be the area obtained
	int maxArea(vector<int> &height) {
		if (height.empty()) {
			return 0;
		}
		int left = 0, right = height.size() - 1;
		int maxArea = 0;
		int area;
		while (left <= right) {
			area = getArea(height, left, right);
			if (area > maxArea) {
				maxArea = area;
			}
			// moving lower one to the higher one would get larger area
			if (height[left] > height[right]) {
				--right;
			} else {
				++left;
			}
			if (left >= height.size() || right < 0) {
				break;
			}
		}
		return maxArea;
	}
	
	int getArea(vector<int> &height, int left, int right) {
		return (right - left) * (min(height[left], height[right]));
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
		vector<int> height = stringToIntegerVector(line);
		
		int ret = Solution().maxArea(height);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}