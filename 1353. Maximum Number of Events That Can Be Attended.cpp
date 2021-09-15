//
// Created by Yuyang Huang on 9/15/21.
//

/*
 * 1353. Maximum Number of Events That Can Be Attended
 * Medium
 * Given an array of events where events[i] = [startDayi, endDayi].
 * Every event i starts at startDayi and ends at endDayi.
 * You can attend an event i at any day d where startTimei <= d <= endTimei.
 * Notice that you can only attend one event at any time d.
 * Return the maximum number of events you can attend.
 *
 * Example 1:
 * Input: events = [[1,2],[2,3],[3,4]]
 * Output: 3
 * Explanation: You can attend all the three events.
 * One way to attend them all is as shown.
 * Attend the first event on day 1.
 * Attend the second event on day 2.
 * Attend the third event on day 3.
 *
 * Example 2:
 * Input: events= [[1,2],[2,3],[3,4],[1,2]]
 * Output: 4
 *
 * Example 3:
 * Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
 * Output: 4
 *
 * Example 4:
 * Input: events = [[1,100000]]
 * Output: 1
 *
 * Example 5:
 * Input: events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
 * Output: 7
 *
 * Constraints:
 * 1 <= events.length <= 105
 * events[i].length == 2
 * 1 <= startDayi <= endDayi <= 105
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(nlogn)
	 * sort event by beginning time
	 * put active events in priority queue, which sort by ending time first
	 * attend active event and remove that event
	 */
	int maxEvents(vector<vector<int>> &events) {
		sort(events.begin(), events.end(), [](vector<int> &lhs, vector<int> &rhs) {
			if (lhs[0] == rhs[0]) {
				return lhs[1] < rhs[1];
			} else {
				return lhs[0] < rhs[0];
			}
		});
		
		int daysMax = 1E5;
		int eventIdx = 0;
		int attended = 0;
		
		// <start time, end time>
		auto comp = [](pair<int, int> &lhs, pair<int, int> &rhs) {
			return lhs.second > rhs.second;
		};
		
		// end time earliest at top
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
		
		for (int day = 1; day <= daysMax; day++) {
			for (; eventIdx < events.size(); eventIdx++) {
				int startTime = events[eventIdx][0];
				int endTime = events[eventIdx][1];
				// push available event into pq
				if (startTime == day) {
					pq.push(make_pair(startTime, endTime));
				}
				if(startTime>day){
					break;
				}
			}
			
			// clean ended event and get event ends first
			while(!pq.empty()&&pq.top().second<day){
				pq.pop();
			}
			if(!pq.empty()){
				pq.pop();
				attended++;
			}
		}
		return attended;
	}
};