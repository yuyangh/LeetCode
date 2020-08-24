#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (30.52%)
 * Likes:    1845
 * Dislikes: 577
 * Total Accepted:    245K
 * Total Submissions: 800.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place and use only constant extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 *
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */
class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * find 1st decreasing digit from the end
	 * swap that digit with a digit larger than that from the end
	 * reverse the part
	 */
	void nextPermutation(vector<int> &nums) {
		int smallerIndex = -1;
		// We need to find the first pair of two successive numbers a[i] and a[i−1],
		// from the right, which satisfy a[i] > a[i-1].
		for (int i = nums.size() - 1; i >= 1; --i) {
			// find 1st non-ascending number from backward
			if (nums[i] > nums[i - 1]) {
				smallerIndex = i - 1;
				break;
			}
		}
		// if there are none, done
		if (smallerIndex == -1) {
			reverse(nums.begin(), nums.end());
			return;
		}
		// Now, no rearrangements to the right of a[i-1]
		// can create a larger permutation since that subarray
		// consists of numbers in descending order.
		// Thus, we need to rearrange the numbers
		// to the right of a[i−1] including itself.
		
		// Now, what kind of rearrangement will produce the next larger number?
		// We want to create the permutation just larger than the current one.
		// Therefore, we need to replace the number a[i−1]
		// with the number which is just larger than itself
		// among the numbers lying to its right section, say a[j].
		for (int largerIndex = nums.size() - 1; largerIndex > smallerIndex; --largerIndex) {
			// find and swap the element just larger than itself
			if (nums[largerIndex] > nums[smallerIndex]) {
				swap(nums[largerIndex], nums[smallerIndex]);
				break;
			}
		}
		// We swap the numbers a[i−1] and a[j].
		// We now have the correct number at index i−1.
		// But still the current permutation isn't the
		// permutation that we are looking for.
		// We need the smallest permutation that can be
		// formed by using the numbers only to the right of a[i−1].
		// Therefore, we need to place those numbers in ascending order
		// to get their smallest permutation.
		
		// But, recall that while scanning the numbers from the right,
		// we simply kept decrementing the index until
		// we found the pair a[i] and a[i-1] where, a[i] > a[i-1].
		// Thus, all numbers to the right of a[i-1] were already
		// sorted in descending order.
		// Furthermore, swapping a[i-1] and a[j] didn't change that order.
		// Therefore, we simply need to reverse the numbers following a[i−1]
		// to get the next smallest lexicographic permutation.
		reverse(nums.begin() + smallerIndex + 1, nums.end());
	}
};