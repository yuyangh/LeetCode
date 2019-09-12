#include "LeetCodeLib.h"

/*
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
 * find the minimum number of conference rooms required.
 *
 * Example 1:
 * Input: [[0, 30],[5, 10],[15, 20]]
 * Output: 2
 *
 * Example 2:
 * Input: [[7,10],[2,4]]
 * Output: 1
 */


class Solution {
public:
	int minMeetingRooms(vector<vector<int>> &intervals) {
		// quesitons: if 2 reservation end and start at the same time, can we put them in the same room?
		// yes
		
		// test case
		// non overlapping {{1,2},{2,3},{5,6}};
		// overlapping {{1,4},{2,3},{5,8},{3,5},{7,9}};
		
		// empty interval {}
		if (intervals.empty()) {
			return 0;
		}
		
		// sort all intervals with its beginning time in ascending order
		sort(intervals.begin(), intervals.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
			return lhs[0] < rhs[0];
		});
		
		// a priority queue for storing rooms earliest ending time
		// the pq is a min heap (earliest end time room) is at the top of the pq
		priority_queue<int, vector<int>, std::greater<int>> pq;
		
		
		for (const auto &reserve:intervals) {
			if (pq.empty()) {
				// place first reservation's ending time
				pq.emplace(reserve[1]);
			} else {
				int earliestEndingTime = pq.top();
				if (earliestEndingTime <= reserve[0]) {
					pq.pop();
					// use that room with the new reserve ending time
					pq.emplace(reserve[1]);
				} else {
					// earliest room is still not satisfiable
					pq.emplace(reserve[1]);
				}
			}
		}
		
		// size of the pq will be the number of rooms we need
		return pq.size();
	}
};

int main() {
	Solution solution;
	int result;
	vector<vector<int>> empty;
	result = solution.minMeetingRooms(empty);
	PrintSingleResult(result);
	
	vector<vector<int>> nonOverLapping = {{1, 2},
	                                      {2, 3},
	                                      {5, 6}};
	result = solution.minMeetingRooms(nonOverLapping);
	PrintSingleResult(result);
	
	
	vector<vector<int>> overLapping = {{1, 4},
	                                   {2, 3},
	                                   {5, 8},
	                                   {3, 5},
	                                   {7, 9}};
	result = solution.minMeetingRooms(overLapping);
	PrintSingleResult(result);
	
	return 0;
	
}