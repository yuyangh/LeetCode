#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (35.67%)
 * Likes:    1091
 * Dislikes: 2773
 * Total Accepted:    368K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 *
 * Note:
 *
 *
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 *
 *
 * Example:
 *
 *
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 *
 * Output: [1,2,2,3,5,6]
 *
 *
 */
class Solution {
public:
	/*
	 * copy from the back so that does not need extra space
	 */
	void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
		// second vector is empty, nothing to do
		if (n == 0) {
			return;
		}
		// first vector is empty, copy
		if (m == 0) {
			for (int i = 0; i < n; ++i) {
				nums1[i] = nums2[i];
			}
			return;
		}
		
		int nums1pos = m - 1;
		int nums2pos = n - 1;
		int pos = m + n - 1;
		
		while (pos >= 0) {
			// determine copy from which vector
			if (nums1[nums1pos] > nums2[nums2pos]) {
				nums1[pos] = nums1[nums1pos];
				--nums1pos;
			}else{
				nums1[pos]=nums2[nums2pos];
				--nums2pos;
			}
			--pos;
			// if complete copy from vector 1
			if(nums1pos<0){
				while(nums2pos>=0){
					nums1[pos]=nums2[nums2pos];
					--pos;
					--nums2pos;
				}
				break;
			}
			if(nums2pos<0){
				break;
			}
		}
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

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}
	
	if (length == 0) {
		return "[]";
	}
	
	string result;
	for(int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums1 = stringToIntegerVector(line);
		getline(cin, line);
		int m = stringToInteger(line);
		getline(cin, line);
		vector<int> nums2 = stringToIntegerVector(line);
		getline(cin, line);
		int n = stringToInteger(line);
		
		Solution().merge(nums1, m, nums2, n);
		
		string out = integerVectorToString(nums1);
		cout << out << endl;
	}
	return 0;
}