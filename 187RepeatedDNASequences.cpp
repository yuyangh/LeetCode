#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 *
 * https://leetcode.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (35.98%)
 * Likes:    434
 * Dislikes: 173
 * Total Accepted:    125.6K
 * Total Submissions: 348.5K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and
 * T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
 * identify repeated sequences within the DNA.
 *
 * Write a function to find all the 10-letter-long sequences (substrings) that
 * occur more than once in a DNA molecule.
 *
 * Example:
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * Output: ["AAAAACCCCC", "CCCCCAAAAA"]
 */
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		if (s.empty()) {
			return vector<string>();
		}
		vector<string> result;
		// use hashtable to record number of existence
		unordered_map<string, int> seq;
		string str;
		// size() return size_t, which is unsigned
		for (int i = 0; i <= (int) s.size() - 10; i++) {
			str = s.substr(i, 10);
			auto find = seq.find(str);
			if (find == seq.end()) {
				seq.emplace(str, 1);
			} else {
				find->second += 1;
				if (find->second == 2) {
					result.emplace_back(str);
				}
			}
		}
		return result;
	}
};

int main() {
	string temp;
	cin >> temp;
	Solution solution;
	auto result = solution.findRepeatedDnaSequences(temp);
	for (const auto &item : result) {
		cout << item << ",";
	}
	cout << "\n";
}