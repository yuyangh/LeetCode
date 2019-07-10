#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.98%)
 * Likes:    3780
 * Dislikes: 425
 * Total Accepted:    552.8K
 * Total Submissions: 2.3M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 *
 * Note:
 * The solution set must not contain duplicate triplets.
 *
 * Example:
 * Given array nums = [-1, 0, 1, 2, -1, -4], input as: -1, 0, 1, 2, -1, -4
 *
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 */
class Solution {
public:
	// O(n*n), relatively slow
	vector<vector<int>> threeSum(vector<int> &nums) {
		if (nums.empty()) {
			return vector<vector<int>>();
		}
		vector<vector<int>> result;
		
		sort(nums.begin(), nums.end());
		// get the count of each num
		unordered_map<int, int> valueCountMap;
		// get all non duplicate numbers
		vector<int> nonDuplicateNums;
		
		int prevNum = INT_MAX;
		auto find = valueCountMap.find(0);
		for (int &num : nums) {
			if (num != prevNum) {
				nonDuplicateNums.emplace_back(num);
				prevNum = num;
				valueCountMap.emplace(num, 1);
				find = valueCountMap.find(num);
			} else {
				find->second++;
			}
		}
		// look 3 sums
		for (int i = 0; i < nonDuplicateNums.size(); ++i) {
			for (int j = i; j < nonDuplicateNums.size(); ++j) {
				// get rid of number pretend to exist twice but indeed once
				if (i == j) {
					if (valueCountMap.find(nonDuplicateNums[i])->second < 2) {
						continue;
					}
				}
				// looking for the target
				auto target = valueCountMap.find(0 - nonDuplicateNums[i] - nonDuplicateNums[j]);
				if (target != valueCountMap.end()) {
					bool add = false;
					// to avoid duplicate result, numbers must in ascending order
					if (target->first < max(nonDuplicateNums[i], nonDuplicateNums[j])) {
						continue;
					}
					// must pass
					if (target->second >= 3) {
						add = true;
					}
					// three nums must not equal
					if (target->second == 2) {
						if ((i == j && target->first != nonDuplicateNums[i]) ||
						    (i != j)) {
							add = true;
						}
					}
					if (target->second == 1) {
						if (target->first != nonDuplicateNums[i] &&
						    target->first != nonDuplicateNums[j]) {
							add = true;
						}
					}
					if (add) {
						result.push_back({nonDuplicateNums[i], nonDuplicateNums[j], target->first});
						continue;
					}
				}
			}
		}
		return result;
	}
	
	// reference O(n*n), but actually runs faster
	vector<vector<int> > threeSumRef(vector<int> &num) {
		vector<vector<int> > res;
		std::sort(num.begin(), num.end());
		
		for (int i = 0; i < num.size(); i++) {
			int target = -num[i];
			int front = i + 1;
			int back = num.size() - 1;
			while (front < back) {
				int sum = num[front] + num[back];
				
				// Finding answer which start from number num[i]
				if (sum < target)
					front++;
				else if (sum > target)
					back--;
				else {
					vector<int> triplet(3, 0);
					triplet[0] = num[i];
					triplet[1] = num[front];
					triplet[2] = num[back];
					res.push_back(triplet);
					
					// Processing duplicates of Number 2
					// Rolling the front pointer to the next different number forwards
					while (front < back && num[front] == triplet[1]) front++;
					
					// Processing duplicates of Number 3
					// Rolling the back pointer to the next different number backwards
					while (front < back && num[back] == triplet[2]) back--;
				}
			}
			// Processing duplicates of Number 1
			while (i + 1 < num.size() && num[i + 1] == num[i])
				i++;
		}
		return res;
	}
};

int main(int argc, char **argv) {
	string in;
	while (getline(cin, in)) {
		stringstream ss(in);
		int num;
		vector<int> input;
		while (ss >> num) {
			if (ss.peek() == ',') {
				ss.ignore();
			}
			input.push_back(num);
		}
		Solution solution;
		auto result = solution.threeSum(input);
		for (const auto &item : result) {
			for (const auto &value : item) {
				cout << value << " ";
			}
			cout << "\n";
		}
	}
}