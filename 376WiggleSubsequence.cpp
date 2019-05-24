#include "LeetCodeLib.h"

class Solution {
public:
	int wiggleMaxLength(vector<int> &nums) {
		if (nums.size() < 2) {
			return nums.size();
		}
		int maxLen = 1;
		int sign = 0; // record down the sign
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] < nums[i - 1] && sign != -1) {         //peak
				sign = -1;
				maxLen++;
			} else if (nums[i] > nums[i - 1] && sign != 1) {   //valley
				sign = 1;
				maxLen++;
			}
		}
		return maxLen;
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

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);
		
		int ret = Solution().wiggleMaxLength(nums);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}