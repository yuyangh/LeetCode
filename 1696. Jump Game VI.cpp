//
// Created by Yuyang Huang on 6/9/21.
//

/*
 * 1696. Jump Game VI
 * Medium
 * You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.
 *
 * Example 1:

Input: nums = [1,-1,-2,4,-7,3], k = 2
Output: 7
Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.
Example 2:

Input: nums = [10,-5,-2,4,0,3], k = 3
Output: 17
Explanation: You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.

 Example 3:
Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
Output: 0


Constraints:

1 <= nums.length, k <= 105
-104 <= nums[i] <= 104
 */

#include "LeetCodeLib.h"

/*
 * Time Complexity: O(nlogn)
 * current approach is to use dynamic programing with heap
 * using dp with deque that has an ascending sequence would be better O(n)
 */
class Solution {
public:
	int maxResult(vector<int> &nums, int k) {
		//todo check k==0
		if (nums.size() == 1) {
			return nums[0];
		}
		
		// largest at top
		auto pairComp = [](pair<int, int> &lhs, pair<int, int> &rhs) {
			return lhs.first < rhs.first;
		};
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(pairComp)> pq(pairComp);
		pq.push(make_pair(nums.back(), nums.size() - 1));
		
		vector<int> maxSumToEnd(nums.size(), INT_MIN);
		maxSumToEnd.back() = nums.back();
		
		for (int i = static_cast<int>(nums.size()) - 2; i >= 0; --i) {
			while (pq.top().second - i > k) {
				pq.pop();
			}
			maxSumToEnd[i] = max(maxSumToEnd[i], nums[i] + pq.top().first);
			pq.push(make_pair(maxSumToEnd[i], i));
		}
		return maxSumToEnd.front();
	}
};

int main() {
	Solution solution;
	vector<int> nums;
	int k;
	nums = {1, -1, -2, 4, -7, 3}, k = 2;
	PrintSingleResult(solution.maxResult(nums, k));
	
	nums = {10, -5, -2, 4, 0, 3}, k = 3;
	PrintSingleResult(solution.maxResult(nums, k));
	
	nums = {1, -5, -20, 4, -1, 3, -6, -3}, k = 2;
	PrintSingleResult(solution.maxResult(nums, k));
	
	Complete();
}