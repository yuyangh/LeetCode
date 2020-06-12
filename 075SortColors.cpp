#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (42.27%)
 * Likes:    1705
 * Dislikes: 160
 * Total Accepted:    328.6K
 * Total Submissions: 773.3K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 *
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 *
 * Example:
 *
 *
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 *
 * Follow up:
 *
 *
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 *
 *
 */
class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * Space Complexity: O(1)
     * Dutch National Flag problem solution.
	 */
	void sortColors(vector<int> &nums) {
		// for all idx < p0 : nums[idx < p0] = 0
		// curr is an index of element under consideration
		int p0 = 0, curr = 0;
		// for all idx > p2 : nums[idx > p2] = 2
		int p2 = nums.size() - 1;
		
		while (curr <= p2) {
			if (nums[curr] == 0) {
				// swap current with next 0th place
				swap(nums[curr++], nums[p0++]);
			} else if (nums[curr] == 2) {
				// swap current with next 2th place
				swap(nums[curr], nums[p2--]);
			} else {
				curr++;
			}
		}
	}
	
	void sortColorsRef(vector<int> &nums) {
		if (nums.empty() || nums.size() == 1) {
			return;
		}
		int color[3] = {0, 0, 0};
		
		// utilize the number property
		// larger numbers must move backward
		for (int i = 0; i < nums.size(); ++i) {
			switch (nums[i]) {
				case 0: {
					for (int index = 2; index >= 0; --index) {
						nums[color[index]] = index;
					}
					for (int index = 2; index >= 0; --index) {
						++color[index];
					}
					break;
				}
				case 1: {
					for (int index = 2; index >= 1; --index) {
						nums[color[index]] = index;
					}
					for (int index = 2; index >= 1; --index) {
						++color[index];
					}
					break;
				}
				case 2: {
					++color[2];
					break;
				}
				default: {
					printf("Wrong input\n");
				}
			}
		}
	}
};

int main() {
	vector<int> arr = {1, 2, 0, 1, 2, 0};
	Solution solution;
	solution.sortColors(arr);
	PrintVector(arr);
	return 0;
}

