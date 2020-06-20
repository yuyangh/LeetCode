//
// Created by Yuyang Huang on 6/18/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 *
 * https://leetcode.com/problems/my-calendar-ii/description/
 *
 * algorithms
 * Medium (46.45%)
 * Likes:    581
 * Dislikes: 80
 * Total Accepted:    39.9K
 * Total Submissions: 81.7K
 * Testcase Example:  '["MyCalendarTwo","book","book","book","book","book","book"]\n' +
  '[[],[10,20],[50,60],[10,40],[5,15],[5,10],[25,55]]'
 *
 * Implement a MyCalendarTwo class to store your events. A new event can be
 * added if adding the event will not cause a triple booking.
 *
 * Your class will have one method, book(int start, int end). Formally, this
 * represents a booking on the half open interval [start, end), the range of
 * real numbers x such that start <= x < end.
 *
 * A triple booking happens when three events have some non-empty intersection
 * (ie., there is some time that is common to all 3 events.)
 *
 * For each call to the method MyCalendar.book, return true if the event can be
 * added to the calendar successfully without causing a triple booking.
 * Otherwise, return false and do not add the event to the calendar.
 * Your class will be called like this: MyCalendar cal = new MyCalendar();
 * MyCalendar.book(start, end)
 *
 * Example 1:
 *
 *
 * MyCalendar();
 * MyCalendar.book(10, 20); // returns true
 * MyCalendar.book(50, 60); // returns true
 * MyCalendar.book(10, 40); // returns true
 * MyCalendar.book(5, 15); // returns false
 * MyCalendar.book(5, 10); // returns true
 * MyCalendar.book(25, 55); // returns true
 * Explanation:
 * The first two events can be booked.  The third event can be double booked.
 * The fourth event (5, 15) can't be booked, because it would result in a
 * triple booking.
 * The fifth event (5, 10) can be booked, as it does not use time 10 which is
 * already double booked.
 * The sixth event (25, 55) can be booked, as the time in [25, 40) will be
 * double booked with the third event;
 * the time [40, 50) will be single booked, and the time [50, 55) will be
 * double booked with the second event.
 *
 *
 *
 *
 * Note:
 *
 *
 * The number of calls to MyCalendar.book per test case will be at most
 * 1000.
 * In calls to MyCalendar.book(start, end), start and end are integers in the
 * range [0, 10^9].
 *
 *
 *
 */

// @lc code=start

/*
 * Time complexity: O(n*n)
 * brute force
 * can be optimized with suffix tree to O(n)
 */
class MyCalendarTwo {
public:
	MyCalendarTwo() {}
	
	bool book(int start, int end) {
		// for already duplicate time, return false
		for (auto &event : duplicateEvents) {
			if (event.second > start && event.first < end) {
				return false;
			}
		}
		for (auto &event : noDuplicateEvents) {
			if (event.second > start && event.first < end) {
				auto overlap = make_pair(max(event.first, start), min(event.second, end));
				duplicateEvents.emplace_back(overlap);
			}
		}
		noDuplicateEvents.emplace_back(make_pair(start, end));
		return true;
	}

private:
	vector<pair<int, int>> noDuplicateEvents;
	vector<pair<int, int>> duplicateEvents;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

int main() {
	MyCalendarTwo MyCalendarTwo;
	PrintSingleResult(MyCalendarTwo.book(10, 20)); // returns true
	PrintSingleResult(MyCalendarTwo.book(50, 60)); // returns true
	PrintSingleResult(MyCalendarTwo.book(10, 40)); // returns true
	PrintSingleResult(MyCalendarTwo.book(5, 15)); // returns false
	PrintSingleResult(MyCalendarTwo.book(5, 10)); // returns true
	PrintSingleResult(MyCalendarTwo.book(25, 55)); // returns true
}
