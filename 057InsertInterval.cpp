#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (31.20%)
 * Likes:    820
 * Dislikes: 101
 * Total Accepted:    178.1K
 * Total Submissions: 570K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their
 * start times.
 *
 * Example 1:
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 *
 *
 * Example 2:
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 *
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 *
 */
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		if(intervals.empty()){
			return {newInterval};
		}
		if(newInterval.empty()){
			return intervals;
		}
		int pos=binarySearch(intervals,newInterval);
		intervals.emplace(intervals.begin()+pos,newInterval);
		
		// merge the intervals
		vector<vector<int>> result;
		result.emplace_back(intervals[0]);
		pos = 0;
		for (int i = 1; i < intervals.size(); i++) {
			if (result[pos][1] >= intervals[i][0]) {
				result[pos][1] = max(result[pos][1], intervals[i][1]);
			} else {
				result.emplace_back(intervals[i]);
				pos++;
			}
		}
		return result;
	}
	
	/**
	 * search for the insertion position
	 * @param intervals
	 * @param newInterval
	 * @return
	 */
	int binarySearch(vector<vector<int>>& intervals, vector<int>& newInterval){
		int low=0,high=intervals.size()-1,mid;
		while(low<=high){
			mid=(low+high)/2;
			if(intervals[mid][0]==newInterval[0]){
				return mid;
			}else{
				if(intervals[mid][0]<newInterval[0]){
					low=mid+1;
				}else{
					high=mid-1;
				}
			}
		}
		return low;
	}
};