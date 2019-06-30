#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (28.94%)
 * Likes:    1758
 * Dislikes: 591
 * Total Accepted:    220K
 * Total Submissions: 756.1K
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 *
 * Example 1:
 * Input: [1,2,0]
 * Output: 3
 *
 * Example 2:
 * Input: [3,4,-1,1]
 * Output: 2
 *
 * Example 3:
 * Input: [7,8,9,11,12]
 * Output: 1
 *
 *
 * Note:
 * Your algorithm should run in O(n) time and uses constant extra space.
 */
class Solution {
public:
	// visit each number once,
	// and each number will be put in its right place at most once,
	// so it is O(n) + O(n)
	int firstMissingPositive(vector<int> &nums) {
		// Put each number in its right place.
		// For example:
		// When we find 5, then swap it with A[4].
		// At last, the first place where its number is not right, return the place + 1.
		for (int i = 0; i < nums.size(); i++) {
			while (nums[i] <= nums.size()
			       && nums[i] > 0
			       && nums[i] != nums[nums[i] - 1]) {
				//swap if nums[index] != index + 1;
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		
		//check if nums[index] == index + 1;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] - 1 != i) {
				return i + 1;
			}
		}
		
		// edge case: {1,2,3,4} return 5
		return nums.size() + 1;
	}
};

int main() {
	vector<int> arr = {3, 4, -1, 1};
	Solution solution;
	auto result = solution.firstMissingPositive(arr);
	cout << "Result is:\t" << result << endl;
}
