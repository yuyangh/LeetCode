#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (45.82%)
 * Likes:    1752
 * Dislikes: 307
 * Total Accepted:    93.5K
 * Total Submissions: 203.6K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks. Tasks
 * could be done without original order. Each task could be done in one
 * interval. For each interval, CPU could finish one task or just be idle.
 *
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle.
 *
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 *
 *
 *
 * Example:
 *
 *
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 *
 *
 *
 *
 * Note:
 *
 *
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 *
 *
 */
class Solution {
public:
	/*
	 * the idea is to find out the idle time first
	 * the total time is determined by the max of
	 * (larget single job) * (n+1)
	 * and tasks size
	 *
	 * it is clear with two extreme case:
	 * large amount of small jobs and a large single job
	 *
	 * can use array instead of hashtable to optimize
	 */
	int leastInterval(vector<char> &tasks, int n) {
		if (n == 0) {
			return tasks.size();
		}
		
		int space;
		unordered_map<char, int> typeCount;
		int maxNumItem = 0;
		
		// calculate job types and its count
		for (const auto &task : tasks) {
			auto it = typeCount.find(task);
			if (it == typeCount.end()) {
				typeCount.emplace(task, 1);
				if (maxNumItem == 0) {
					maxNumItem = 1;
				}
			} else {
				++it->second;
				if (it->second > maxNumItem) {
					maxNumItem = it->second;
				}
			}
		}
		
		space = (maxNumItem - 1) * (n + 1);
		
		// add the space for the ending jobs which do not need cooling time
		for (const auto &item : typeCount) {
			if (item.second == maxNumItem) {
				++space;
			}
		}
		
		// choose the max one
		return max(space, (int) tasks.size());
	}
};

int main() {
	vector<string> input;
	vector<char> arr;
	int gap;
	
	input = {"A", "A", "A", "A", "A", "A", "B", "C", "D", "E", "F", "G"};
	gap = 2;
	
	// do conversion
	arr.reserve(input.size());
	for (auto &item : input) {
		arr.emplace_back(item[0]);
	}
	
	Solution solution;
	solution.leastInterval(arr, gap);
	
}

