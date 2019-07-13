#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (33.18%)
 * Likes:    882
 * Dislikes: 231
 * Total Accepted:    142.2K
 * Total Submissions: 425K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 *
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 *
 *
 * Given n and k, return the k^th permutation sequence.
 *
 * Note:
 *
 *
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3, k = 3
 * Output: "213"
 *
 *
 * Example 2:
 *
 *
 * Input: n = 4, k = 9
 * Output: "2314"
 *
 *
 */
class Solution {
public:
	/**
	 * return the kth permutation for a n-char sequence
	 * @param n between 1 and 9 inclusive
	 * @param k between 1 and n! inclusive
	 * @return kth permutation sequence
	 */
	string getPermutation(int n, int k) {
		// since k starts from 1, decrease 1
		int swap_need = k - 1;
		string result;
		
		vector<int> nums;
		nums.reserve(n);
		for (int i = 0; i < n; ++i) {
			nums.emplace_back(i + 1);
		}
		
		for (int factorials_index = n - 1; factorials_index >= 0; --factorials_index) {
			int choose_pos = 0;
			/*
			 * say n = 4, you have {1, 2, 3, 4}
			 * If you were to list out all the permutations you have
			 * 1 + (permutations of 2, 3, 4)
			 * 2 + (permutations of 1, 3, 4)
			 * 3 + (permutations of 1, 2, 4)
			 * 4 + (permutations of 1, 2, 3)
			 * So each of those with permutations of 3 numbers means
			 * there are 6 possible permutations.
			 * Meaning there would be a total of 24 permutations in this particular one.
			 * So if you were to look for the (k = 14) 14th permutation,
			 * it would be in the 3 + (permutations of 1, 2, 4) subset.
			 */
			while (swap_need >= factorials_[factorials_index]) {
				swap_need -= factorials_[factorials_index];
				++choose_pos;
			}
			// add the selected number and remove it from the pool
			result += (nums[choose_pos]) + '0';
			remove(nums.begin(), nums.end(), nums[choose_pos]);
		}
		return result;
	}
	
	vector<vector<int>> GeneratePermutation(int n) {
		vector<int> nums;
		nums.reserve(n);
		vector<vector<int>> result;
		for (int i = 0; i < n; ++i) {
			nums.emplace_back(i + 1);
		}
		permute(result, nums, 0);
		return result;
	}

private:
	// pre-calculated factorials
	const vector<int> factorials_ = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
	
	void permute(vector<vector<int>> &result, vector<int> nums, int index) {
		if (index == nums.size()) {
			result.emplace_back(nums);
			return;
		}
		for (int i = index; i < nums.size(); ++i) {
			swap(nums[i], nums[index]);
			permute(result, nums, index + 1);
		}
	}
};

int main() {
	Solution solution;
	int n = 4;
	// auto result = solution.GeneratePermutation(n);
	// PrintVectorVector(result);
	auto result = solution.getPermutation(3, 3);
	PrintSingleResult(result);
	return 0;
}

