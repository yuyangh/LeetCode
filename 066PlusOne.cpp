#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (41.29%)
 * Likes:    896
 * Dislikes: 1596
 * Total Accepted:    407.3K
 * Total Submissions: 984.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 *
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 *
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 *
 *
 * Example 2:
 *
 *
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 *
 */
class Solution {
public:
	// todo can optimize
	vector<int> plusOne(vector<int> &digits) {
		if (digits.empty()) {
			return {1};
		}
		
		reverse(digits.begin(), digits.end());
		
		bool carry = false;
		++digits[0];
		for (int &digit : digits) {
			int num = digit + carry;
			if (num > 9) {
				carry = num >= 10;
				digit = num % 10;
			} else {
				carry = false;
				digit = num;
			}
			
		}
		if (carry) {
			digits.emplace_back(1);
		}
		reverse(digits.begin(), digits.end());
		return digits;
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

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}
	
	if (length == 0) {
		return "[]";
	}
	
	string result;
	for (int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> digits = stringToIntegerVector(line);
		
		vector<int> ret = Solution().plusOne(digits);
		
		string out = integerVectorToString(ret);
		cout << out << endl;
	}
	return 0;
}
