//
// Created by Yuyang Huang on 6/5/20.
//

#include "LeetCodeLib.h"

/*
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 * Find all strobogrammatic numbers that are of length = n.
 * Example:
 * Input:  n = 2
 * Output: ["11","69","88","96"]
 */

/*
 * Time complexity: O(5^(n/2))
 * recursion
 */
class Solution {
public:
	vector<string> findStrobogrammatic(int n) {
		if (n == 0) {
			return {};
		}
		vector<string> result;
		helper(n, "", result);
		
		// get rid of ones that start with 0
		return result;
	}

private:
	void helper(int lengthLimit, string buffer, vector<string> &result) {
		// base case
		if (buffer.size() == (lengthLimit + 1) / 2) {
			for (int i = 0; i < lengthLimit / 2; ++i) {
				char prev = buffer[(lengthLimit) / 2 - 1 - i];
				if (prev == '0' || prev == '1' || prev == '8') {
					buffer.push_back(prev);
				}
				if (prev == '6') {
					buffer.push_back('9');
				}
				if (prev == '9') {
					buffer.push_back('6');
				}
			}
			result.emplace_back(buffer);
			return;
		}
		
		// handle starting with 0 case
		if (lengthLimit == 1 || buffer.size() != 0) {
			helper(lengthLimit, buffer + '0', result);
		}
		helper(lengthLimit, buffer + '1', result);
		helper(lengthLimit, buffer + '8', result);
		
		// handle odd length case
		if (buffer.size() < lengthLimit / 2) {
			helper(lengthLimit, buffer + '6', result);
			helper(lengthLimit, buffer + '9', result);
		}
	}
};

int main() {
	Solution solution;
	PrintVector(solution.findStrobogrammatic(1));
	
	PrintVector(solution.findStrobogrammatic(2));
	
	PrintVector(solution.findStrobogrammatic(3));
	
	Complete();
}