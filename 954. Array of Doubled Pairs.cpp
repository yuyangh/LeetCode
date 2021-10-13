//
// Created by Yuyang Huang on 10/18/21.
//

/*
 * 954. Array of Doubled Pairs
Medium

855

102

Add to List

Share
Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.



Example 1:

Input: arr = [3,1,3,6]
Output: false
Example 2:

Input: arr = [2,1,2,6]
Output: false
Example 3:

Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
Example 4:

Input: arr = [1,2,4,16,8,4]
Output: false


Constraints:

2 <= arr.length <= 3 * 104
arr.length is even.
-105 <= arr[i] <= 105
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity O(nlogn)
	 * sort absolute value in ascending order
	 * keep track of numbers that are valid
	 */
	bool canReorderDoubled(vector<int> &arr) {
		unordered_map<int, int> numCountMap;
		for (int num: arr) {
			numCountMap[num] += 1;
		}
		
		sort(arr.begin(), arr.end(), [](int lhs, int rhs) {
			return abs(lhs) < abs(rhs);
		});
		
		for (int i = 0; i < arr.size(); i++) {
			int num = arr[i];
			// if num has already used
			if (numCountMap[num] <= 0) { continue; }
			
			// return false if no corresponding number
			if (numCountMap[num * 2] <= 0) { return false; }
			
			numCountMap[num]--;
			numCountMap[num * 2]--;
		}
		return true;
	}
};

int main() {
	Solution solution;
	vector<int> arr;
	arr = {1, 2, 4, 16, 8, 4};
	
	PrintSingleResult(solution.canReorderDoubled(arr));
}