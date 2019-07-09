#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.77%)
 * Likes:    1180
 * Dislikes: 86
 * Total Accepted:    358.9K
 * Total Submissions: 783.8K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 * Example:
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * [-1,2,1,-4] 2
 * [-1,2,1,-4] 3
 * [-1,2,1,-4] -1
 * [-1,2,1,-4] -4
 * [-1,2,1,-4] 10
 *
 */
class Solution {
public:
	// first index go through the array to check all situations
	// remaining two index walk from two end to middle to find closest sum
	int threeSumClosest(vector<int> &nums, int target) {
		if (nums.size() < 3) {
			return 0;
		}
		
		sort(nums.begin(), nums.end());
		
		int diff_min = INT_MAX;
		int best_sum = 0;
		
		// first index, traverse array
		for (int pos = 0; pos + 2 < nums.size(); ++pos) {
			// start and end index will go through the remaining array
			int start = pos + 1, end = nums.size() - 1;
			while (start < end) {
				int sum = nums[pos] + nums[start] + nums[end];
				
				int diff = (sum - target);
				if (diff == 0) {
					return sum;
				}
				// move start and end
				if (diff < 0) {
					++start;
				} else {
					--end;
				}
				
				int distance = abs(diff);
				if (distance < diff_min) {
					diff_min = distance;
					best_sum = sum;
				}
			}
		}
		return best_sum;
	}
	
	// this O(nlogn) algorithm may move right ptr to left too much,
	// so that it cannot move left ptr to right enough
	// fails on {1, 2, 4, 8, 16, 32, 64, 128}, 82
	int threeSumClosestWrong(vector<int> &nums, int target) {
		if (nums.size() <= 3) {
			return 0;
		}
		sort(nums.begin(), nums.end());
		int start = 0, end = nums.size() - 1;
		int diff_min = INT_MAX;
		int best_sum = 0;
		while (start < end) {
			int pos = binarySearch(nums, start + 1, end - 1, target - nums[start] - nums[end]);
			if (start < pos && pos < end) {
				int sum = nums[pos] + nums[start] + nums[end];
				
				int diff = (sum - target);
				if (diff == 0) {
					return sum;
				}
				if (diff < 0) {
					++start;
				} else {
					--end;
				}
				int distance = abs(diff);
				if (distance < diff_min) {
					diff_min = distance;
					best_sum = sum;
				} else {
					if (end + 2 < nums.size()) {
						++end;
					}
				}
			} else {
				++start;
			}
		}
		return best_sum;
	}

private:
	int binarySearch(vector<int> &nums, int low, int high, int target) {
		int diff_min = INT_MAX, mid = low;
		while (low <= high) {
			mid = (low + high) / 2;
			if (target == nums[mid]) {
				return mid;
			} else {
				int diff = abs(nums[mid] - target);
				if (diff < diff_min) {
					diff_min = diff;
				} else {
					break;
				}
				if (target < nums[mid]) {
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}
		}
		return mid;
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
		
		int ret = Solution().threeSumClosest(nums, target);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}