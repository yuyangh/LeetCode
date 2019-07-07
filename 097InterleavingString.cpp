#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (28.08%)
 * Likes:    820
 * Dislikes: 38
 * Total Accepted:    114.5K
 * Total Submissions: 405.1K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
 * s2.
 *
 * Example 1:
 *
 *
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 *
 *
 */
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size()) {
			return false;
		}
		access_ = vector<vector<State>>(max((size_t) 1, s1.size()),
		                                vector<State>(max((size_t) 1, s2.size()), Unexplored));
		bool match = recursionMemorize(s1, 0, s2, 0, s3, 0);
		return match;
	}

private:
	enum State {
		Unexplored, NotAble, Able
	};
	vector<vector<State>> access_;
	
	// O(mn), go over access_ at most twice
	bool recursionMemorize(string &s1, int index1, string &s2, int index2, string &s3, int index3) {
		if (index3 == s3.size()) {
			return true;
		}
		
		// recall from memorization
		if (index1 < s1.size() && index2 < s2.size()) {
			if (access_[index1][index2] == Able) {
				return true;
			}
			if (access_[index1][index2] == NotAble) {
				return false;
			}
		}
		
		bool match = false;
		if (s1[index1] == s3[index3]) {
			match = recursionMemorize(s1, index1 + 1, s2, index2, s3, index3 + 1);
		}
		if (match) {
			if (index1 < s1.size() && index2 < s2.size()){
				access_[index1][index2] = Able;
			}
			return match;
		}
		if (s2[index2] == s3[index3]) {
			match = recursionMemorize(s1, index1, s2, index2 + 1, s3, index3 + 1);
		}
		if (index1 < s1.size() && index2 < s2.size()){
			access_[index1][index2] = NotAble;
		}
		return match;
		
	}
	
	// O(2^(m+n)), because we need to visit each char state twice
	bool recursionNoMemorize(string &s1, int index1, string &s2, int index2, string &s3, int index3) {
		if (index3 == s3.size()) {
			return true;
		}
		bool match = false;
		if (s1[index1] == s3[index3]) {
			match = recursionNoMemorize(s1, index1 + 1, s2, index2, s3, index3 + 1);
		}
		if (match) {
			return match;
		}
		if (s2[index2] == s3[index3]) {
			match = recursionNoMemorize(s1, index1, s2, index2 + 1, s3, index3 + 1);
		}
		return match;
		
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

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		string s1 = stringToString(line);
		getline(cin, line);
		string s2 = stringToString(line);
		getline(cin, line);
		string s3 = stringToString(line);
		
		bool ret = Solution().isInterleave(s1, s2, s3);
		
		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}