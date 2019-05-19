//
// Created by Yuyang Huang on 2019-04-20.
//

#ifndef LEETCODE_LONGESTPALINDROMICSUBSTRING_H
#define LEETCODE_LONGESTPALINDROMICSUBSTRING_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LongestPalindromicSubstring {
public:
	static string longestPalindrome(string s) {
		if (s.empty()) {
			return "";
		}
		int begin = 0, length = 1;
		vector<vector<bool>> grid;
		// initialize the space for the grid
		grid.reserve(s.size());
		for (int i = 0; i < s.size(); i++) {
			grid.emplace_back(s.size(), false);
		}
		
		// initialize the base case for the grid
		// that is true for single char and whethe true for 2 char
		for (int start = 0; start < s.size(); start++) {
			grid[start][start] = true;
			if (start + 1 < s.size() && s[start] == s[start + 1]) {
				grid[start][start + 1] = true;
				begin = start;
				length = 2;
			}
		}
		
		// it will be true if left-down is true and two adjacent are identical
		for (int end = 2; end < s.size(); end++) {
			for (int start = 0; start < end; start++) {
				if (grid[start + 1][end - 1] && s[start] == s[end]) {
					grid[start][end] = true;
					if (end - start + 1 > length) {
						begin = start;
						length = end - start + 1;
					}
				}
			}
		}
		
		// string substr (size_t pos = 0, size_t len = npos) const
		return s.substr(begin, length);
		
	}
};

#endif //LEETCODE_LONGESTPALINDROMICSUBSTRING_H
