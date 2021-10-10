//
// Created by Yuyang Huang on 10/10/21.
//

/*
 * 1937. Maximum Number of Points with Cost
 * Medium

You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

x for x >= 0.
-x for x < 0.


Example 1:


Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.
Example 2:


Input: points = [[1,5],[2,3],[4,2]]
Output: 11
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.


Constraints:

m == points.length
n == points[r].length
1 <= m, n <= 105
1 <= m * n <= 105
0 <= points[r][c] <= 105

 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(mn)
	 * memorize the value from left and right
	 * choose the larger one
	 */
	long long maxPoints(vector<vector<int>>& points) {
		uint width=points.front().size();
		
		vector<long long> pre(width);
		for(uint i=0;i<width;i++){
			pre[i]=points[0][i];
		}
		for(uint row=1;row<points.size();row++){
			// memorize the largest value front left and right
			vector<long long> left(width),right(width),cur(width);
			left.front()=pre.front();
			right.back()=pre.back();
			
			for(uint i=1;i<width;i++){
				left[i]= max(left[i-1]-1,pre[i]);
			}
			for(int i=width-2;i>=0;i--){
				right[i]= max(right[i+1]-1,pre[i]);
			}
			
			// current value is the largest of left or right + points
			for(uint i=0;i<width;i++){
				cur[i]= max(left[i],right[i])+points[row][i];
			}
			pre=cur;
		}
		return *max_element(pre.begin(),pre.end());
	}
};

int main(){
	Solution solution;
	vector<vector<int>> points;
	points= {{1,2,3},{1,5,1},{3,1,1}};
	PrintSingleResult(solution.maxPoints(points));
	
	points = {{1,5},{2,3},{4,2}};
	PrintSingleResult(solution.maxPoints(points));
	
}