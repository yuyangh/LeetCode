#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (40.62%)
 * Likes:    802
 * Dislikes: 6190
 * Total Accepted:    291.1K
 * Total Submissions: 712.6K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 *
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence.
 *
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 *
 * Example 1:
 * Input: 1
 * Output: "1"
 *
 * Example 2:
 * Input: 4
 * Output: "1211"
 */
class Solution {
public:
	string countAndSay(int n) {
		int level = 1;
		string prevNumsString = "1";
		for (; level < n; ++level) {
			string currNumsString;
			int num;
			int prevNum = -1;
			int count = 0;
			for (char index : prevNumsString) {
				num = index - '0';
				// accumulate the count
				if (num == prevNum) {
					++count;
				} else {
					// record down
					if (prevNum != -1) {
						currNumsString += (count + '0');
						currNumsString += (prevNum + '0');
					}
					count = 1;
				}
				prevNum = num;
			}
			// end of the string
			if (prevNum != -1) {
				currNumsString += (count + '0');
				currNumsString += (prevNum + '0');
			}
			// update NumsString
			prevNumsString = currNumsString;
		}
		return prevNumsString;
	}
};


int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int n = stringToInteger(line);
		
		string ret = Solution().countAndSay(n);
		
		string out = (ret);
		cout << out << endl;
	}
	return 0;
}