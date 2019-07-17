#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (60.68%)
 * Likes:    2609
 * Dislikes: 97
 * Total Accepted:    489K
 * Total Submissions: 805.6K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 *
 * Note:
 *
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 *
 * Example 1:
 *
 *
 * Input: [2,2,1]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: [4,1,2,1,2]
 * Output: 4
 *
 *
 */
class Solution {
public:
	/*
	 * because any number XOR with self will generate 0
	 * so a XOR b XOR a = a XOR a XOR b = b
	 * So we can XOR all bits together to find the unique number.
	 */
	int singleNumber(vector<int> &nums) {
		int number = 0;
		for (const auto &num : nums) {
			number ^= num;
		}
		return number;
	}
	
	/*
	 * use hash set to memorize
	 */
	int singleNumberHash(vector<int> &nums) {
		if (nums.empty()) {
			return 0;
		}
		if (nums.size() <= 1) {
			return nums[0];
		}
		
		unordered_set<int> numbers;
		numbers.reserve(nums.size());
		for (const int num:nums) {
			auto it = numbers.find(num);
			if (it == numbers.end()) {
				numbers.emplace(num);
			} else {
				numbers.erase(it);
			}
		}
		return *nums.begin();
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
