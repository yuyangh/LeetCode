#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium 
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 *
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 *
 * Example 1:
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 *
 * Example 2:
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 *
 * Follow up:
 * This is a follow up problem to Search in Rotated Sorted Array, where nums
 * may contain duplicates.
 * Would this affect the run-time complexity? How and why?
 */

class Solution {
public:
	/*
	 * average O(logn)
	 * only do binary search once
	 * use 2 conditions to check to ensure target is in one side
	 */
	bool search(vector<int> &nums, int target) {
		int left = 0, right = nums.size() - 1, mid;
		
		while (left <= right) {
			// update left and right if they are the same to avoid duplicates
			while ((right >= 0 && left != right && nums[left] == nums[right])) {
				--right;
			}
			
			mid = (left + right) / 2;
			if (nums[mid] == target) {
				return true;
			}
			
			// decide the direction to search
			if (nums[left] <= nums[mid]) {
				// ensure target is in the left half
				if ((nums[left] <= target) && (nums[mid] > target)) {
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			} else {
				if ((nums[mid] < target) && (nums[right] >= target)) {
					left = mid + 1;
				} else {
					right = mid - 1;
				}
			}
		}
		return false;
	}
	
	/*
	 * average O(logn)
	 * first find the pivot
	 * then do binary search on both sides
	 */
	bool searchTwice(vector<int> &nums, int target) {
		if (nums.empty()) {
			return false;
		}
		
		// find the pivot
		int pos = pivotPos(nums);
		// printf("pivot pos: %d \n",pos);
		if (nums[pos] == target) {
			return true;
		}
		
		// search on left and right
		bool left = binary_search(nums.begin(), nums.begin() + pos, target);
		if (left) {
			return true;
		}
		bool right = binary_search(nums.begin() + pos + 1, nums.end(), target);
		return right;
	}
	
	/*
	 * find the position of the pivot,
	 * pivot pos is the largest element moving forward
	 */
	int pivotPos(vector<int> &nums) {
		int mid = -1, low = 0, hi = nums.size() - 1;
		// deal with duplicate number situation
		while (nums[low] == nums[hi]) {
			--hi;
			if (hi <= 0) {
				return 0;
			}
		}
		
		// binary search
		while (nums[low] >= nums[hi]) {
			mid = (hi + low) / 2;
			// handle out of bound case
			if (mid + 1 >= nums.size()) {
				return nums.size() - 1;
			}
			if (nums[mid] > nums[mid + 1]) {
				return mid;
			} else {
				if (nums[mid] >= nums[low]) {
					low = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			// handle smaller than 0
			if (hi < 0) {
				return 0;
			}
			// handle overbound
			if (low >= nums.size() - 1) {
				return low;
			}
		}
		return hi;
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

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);
		getline(cin, line);
		int target = stringToInteger(line);
		
		bool ret = Solution().search(nums, target);
		
		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}