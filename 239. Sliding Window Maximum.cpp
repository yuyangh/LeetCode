//
// Created by Yuyang Huang on 9/12/20.
//

# include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (39.75%)
 * Likes:    3939
 * Dislikes: 178
 * Total Accepted:    294.8K
 * Total Submissions: 678.4K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Return the max sliding window.
 * 
 * Follow up:
 * Could you solve it in linear time?
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7] 
 * Explanation: 
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * 1 [3  -1  -3] 5  3  6  7       3
 * 1  3 [-1  -3  5] 3  6  7       5
 * 1  3  -1 [-3  5  3] 6  7       5
 * 1  3  -1  -3 [5  3  6] 7       6
 * 1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4<= nums[i]<= 10^4
 * 1 <= k<= nums.length
 * 
 * 
 */


/*
 * Time complexity: O(n)
 * use deque to keep index of numbers,
 * whose values are from large to small
 * remove numbers before the sliding window and numbers smaller than the current number,
 * so the deque will only have candidate values
 */
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k) {
		if (nums.empty() || k == 0) {
			return {};
		}
		
		vector<int> result;
		deque<int> deque;
		
		for (int i = 0; i < nums.size(); ++i) {
			// remove numbers before the start of the sliding window
			while (!deque.empty() && deque.front() < i - k + 1) {
				deque.pop_front();
			}
			// remove numbers in deque that are smaller than current number
			while (!deque.empty() && nums[deque.back()] < nums[i]) {
				deque.pop_back();
			}
			
			deque.emplace_back(i);
			// only add to result after k
			if (i >= k - 1) {
				result.emplace_back(nums[deque.front()]);
			}
		}
		
		return result;
	}
};
// @lc code=end

int main() {
	vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
	auto k = 3;
	Solution solution;
	PrintVector(solution.maxSlidingWindow(nums, k));
	
	nums = {1};
	PrintVector(solution.maxSlidingWindow(nums, 1));
	
	Complete();
}
