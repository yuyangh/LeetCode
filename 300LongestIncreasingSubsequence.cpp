#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (40.76%)
 * Likes:    2498
 * Dislikes: 57
 * Total Accepted:    223.5K
 * Total Submissions: 547.3K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 *
 * Example:
 *
 *
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4.
 *
 * Note:
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 *
 *
 * Follow up: Could you improve it to O(n log n) time complexity?
 *
 */
class Solution {
public:
	// iteritive solution
	int lengthOfLIS(vector<int> &nums) {
		if (nums.empty()) {
			return 0;
		}
		
		// fills the array from bottom right
		vector<vector<int>> data(nums.size() + 1, vector<int>(nums.size() + 1, 1));
		for (int row = nums.size() - 1; row >= 0; row--) {
			for (int col = nums.size() - 1; col >= row; col--) {
				if (nums[col] > nums[row]) {
					data[row][col] = max(data[col][col + 1] + 1, data[row][col + 1]);
				} else {
					data[row][col] = data[row][col + 1];
				}
			}
		}
		int maxLength = INT_MIN;
		// each substring starts from diagonal position
		for (int i = 0; i < data.size(); i++) {
			maxLength = max(data[i][i], maxLength);
		}
		
		return maxLength;
	}
	
	// recursion method
	int lengthOfLISRec(vector<int> &nums) {
		if (nums.empty()) {
			return 0;
		}
		int ans = INT_MIN;
		// Do LIS at each index
		for (int i = 0; i < nums.size(); i++) {
			ans = max(ans, LIS(i, i, nums) + 1);
		}
		return ans;
	}
	
	// there are 2 parameter in recursion, so we can use memorization with 2D array
	int LIS(int currIdx, int maxIdx, vector<int> &nums) {
		if (currIdx >= nums.size()) {
			return 0;
		} else {
			if (nums[currIdx] > nums[maxIdx]) {
				return max(LIS(currIdx + 1, currIdx, nums) + 1,
				           LIS(currIdx + 1, maxIdx, nums));
			} else {
				return LIS(currIdx + 1, maxIdx, nums);
			}
		}
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
		vector<int> nums = stringToIntegerVector(line);
		
		int ret = Solution().lengthOfLIS(nums);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}
