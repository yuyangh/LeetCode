#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (43.72%)
 * Likes:    505
 * Dislikes: 170
 * Total Accepted:    212.5K
 * Total Submissions: 479.7K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 *
 * Note that the row index starts from 0.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 3
 * Output: [1,3,3,1]
 *
 *
 * Follow up:
 *
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 */
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> row(rowIndex+1,0);
		row[0]=1;
		
		for(int level=1;level<=rowIndex+1;level++){
			int prev=1,curr;
			// middle element, do operation on single vector
			for (int mid = 1; mid < level-1; ++mid) {
				curr=row[mid];
				row[mid]=prev+row[mid];
				prev=curr;
			}
			row[level-1]=1;
		}
		return row;
	}
};

int main(){
	int level=3;
	Solution solution;
	auto result=solution.getRow(level);
	PrintVector(result);
	return 0;
}

