//
// Created by Yuyang Huang on 5/28/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=857 lang=cpp
 *
 * [857] Minimum Cost to Hire K Workers
 *
 * https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/
 *
 * algorithms
 * Hard (48.68%)
 * Likes:    824
 * Dislikes: 81
 * Total Accepted:    27.9K
 * Total Submissions: 56.6K
 * Testcase Example:  '[10,20,5]\n[70,50,30]\n2'
 *
 * There are N workers.Â  The i-th worker has a quality[i] and a minimum wage
 * expectation wage[i].
 *
 * Now we want to hire exactly KÂ workers to form a paid group.Â  When hiring a
 * group of K workers, we must pay them according to the following rules:
 *
 *
 * Every worker in the paid group should be paid in the ratio of their quality
 * compared to other workers in the paid group.
 * Every worker in the paid group must be paid at least their minimum wage
 * expectation.
 *
 *
 * Return the least amount of money needed to form a paid group satisfying the
 * above conditions.
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: quality = [10,20,5], wage = [70,50,30], K = 2
 * Output: 105.00000
 * Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
 * Output: 30.66667
 * Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers
 * seperately.
 *
 *
 *
 *
 * Note:
 * 1 <= K <= N <= 10000, where N = quality.length = wage.length
 * 1 <= quality[i] <= 10000
 * 1 <= wage[i] <= 10000
 * Answers within 10^-5 of the correct answer will be considered correct.
 *
 *
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(nlogn)
 * selected worker group has same wage/quality ratio,
 * so the total expense is determined by both quality and the ratio.
 * Use pq to find a minimum with ratio and quality
 */
class Solution {
public:
	double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int K) {
		vector<pair<double, int>> ratioQuality;
		priority_queue<int> pq;
		double minExpense = numeric_limits<double>::max(), qualitySum = 0;
		
		// calculate ratio for each worker
		ratioQuality.reserve(quality.size());
		for (int i = 0; i < quality.size(); ++i) {
			ratioQuality.emplace_back(make_pair(static_cast<double>(wage[i]) / (quality[i]), quality[i]));
		}
		
		// higher quality value will be put at the top
		sort(ratioQuality.begin(), ratioQuality.end());
		for (const auto &item : ratioQuality) {
			pq.emplace(item.second);
			qualitySum += item.second;
			if (pq.size() > K) {
				qualitySum -= pq.top();
				pq.pop();
			}
			if (pq.size() == K) {
				minExpense = min(minExpense, item.first * qualitySum);
			}
		}
		return minExpense;
	}
};
// @lc code=end

int main() {
	Solution solution;
	vector<int> quality = {10, 20, 5}, wage = {70, 50, 30};
	int K = 2;
	// assert(solution.mincostToHireWorkers(quality, wage, K) == 105.0);
	quality = {3, 1, 10, 10, 1}, wage = {4, 8, 2, 2, 7};
	K = 3;
	assert(abs(solution.mincostToHireWorkers(quality, wage, K) - 30.66667) < 0.1);
	Complete();
	
}