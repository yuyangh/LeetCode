#include "LeetCodeLib.h"

class Solution {
public:
	int jump(vector<int> &nums) {
		int notAccessible = -1;
		vector<int> jumpsCost(nums.size(), INT_MAX);
		jumpsCost[0] = 0;
		int maxJump = 0;
		
		if (nums.empty()) {
			return notAccessible;
		}
		if (nums.size() == 1) {
			return 0;
		}
		
		for (int i = 0; i < nums.size(); i++) {
			// all positions before maxJump are accessible
			if (i > maxJump) {
				return notAccessible;
			} else {
				// maxJump = max(maxJump, i + nums[i]);
				if (maxJump < i + nums[i]) {
					maxJump = i + nums[i];
					int cost = jumpsCost[i] + 1;
					
					// update jumpCost in the jump range
					for (int j = i + 1; j <= maxJump && j < nums.size(); j++) {
						if (cost < jumpsCost[j]) {
							jumpsCost[j] = cost;
						}
					}
				}
			}
			
			// if we can access the last position or even beyond
			if (maxJump >= nums.size() - 1) {
				return jumpsCost[nums.size() - 1];
			}
		}
		return notAccessible;
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
		
		int ret = Solution().jump(nums);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}