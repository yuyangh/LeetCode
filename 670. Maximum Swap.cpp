//
// Created by Yuyang Huang on 9/5/21.
//

/*
 * 670. Maximum Swap
 * Medium
 *
 * You are given an integer num. You can swap two digits at most once to get the maximum valued number.
 * Return the maximum valued number you can get.
 *
 * Example 1:
 * Input: num = 2736
 * Output: 7236
 * Explanation: Swap the number 2 and the number 7.
 *
 * Example 2:
 * Input: num = 9973
 * Output: 9973
 * Explanation: No swap.
 *
 * Constraints:
 * 0 <= num <= 108
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(n)
	 */
	int maximumSwap(int num) {
		string numStr = to_string(num);
		vector<int> digitLastPos(10, -1);
		
		// record the last position for each digit
		for (int i = 0; i < numStr.size(); i++) {
			digitLastPos[numStr[i] - '0'] = i;
		}
		
		for (int i = 0; i < numStr.size(); i++) {
			// look for whether there is a larger digit afterwards
			for (int digit = 9; digit >= 0; digit--) {
				if (digitLastPos[digit] > i && digit > numStr[i] - '0') {
					swap(numStr[i], numStr[digitLastPos[digit]]);
					return stoi(numStr);
				}
			}
		}
		
		return num;
	}
};