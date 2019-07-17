#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (53.24%)
 * Likes:    1784
 * Dislikes: 151
 * Total Accepted:    403.7K
 * Total Submissions: 757.9K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 *
 * Example 1:
 *
 *
 * Input: [3,2,3]
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 *
 *
 */
class Solution {
public:
	/*
	 * we maintain a count,
	 * which is incremented whenever we see an instance
	 * of our current candidate for majority element and
	 * decremented whenever we see anything else.
	 * Whenever count equals 0, we effectively forget about
	 * everything in nums up to the current index and
	 * consider the current number as the candidate for majority element.
	 *
	 * it is because majority element
	 * must exists more than all other element
	 */
	int majorityElement(vector<int> &nums) {
		int count = 0;
		int number = 0;
		for (const auto &num : nums) {
			// modify the count
			if (count > 0) {
				if (number == num) {
					++count;
				} else {
					--count;
				}
			} else {
				count = 1;
				number = num;
			}
			// if exists over size()/2, then it is the majority element
			if (2 * count >= nums.size()) {
				return number;
			}
		}
		return number;
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
		
		int ret = Solution().majorityElement(nums);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}
