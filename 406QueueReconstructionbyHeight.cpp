//
// Created by Yuyang Huang on 6/6/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 *
 * https://leetcode.com/problems/queue-reconstruction-by-height/description/
 *
 * algorithms
 * Medium (61.45%)
 * Likes:    2758
 * Dislikes: 320
 * Total Accepted:    137.5K
 * Total Submissions: 210.5K
 * Testcase Example:  '[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]'
 *
 * Suppose you have a random list of people standing in a queue. Each person is
 * described by a pair of integers (h, k), where h is the height of the person
 * and k is the number of people in front of this person who have a height
 * greater than or equal to h. Write an algorithm to reconstruct the queue.
 *
 * Note:
 * The number of people is less than 1,100.
 *
 *
 * Example
 *
 *
 * Input:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 *
 * Output:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 *
 *
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(n*n)
 * Greedy approach
 */
class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
		// first make sure where the shortest person's position is, then think about next one
		sort(people.begin(), people.end(), [](vector<int> &lhs, vector<int> &rhs) {
			if (lhs[0] < rhs[0]) {
				return true;
			} else {
				return lhs[0] == rhs[0] && lhs[1] < rhs[1];
			}
		});
		
		vector<vector<int>> result(people.size(), vector<int>());
		
		for (const auto &person : people) {
			int numPeopleBefore = person[1];
			int height = person[0];
			int countNumPeopleHigher = 0;
			
			// please person after numPeopleBefore
			for (int pos = 0; pos < people.size(); ++pos) {
				if (result[pos].empty() || result[pos][0] >= height) {
					++countNumPeopleHigher;
				} else {
					continue;
				}
				
				if (countNumPeopleHigher == numPeopleBefore + 1) {
					result[pos] = person;
					break;
				}
			}
		}
		
		return result;
	}
};
// @lc code=end

int main() {
	Solution solution;
	
	vector<vector<int>> people;
	people = {{7, 0},
	          {4, 4},
	          {7, 1},
	          {5, 0},
	          {6, 1},
	          {5, 2}};
	
	PrintVectorVector(solution.reconstructQueue(people));
	
	Complete();
}
