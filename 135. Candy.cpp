//
// Created by Yuyang Huang on 6/15/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 *
 * https://leetcode.com/problems/candy/description/
 *
 * algorithms
 * Hard (28.74%)
 *
 * There are N children standing in a line. Each child is assigned a rating
 * value.
 * You are giving candies to these children subjected to the following
 * requirements:
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 *
 * Example 1:
 * Input: [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2,
 * 1, 2 candies respectively.
 *
 * Example 2:
 * Input: [1,2,2]
 * Output: 4
 * Explanation: You can allocate to the first, second and third child with 1,
 * 2, 1 candies respectively.
 * The third child gets 1 candy because it satisfies the above two conditions.
 */

// @lc code=start

/*
 * there are O(n) solution memorizing the cost from each side
 * also O(nlogn) solution with sorting
 */
class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * Space complexity: O(1)
	 * use constant space
	 */
	int candy(vector<int> &ratings) {
		int count = 1;
		int up = 0, down = 0, peak = 0;
		for (int i = 1; i < ratings.size(); ++i) {
			if (ratings[i - 1] < ratings[i]) {
				up++;
				down = 0;
				// count consecutive ups
				peak = up;
				count += up + 1;
			} else if (ratings[i - 1] == ratings[i]) {
				// for a plane, two person get same amount
				up = 0;
				down = 0;
				peak = 0;
				count += 1;
			} else if (ratings[i - 1] > ratings[i]) {
				up = 0;
				down++;
				count += 1 + down;
				if (peak >= down) {
					// decrease the need to matching height for the peak
					count -= 1;
				}
			}
		}
		return count;
	}
	
	/*
	 * Time complexity: O(n)
	 * Space complexity: O(n)
	 * use two arrays to memorize the number of candies required from each sides
	 * choose the maximum of them
	 */
	int candy2(vector<int> &ratings) {
		vector<int> left2right(ratings.size(),1);
		vector<int> right2left(ratings.size(),1);
		
		for (int i = 1; i < ratings.size(); ++i) {
			if(ratings[i-1]<ratings[i]){
				left2right[i]=left2right[i-1]+1;
			}
		}
		
		for (int i = ratings.size()-2; i >=0; --i) {
			if(ratings[i]>ratings[i+1]){
				right2left[i]=right2left[i+1]+1;
			}
		}
		
		int sum=0;
		for (int i = 0; i < ratings.size(); ++i) {
			sum+=max(left2right[i],right2left[i]);
		}
		return sum;
	}
};
// @lc code=end

