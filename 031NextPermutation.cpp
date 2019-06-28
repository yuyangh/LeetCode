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
	/**
	 * O(n)
	 * @param nums
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
	
	// O(n*n) find a reversed index
	void nextPermutationSlow(vector<int> &nums) {
		for (int i = nums.size() - 2; i >= 0; --i) {
			// find element larger than nums[i]
			for (int index = nums.size() - 1; index > i; --index) {
				if (nums[i] < nums[index]) {
					swap(nums[i], nums[index]);
					// sort from the element right after swapped element
					sort(nums.begin() + i + 1, nums.end());
					return;
				}
			}
		}
		reverse(nums.begin(), nums.end());
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
		
		Solution().nextPermutation(nums);
		
		string out = integerVectorToString(nums);
		cout << out << endl;
	}
	return 0;
}