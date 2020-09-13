//
// Created by Yuyang Huang on 9/12/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
 *
 * https://leetcode.com/problems/friend-circles/description/
 *
 * algorithms
 * Medium (55.61%)
 * Likes:    2115
 * Dislikes: 145
 * Total Accepted:    184.2K
 * Total Submissions: 312.7K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * There are N students in a class. Some of them are friends, while some are
 * not. Their friendship is transitive in nature. For example, if A is a direct
 * friend of B, and B is a direct friend of C, then A is an indirect friend of
 * C. And we defined a friend circle is a group of students who are direct or
 * indirect friends.
 * 
 * Given a N*N matrix M representing the friend relationship between students
 * in the class. If M[i][j] = 1, then the ith and jth students are direct
 * friends with each other, otherwise not. And you have to output the total
 * number of friend circles among all the students.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [[1,1,0],
 * [1,1,0],
 * [0,0,1]]
 * Output: 2
 * Explanation:The 0th and 1st students are direct friends, so they are in a
 * friend circle. 
 * The 2nd student himself is in a friend circle. So return 2.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [[1,1,0],
 * [1,1,1],
 * [0,1,1]]
 * Output: 1
 * Explanation:The 0th and 1st students are direct friends, the 1st and 2nd
 * students are direct friends, 
 * so the 0th and 2nd students are indirect friends. All of them are in the
 * same friend circle, so return 1.
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= N <= 200
 * M[i][i] == 1
 * M[i][j] == M[j][i]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
	int findCircleNum(vector<vector<int>> &M) {
		if (M.empty()) {
			return 0;
		}
		
		vector<int> friendGroupIdx(M.size(), -1);
		
		int numGroups = 0;
		
		// BFS on each person
		for (int i = 0; i < friendGroupIdx.size(); i++) {
			if (friendGroupIdx[i] != -1) { continue; }
			
			queue<int> friends;
			friends.emplace(i);
			numGroups += 1;
			friendGroupIdx[i] = numGroups;
			
			while (!friends.empty()) {
				int person = friends.front();
				friends.pop();
				
				// mark friends to the same group
				for (int friend_idx = 0; friend_idx < M[0].size(); ++friend_idx) {
					if (M[person][friend_idx] == 1) {
						if (friendGroupIdx[friend_idx] != friendGroupIdx[person]) {
							friendGroupIdx[friend_idx] = friendGroupIdx[person];
							friends.emplace(friend_idx);
						}
					}
				}
			}
		}
		
		return numGroups;
	}
};
// @lc code=end

int main() {
	Solution solution;
	vector<vector<int>> matrix = {{1, 1, 0},
	                              {1, 1, 0},
	                              {0, 0, 1}};
	PrintSingleResult(solution.findCircleNum(matrix));
	assert(solution.findCircleNum(matrix) == 2);
	matrix = {{1, 1, 0},
	          {1, 1, 1},
	          {0, 1, 1}};
	assert(solution.findCircleNum(matrix) == 1);
	
	Complete();
}

