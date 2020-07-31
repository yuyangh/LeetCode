//
// Created by Yuyang Huang on 7/30/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (57.18%)
 * Likes:    3360
 * Dislikes: 218
 * Total Accepted:    431.1K
 * Total Submissions: 704.9K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Note:
 *
 *
 * You may assume k is always valid, 1 â‰¤ k â‰¤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * It's guaranteed that the answer is unique, in other words the set of the top
 * k frequent elements is unique.
 * You can return the answer in any order.
 *
 *
 */

// @lc code=start
class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * use quick select to get top k element
	 */
	vector<int> topKFrequent(vector<int> &nums, int k) {
		unordered_map<int, int> numsCount;
		for (const auto &num : nums) {
			numsCount[num]++;
		}
		
		// record keys of the map
		vector<int> numFrequency;
		numFrequency.reserve(numsCount.size());
		for (const auto &item : numsCount) {
			numFrequency.emplace_back(item.first);
		}
		
		// get top k element
		nth_element(numFrequency.begin(), numFrequency.begin() + k, numFrequency.end(), [&numsCount](int lhs, int rhs) {
			return numsCount[lhs] > numsCount[rhs];
		});
		
		return vector<int>(numFrequency.begin(), numFrequency.begin() + k);
	}
};

// @lc code=end
int main() {
	Solution solution;
	vector<int> nums;
	nums = {1, 1, 1, 2, 2, 3};
	PrintVector(solution.topKFrequent(nums, 2));
	
	nums = {1};
	PrintVector(solution.topKFrequent(nums, 1));
	
	Complete();
}
