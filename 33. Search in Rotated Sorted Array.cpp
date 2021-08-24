#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium 
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 *
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 *
 */
class Solution {
public:
	/*
	 * average O(logn)
	 * only do binary search once
	 * use 2 conditions to check to ensure target is in one side
	 */
	int search(vector<int> &nums, int target) {
		int left = 0, right = nums.size() - 1, mid;
		
		// search in left and right range
		while (left <= right) {
			mid = (left + right) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			
			// decide the direction to search
			if (nums[left] <= nums[mid]) {
				// limit the target place to be strictly on the left half
				if (target < nums[mid] && target >= nums[left]) {
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			} else {
				if (target > nums[mid] && target <= nums[right]) {
					left = mid + 1;
				} else {
					right = mid - 1;
				}
			}
		}
		return -1;
	}
	
	/*
	 * average O(logn)
	 * first find the pivot
	 * then do binary search on both sides
	 */
	int searchTwice(vector<int> &nums, int target) {
		if (nums.empty()) {
			return -1;
		}
		
		// find the pos of the pivot
		int pivot = pivotPos(nums);
		// cout<<"pivot:"<<pivot<<endl;
		if (nums[pivot] == target) {
			return pivot;
		}
		
		// search on the left and the right
		int leftSearch = search(nums, 0, pivot - 1, target);
		int rightSearch = search(nums, pivot + 1, nums.size() - 1, target);
		if (leftSearch != -1) {
			return leftSearch;
		}
		if (rightSearch != -1) {
			return rightSearch;
		}
		return -1;
	}
	
	// find the position of the pivot,
	// pivot pos is the largest element moving forward
	int pivotPos(vector<int> &nums) {
		int mid = nums.size() - 1, low = 0, hi = nums.size() - 1;
		while (nums[low] == nums[hi]) {
			--hi;
			if (hi <= 0) {
				return 0;
			}
		}
		while (nums[low] > nums[hi]) {
			mid = (hi + low) / 2;
			// handle out of bound case
			if (mid + 1 >= nums.size()) {
				return nums.size() - 1;
			}
			if (nums[mid] > nums[mid + 1]) {
				break;
			} else {
				if (nums[mid] > nums[low]) {
					low = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
		}
		return mid;
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
		vector<int> nums = stringToIntegerVector(line);
		getline(cin, line);
		int target = stringToInteger(line);
		
		int ret = Solution().search(nums, target);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}