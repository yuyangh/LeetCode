#include "LeetCodeLib.h"

class Solution {

public:
	// O(n) implementation
	bool canJump(vector<int> &nums) {
		int maxJump = 0;
		if (nums.empty()) {
			return false;
		}
		
		for (int i = 0; i < nums.size(); i++) {
			// all positions before maxJump are accessible
			if (i > maxJump) {
				return false;
			} else {
				maxJump = max(maxJump, i + nums[i]);
			}
			
			// if we can access the last position or even beyond
			if (maxJump >= nums.size() - 1) {
				return true;
			}
		}
		return false;
	}
	
	// O(2^n) implementation, depends on the value of the num
	/*
	bool canJump(vector<int> &nums) {
	   int maxJump=0;
	   if (nums.empty()) {
		  return false;
	   }
	   
	   // vector constructor (size, value)
	   vector<bool> arr(nums.size(), false);
	   arr[0] = true;
	   
	   for (int i = 0; i < nums.size(); i++) {
		  if (!arr[i]) {
			 continue;
		  }
		  for (int j = 1; j <= nums[i]; j++) {
			 if (i + j < nums.size()) {
				arr[i + j] = true;
			 }
			 // check last element accessibility
			 if (arr[nums.size() - 1]) {
				return true;
			 }
		  }
	   }
	   return arr[nums.size() - 1];
	}
	*/
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

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);
		
		bool ret = Solution().canJump(nums);
		
		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}