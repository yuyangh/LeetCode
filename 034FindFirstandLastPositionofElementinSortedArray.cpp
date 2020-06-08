#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (33.52%)
 * Likes:    1547
 * Dislikes: 85
 * Total Accepted:    299.8K
 * Total Submissions: 893.8K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example 1:
 *
 *
 * Input: nums = [5,7,8,8,8,8,8,8,10], target = 8
 * Output: [3,4]
 *
 * Example 2:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 *
 */


/*
 * Time complexity: O(logn)
 * left binary search and right binary search
 */
class Solution {
public:
	vector<int> searchRange(vector<int> &nums, int target) {
		bool targetExist = binary_search(nums.begin(), nums.end(), target);
		if (!targetExist) {
			return {-1, -1};
		}
		
		int leftBound = binaryLeftSearch(nums, target);
		int rightBound = binaryRightSearch(nums, target);
		
		return {leftBound, rightBound};
	}
	
	int binaryRightSearch(vector<int> &nums, int target) {
		int left = 0, right = nums.size();
		int mid;
		while (left < right) {
			mid = (left + right) / 2;
			// must increase left, because int division always rounds to smaller
			if (nums[mid] <= target) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		// while loop only breaks when left == right,
		// and right is always not reachable
		// so must return left -1
		return left - 1;
	}
	
	int binaryLeftSearch(vector<int> &nums, int target) {
		int left = 0, right = nums.size();
		int mid;
		while (left < right) {
			mid = (left + right) / 2;
			if (nums[mid] == target) {
				right = mid;
			} else if (nums[mid] < target) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return right;
	}
};

/*
 * reference from online, reach O(logn)
 */
class RefSolution {
public:
	vector<int> searchRange(vector<int> &nums, int target) {
		if (nums.empty()) {
			return {-1, -1};
		}
		
		// find the element
		int mid = search(nums, 0, nums.size() - 1, target);
		if (mid == -1) {
			return {-1, -1};
		}
		
		int right = binaryRightSearch(nums, target);
		int left = binaryLeftSearch(nums, target);
		return {left, right};
	}
	
	/**
	 * search the element on the right most
	 * @param nums
	 * @param target
	 * @return the index of the element on the most right side
	 */
	int binaryRightSearch(vector<int> &nums, int target) {
		int lo = 0;
		int hi = nums.size();
		
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (nums[mid] > target) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		// lo must be right most +1
		return lo - 1;
	}
	
	int binaryLeftSearch(vector<int> &nums, int target) {
		int lo = 0;
		int hi = nums.size();
		
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (nums[mid] >= target) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		return hi;
	}
	
	// normal binary search
	int search(vector<int> &nums, int low, int high, int target) {
		int mid;
		while (low <= high) {
			mid = (low + high) / 2;
			if (nums[mid] == target) {
				return mid;
			} else {
				if (nums[mid] > target) {
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}
		}
		return -1;
	}
};


int main() {
	MySolution mySolution;
	vector<int> nums;
	int target;
	target = 2;
	nums = {1, 2, 2, 2};
	PrintSingleResult(mySolution.binaryLeftSearch(nums, 2));
	PrintSingleResult(mySolution.binaryRightSearch(nums, 2));
	
	nums = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
	PrintSingleResult(mySolution.binaryLeftSearch(nums, 2) ==
	                  find(nums.begin(), nums.end(), 2) - nums.begin());
	
	Complete();
}