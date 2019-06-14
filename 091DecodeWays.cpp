#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (22.37%)
 * Likes:    1402
 * Dislikes: 1618
 * Total Accepted:    264.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 *
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 *
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 *
 * Example 1:
 *
 *
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 *
 *
 * Example 2:
 *
 *
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 *
 */
class Solution {
public:
	int numDecodings(string s) {
		// iterative
		if (s.empty()) {
			return 0;
		}
		return decode(s);
		
		// recursion
		int sum = 0;
		decode(0, s, sum);
		return sum;
	}
	
	// iterative
	int decode(string &s) {
		vector<int> data(s.size(), 0);
		// base case
		if (s[0] > '0') {
			data[0] = 1;
		}
		for (int i = 1; i < s.size(); i++) {
			int singleNum = s[i] - '0';
			// single digit case
			if (singleNum > 0) {
				data[i] = data[i - 1];
			}
			// check for 0 case
			if(data[i]+data[i-1]==0){
				return 0;
			}
			// two digit case
			int twoNum = singleNum + (s[i - 1] - '0') * 10;
			if (10 <= twoNum && twoNum <= 26) {
				if(i==1){
					data[i]++;
					continue;
				}
				// this is very important
				// it is accumulate all counts that that can sum exactly to this position
				data[i]+=data[i-2];
			}
		}
		return data.back();
	}
	
	// recursion
	void decode(int pos, string &s, int &sum) {
		// base case
		if (pos > s.size()) {
			return;
		}
		
		if (pos < s.size()) {
			// 0 case
			if (s[pos] == '0') {
				return;
			} else {
				// single digit case
				if (pos == s.size() - 1) {
					int num = s[pos] - '0';
					if (num > 0 && num <= 9) {
						++sum;
						return;
					}
				}
				decode(pos + 1, s, sum);
			}
			// two digits case
			if (pos + 1 < s.size()) {
				int num = (s[pos] - '0') * 10 + (s[pos + 1] - '0');
				if (num < 10 || num > 26) {
					return;
				} else {
					if (pos + 2 == s.size()) {
						++sum;
						return;
					}
					decode(pos + 2, s, sum);
				}
			}
		}
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

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);
		
		int ret = Solution().numDecodings(s);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}

