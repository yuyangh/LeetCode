//
// Created by Yuyang Huang on 9/15/21.
//

/*
 * 1481. Least Number of Unique Integers after K Removals
 * Medium
 *
 * Given an array of integers arr and an integer k.
 * Find the least number of unique integers after removing exactly k elements.
 *
 * Example 1:
 * Input: arr = [5,5,4], k = 1
 * Output: 1
 * Explanation: Remove the single 4, only 5 is left.
 *
 * Example 2:
 * Input: arr = [4,3,1,1,3,3,2], k = 3
 * Output: 2
 * Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
 *
 * Constraints:
 * 1 <= arr.length <= 10^5
 * 1 <= arr[i] <= 10^9
 * 0 <= k <= arr.length
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(nlogn)
	 * count the frequency and remove by least frequency item first
	 */
	int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
		unordered_map<int, int> numCountMap;
		vector<int> numCount;
		
		for (int num: arr) {
			numCountMap[num]++;
		}
		for (auto &it: numCountMap) {
			numCount.push_back(it.second);
		}
		
		sort(numCount.begin(), numCount.end());
		for (int idx = 0; idx < numCount.size(); idx++) {
			if (k >= numCount[idx]) {
				k -= numCount[idx];
				numCount[idx] = 0;
			}
			if (k == 0) {
				break;
			}
		}
		
		int unique = 0;
		for (int i: numCount) {
			if (i != 0) {
				unique++;
			}
		}
		return unique;
	}
};