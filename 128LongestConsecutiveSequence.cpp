#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (41.77%)
 * Likes:    1894
 * Dislikes: 92
 * Total Accepted:    212.3K
 * Total Submissions: 506.6K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 *
 * Your algorithm should run in O(n) complexity.
 *
 * Example:
 *
 *
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 */
class Solution {
public:
	// O(n)
	// for O(n) requirement on n elements,
	// think about hashset / hashmap,
	// which can remember the state of numbers
	int longestConsecutive(vector<int> &nums) {
		if (nums.empty()) {
			return 0;
		}
		
		// record all numbers
		unordered_set<int> numsSet;
		for (const auto &num : nums) {
			numsSet.emplace(num);
		}
		
		int maxLength = 0;
		while (!numsSet.empty()) {
			int length = 1;
			int num = *numsSet.begin();
			numsSet.erase(num);
			
			// count and remove all larger continuous numbers
			int larger = num + 1;
			while (numsSet.find(larger) != numsSet.end()) {
				++length;
				numsSet.erase(larger);
				++larger;
			}
			
			// count and remove all smaller continuous numbers
			int smaller = num - 1;
			while (numsSet.find(smaller) != numsSet.end()) {
				++length;
				numsSet.erase(smaller);
				--smaller;
			}
			
			if (length > maxLength) {
				maxLength = length;
			}
		}
		return maxLength;
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
		
		int ret = Solution().longestConsecutive(nums);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}
