#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (29.18%)
 * Likes:    764
 * Dislikes: 148
 * Total Accepted:    177.8K
 * Total Submissions: 608.6K
 * Testcase Example:  '1'
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 *
 * For example:
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB
 * ⁠   ...
 *
 *
 * Example 1:
 * Input: 1
 * Output: "A"
 *
 * Example 2:
 * Input: 28
 * Output: "AB"
 *
 * Example 3:
 * Input: 701
 * Output: "ZY"
 */
class Solution {
public:
	string convertToTitle(int n) {
		string result;
		// reserve the space
		result.reserve(ceil(log(n) / log(26)));
		while (n > 0) {
			// because excel's range is 1-26
			--n;
			int index = n % 26;
			result += 'A' + index;
			n /= 26;
		}
		reverse(result.begin(), result.end());
		return result;
	}
};


int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int n = stringToInteger(line);
		
		string ret = Solution().convertToTitle(n);
		
		string out = (ret);
		cout << out << endl;
	}
	return 0;
}
