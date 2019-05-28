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
class Solution {
public:
	// reference from online, reach O(logn)
	vector<int> searchRange(vector<int> &nums, int target) {
		if (nums.empty()) {
			return {-1, -1};
		}
		
		// find the element
		int mid = search(nums,0,nums.size()-1,target);
		if (mid == -1) {
			return {-1, -1};
		}
		
		int right= binaryRightSearch(nums, target);
		int left= binaryLeftSearch(nums, target);
		return {left,right-1};
	}
	
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
		return lo;
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
	
	// previous implementation is O(log(n)log(n))
	// vector<int> searchRange(vector<int> &nums, int target) {
	// 	if (nums.empty()) {
	// 		return {-1, -1};
	// 	}
	//
	// 	// find the element
	// 	int mid = search(nums,0,nums.size()-1,target);
	// 	if (mid == -1) {
	// 		return {-1, -1};
	// 	}
	//
	// 	// look for the leftist element
	// 	int low, newLow = mid;
	// 	do {
	// 		low = newLow;
	// 		newLow = search(nums, 0, low - 1, target);
	// 	} while (newLow != -1);
	//
	// 	// look for the rightist element
	// 	int high, newHigh = mid;
	// 	do {
	// 		high = newHigh;
	// 		newHigh = search(nums, newHigh + 1, nums.size() - 1, target);
	// 	} while (newHigh != -1);
	//
	// 	return {low, high};
	// }
	
	
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

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}
	
	if (length == 0) {
		return "[]";
	}
	
	string result;
	for (int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);
		getline(cin, line);
		int target = stringToInteger(line);
		
		vector<int> ret = Solution().searchRange(nums, target);
		
		string out = integerVectorToString(ret);
		cout << out << endl;
	}
	return 0;
}