#include "LeetCodeLib.h"
class Solution {
public:
	// partition algo is another approach, which is O(n)
	// pq is O(nlogn)
	int findKthLargest(vector<int>& nums, int k) {
		// less is smaller put at the front
		priority_queue<int,vector<int>,greater<int>> pq;
		for(int i=0;i<nums.size();i++){
			pq.push(nums[i]);
			if(pq.size()>k){
				pq.pop();
			}
		}
		return pq.top();
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
		int k = stringToInteger(line);
		
		int ret = Solution().findKthLargest(nums, k);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}