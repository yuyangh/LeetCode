#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (44.61%)
 * Likes:    4376
 * Dislikes: 80
 * Total Accepted:    342.4K
 * Total Submissions: 766.9K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 *
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 *
 * Example:
 *
 *
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 *
 * case: empty
 * input: []
 * output: 0
 *
 * case: one trap
 * input:[0,1,0,0,0,0,1]
 * output: 4
 *
 *
 */
class Solution {
public:
	/* two pointers solution
	 * trapped water are limited by the lower side
	 * so if the other side is higher than current side
	 * then we can ensure that current water can be trapped
	 *
	 * runtime: O(n)
	 * space: O(1)
	 */
	int trap(vector<int> &height) {
		if (height.empty()) {
			return 0;
		}
		int water=0;
		int maxLeft = 0, maxRight = 0;
		int leftPos = 0, rightPos = static_cast<int>(height.size()) - 1;
		
		while (leftPos < rightPos) {
			if (height[leftPos]<height[rightPos]) {
				// we can trap more water from the left side
				if(height[leftPos]>maxLeft){
					// it is a higher bar
					maxLeft=height[leftPos];
				}else{
					// the bar is lower, there can be water trapped
					water+=maxLeft-height[leftPos];
					
				}
				leftPos++;
			}else{
				if(height[rightPos]>maxRight){
					maxRight=height[rightPos];
				}else{
					water+=maxRight-height[rightPos];
				}
				rightPos--;
			}
		}
		return water;
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
		
		int ret = Solution().trap(height);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}