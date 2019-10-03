//
// Created by Yuyang Huang on 10/3/19.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 *
 * https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
 *
 * algorithms
 * Medium (46.68%)
 * Likes:    433
 * Dislikes: 39
 * Total Accepted:    18.2K
 * Total Submissions: 38.8K
 * Testcase Example:  '[4,5,0,-2,-3,1]\n5'
 *
 * Given an array A of integers, return the number of (contiguous, non-empty)
 * subarrays that have a sum divisible by K.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: A = [4,5,0,-2,-3,1], K = 5
 * Output: 7
 * Explanation: There are 7 subarrays with a sum divisible by K = 5:
 * [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2,
 * -3]
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 30000
 * -10000 <= A[i] <= 10000
 * 2 <= K <= 10000
 *
 *
 */

// @lc code=start
class Solution {
public:
	/*
	 * sum of contiguous subarray , prefix sum is a common technique
	 * runtime: O(1), space:O(K)
	 *
	 * if sum[0, i] % K == sum[0, j] % K,
	 * then sum[i + 1, j] is divisible by K.
	 * this is because there are a multiple of K between them.
	 *
	 * So for current index j,
	 * we need to find out how many index i (i < j) exit that has the same mod of K.
	 */
	int subarraysDivByK(vector<int> &A, int K) {
		// count the existence of same mod result
		vector<int> existences(K, 0);
		// initialize for the 1st mod result 0
		existences[0] = 1;
		
		int sum = 0, count = 0;
		for (auto num:A) {
			sum = (sum + num) % K;
			if (sum < 0) {
				// handle negative numbers
				// Because -1 % 5 = -1,
				// but we need the positive mod 4
				sum += K;
			}
			
			// plus the previous existence of such mod result
			count += existences[sum];
			existences[sum]++;
		}
		return count;
	}
};


void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> A = stringToIntegerVector(line);
		getline(cin, line);
		int K = stringToInteger(line);
		
		int ret = Solution().subarraysDivByK(A, K);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}

