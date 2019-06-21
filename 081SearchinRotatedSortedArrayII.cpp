#include "LeetCodeLib.h"

class Solution {
public:
	bool search(vector<int> &nums, int target) {
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
	
	// find the position of the pivot,
	// pivot pos is the largest element moving forward
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