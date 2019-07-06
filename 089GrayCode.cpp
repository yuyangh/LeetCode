#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 *
 * https://leetcode.com/problems/gray-code/description/
 *
 * algorithms
 * Medium (45.85%)
 * Likes:    400
 * Dislikes: 1215
 * Total Accepted:    136.7K
 * Total Submissions: 296.8K
 * Testcase Example:  '2'
 *
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit.
 *
 * Given a non-negative integer n representing the total number of bits in the
 * code, print the sequence of gray code. A gray code sequence must begin with
 * 0.
 *
 * Example 1:
 *
 *
 * Input: 2
 * Output: [0,1,3,2]
 * Explanation:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 *
 * For a given n, a gray code sequence may not be uniquely defined.
 * For example, [0,2,3,1] is also a valid gray code sequence.
 *
 * 00 - 0
 * 10 - 2
 * 11 - 3
 * 01 - 1
 *
 *
 * Example 2:
 * Input: 0
 * Output: [0]
 * Explanation: We define the gray code sequence to begin with 0.
 * A gray code sequence of n has size = 2^n, which for n = 0 the size is 2^0 =
 * 1.
 * Therefore, for n = 0 the gray code sequence is [0].
 *
 *
 */
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> result = {0};
		if (n == 0) {
			return result;
		}
		result.reserve(static_cast<size_t>(pow(2, n)));
		for (int i = 0; i < n; ++i) {
			int size = result.size();
			// reversely copy down previous value + 2^i
			for (int line = size - 1; line >= 0; --line) {
				result.emplace_back(result[line] + pow(2, i));
			}
		}
		return result;
	}
};


int stringToInteger(string input) {
	return stoi(input);
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
		int n = stringToInteger(line);
		
		vector<int> ret = Solution().grayCode(n);
		
		string out = integerVectorToString(ret);
		cout << out << endl;
	}
	return 0;
}