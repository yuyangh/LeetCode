#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (41.71%)
 * Likes:    2218
 * Dislikes: 298
 * Total Accepted:    397K
 * Total Submissions: 950.5K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 *
 * Example:
 *
 *
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 *
 */
class Solution {
public:
	// number to char O(1) conversion
	vector<vector<char>> digitLetterMap = {{},
	                                       {},
	                                       {'a', 'b', 'c'},
	                                       {'d', 'e', 'f'},
	                                       {'g', 'h', 'i'},
	                                       {'j', 'k', 'l'},
	                                       {'m', 'n', 'o'},
	                                       {'p', 'q', 'r', 's'},
	                                       {'t', 'u', 'v'},
	                                       {'w', 'x', 'y', 'z'}};
	vector<string> result;
	
	vector<string> letterCombinations(string digits) {
		if (digits.empty()) {
			return result;
		}
		result.reserve(static_cast<unsigned int>(pow(digits.size(), 3)));
		string buffer;
		combine(0, buffer, digits);
		return result;
	}
	
	void combine(int pos, string &str, string &digits) {
		if (pos == digits.size()) {
			result.emplace_back(str);
			return;
		}
		int num = digits[pos] - '0';
		// append each possible char with backtracking
		for (int i = 0; i < digitLetterMap[num].size(); i++) {
			str += digitLetterMap[num][i];
			combine(pos + 1, str, digits);
			str.pop_back();
		}
	}
};

int main() {
	string digits = "89245";
	Solution solution;
	auto result = solution.letterCombinations(digits);
	cout << "result is:" << endl;
	for (const auto &item : result) {
		cout << item << endl;
	}
}
