//
// Created by Yuyang Huang on 6/5/20.
//

#include "LeetCodeLib.h"

/*
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 * Write a function to determine if a number is strobogrammatic. The number is represented as a string.
 * Example 1:
 * Input:  "69"
 * Output: true
 *
 * Example 2:
 * Input:  "88"
 * Output: true
 *
 * Example 3:
 * Input:  "962"
 * Output: false
 */

/*
 * Time complexity: O(n)
 */
class Solution {
public:
	bool isStrobogrammatic(string num) {
		int length = num.size();
		for (int i = 0; i < (num.size() + 1) / 2; ++i) {
			if (num[i] == '0' && num[length - 1 - i] == '0') {
				continue;
			}
			if (num[i] == '1' && num[length - 1 - i] == '1') {
				continue;
			}
			if (num[i] == '8' && num[length - 1 - i] == '8') {
				continue;
			}
			if (num[i] == '6' && num[length - 1 - i] == '9') {
				continue;
			}
			if (num[i] == '9' && num[length - 1 - i] == '6') {
				continue;
			}
			return false;
		}
		return true;
	}
};

int main(){
	Solution solution;
	assert(solution.isStrobogrammatic("69"));
	assert(solution.isStrobogrammatic("88"));
	assert(!solution.isStrobogrammatic("962"));
	assert(solution.isStrobogrammatic("0"));
	assert(solution.isStrobogrammatic("010"));
	assert(solution.isStrobogrammatic("00"));
	assert(solution.isStrobogrammatic("6699"));
	Complete();
}