//
// Created by Yuyang Huang on 8/24/21.
//

/*
 * 528. Random Pick with Weight
 * Medium
 *
 * You are given an array of positive integers w where w[i] describes the weight of ith index (0-indexed).
 * We need to call the function pickIndex() which randomly returns an integer in the range [0, w.length - 1].
 * pickIndex() should return the integer proportional to its weight in the w array.
 * For example, for w = [1, 3], the probability of picking the index 0 is 1 / (1 + 3) = 0.25 (i.e 25%)
 * while the probability of picking the index 1 is 3 / (1 + 3) = 0.75 (i.e 75%).
 *
 * More formally, the probability of picking index i is w[i] / sum(w).
 * Example 1:
 * Input
 * ["Solution","pickIndex"]
 * [[[1]],[]]
 * Output
 * [null,0]
 *
 * Explanation
 * Solution solution = new Solution([1]);
 * solution.pickIndex();
 * // return 0. Since there is only one single element on the array the only option is to return the first element.
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time Complexity: O(n)
	 * use prefix sum
	 */
	Solution(vector<int> &w) {
		int sum = 0;
		for (int i: w) {
			sum += i;
			prefixWeight.push_back(sum);
		}
	}
	
	/*
	 * Time complexity: O(log n)
	 * use upper bound because the prefixWeight's starting point is non zero
	 */
	int pickIndex() {
		int value = rand() % prefixWeight.back();
		auto it = upper_bound(prefixWeight.begin(), prefixWeight.end(), value);
		return it - prefixWeight.begin();
		
	}

private:
	vector<int> prefixWeight;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */