#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (40.82%)
 * Likes:    1541
 * Dislikes: 3301
 * Total Accepted:    604.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted array nums, remove the duplicates in-place such that each
 * element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 *
 * Example 1:
 * Given nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively.
 *
 * It doesn't matter what you leave beyond the returned length.
 *
 * Example 2:
 * Given nums = [0,0,1,1,1,2,2,3,3,4],
 *
 * Your function should return length = 5, with the first five elements of nums
 * being modified to 0, 1, 2, 3, and 4 respectively.
 *
 * It doesn't matter what values are set beyond the returned length.
 *
 * Clarification:
 * Confused why the returned value is an integer but your answer is an array?
 *
 * Note that the input array is passed in by reference, which means
 * modification to the input array will be known to the caller as well.
 *
 * Internally you can think of this:
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 *
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 */
class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * Space complexity: O(1)
	 * use erase+remove, much faster
	 */
	int removeDuplicates(vector<int> &nums) {
		int magic = INT_MIN / 2;
		// replace item with magic value
		for (int i = nums.size() - 2; i >= 0; i--) {
			if (nums[i] == nums[i + 1]) {
				nums[i + 1] = magic;
			}
		}
		
		// std::remove
		// Transforms the range [first,last) into a range with all the elements that compare equal to val removed,
		// and returns an iterator to the new end of that range.
		// std::vector::erase
		// Iterators specifying a range within the vector] to be removed: [first,last)
		nums.erase(remove(nums.begin(), nums.end(), magic), nums.end());
		return nums.size();
	}
	
	// delete element by element, much slower
	int removeDuplicatesSlow(vector<int> &nums) {
		for (int i = nums.size() - 2; i >= 0; i--) {
			if (nums[i] == nums[i + 1]) {
				nums.erase(nums.begin() + i);
			}
		}
		return nums.size();
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
		
		int ret = Solution().removeDuplicates(nums);
		
		string out = integerVectorToString(nums, ret);
		cout << out << endl;
	}
	return 0;
}