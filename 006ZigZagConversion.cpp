#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (31.99%)
 * Likes:    1085
 * Dislikes: 3358
 * Total Accepted:    333.1K
 * Total Submissions: 1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string s, int numRows);
 *
 * Example 1:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 *
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 */
class Solution {
public:
	// pay attention to the patten,
	// how the result formed
	string convert(string s, int numRows) {
		if (s.empty() || numRows <= 1 || numRows >= s.size()) {
			return s;
		}
		// space for each line
		vector<string> data(numRows, "");
		
		int index = 0;
		while (index < s.size()) {
			// go from top to bottom
			for (int row = 0; row < numRows; ++row) {
				if (index < s.size()) {
					data[row] += s[index];
					++index;
				} else {
					break;
				}
			}
			// go from bottom to top
			for (int row = numRows - 2; row > 0; --row) {
				if (index < s.size()) {
					data[row] += s[index];
					++index;
				} else {
					break;
				}
			}
		}
		
		// append each line into one string
		for (int i = 1; i < numRows; ++i) {
			data[0] += data[i];
		}
		return data[0];
	}
};


string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
				case '\"':
					result.push_back('\"');
					break;
				case '/' :
					result.push_back('/');
					break;
				case '\\':
					result.push_back('\\');
					break;
				case 'b' :
					result.push_back('\b');
					break;
				case 'f' :
					result.push_back('\f');
					break;
				case 'r' :
					result.push_back('\r');
					break;
				case 'n' :
					result.push_back('\n');
					break;
				case 't' :
					result.push_back('\t');
					break;
				default:
					break;
			}
			i++;
		} else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);
		getline(cin, line);
		int numRows = stringToInteger(line);
		
		string ret = Solution().convert(s, numRows);
		
		string out = (ret);
		cout << out << endl;
	}
	return 0;
}

