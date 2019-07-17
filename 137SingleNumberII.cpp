#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (46.39%)
 * Likes:    871
 * Dislikes: 261
 * Total Accepted:    171.8K
 * Total Submissions: 370.2K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given a non-empty array of integers, every element appears three times
 * except for one, which appears exactly once. Find that single one.
 *
 * Note:
 *
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 *
 * Example 1:
 *
 *
 * Input: [2,2,3,2]
 * Output: 3
 *
 *
 * Example 2:
 *
 *
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 *
 */
class Solution {
public:
	/*
	 * every time there is an XOR,
	 * the number will be either remembered or forgotten
	 */
	int singleNumber(vector<int> &nums) {
		int a = 0, b = 0;
		for (int num : nums) {
			/*
			 *                      a  b
			 *  initial state   :   0   0
			 *  1st time see x  :   0   x   (record x into b)
			 *  2nd time see x  :   x   0   (record x into a)
			 *  3rd time see x  :   0   0   (clear)
			 */
			b = (b ^ num) & ~a;
			a = (a ^ num) & ~b;
		}
		return b;
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
		
		int ret = Solution().singleNumber(nums);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}