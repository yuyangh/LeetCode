//
// Created by Yuyang Huang on 7/14/20.
//

#include "LeetCodeLib.h"

/*
 * Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.
 *
 * Example 1:
 * Input: hour = 12, minutes = 30
 * Output: 165
 *
 * Example 2:
 * Input: hour = 3, minutes = 30
 * Output: 75
 *
 * Example 3:
 * Input: hour = 3, minutes = 15
 * Output: 7.5
 *
 * Example 4:
 * Input: hour = 4, minutes = 50
 * Output: 155
 *
 * Example 5:
 * Input: hour = 12, minutes = 0
 * Output: 0
 *
 * Constraints:
 * 1 <= hour <= 12
 * 0 <= minutes <= 59
 * Answers within 10^-5 of the actual value will be accepted as correct.
 */

class Solution {
public:
	/*
	 * Time complexity: O(1)
	 */
	double angleClock(int hour, int minutes) {
		double mins = minutesAngle(minutes);
		double hours = hourAngle(hour, minutes);
		double angle = fabs(max(mins, hours) - min(mins, hours));
		angle = angle > 180 ? 360 - angle : angle;
		return angle;
	}

private:
	double minutesAngle(int minutes) {
		return minutes * 6;
	}
	
	double hourAngle(int hour, int minutes) {
		return (hour % 12 + 1.0 * minutes / 60.0) * (360 / 12);
	}
};

int main() {
	Solution solution;
	PrintSingleResult(solution.angleClock(12, 30));
	PrintSingleResult(solution.angleClock(3, 30));
	PrintSingleResult(solution.angleClock(3, 15));
	PrintSingleResult(solution.angleClock(4, 50));
	PrintSingleResult(solution.angleClock(12, 00));
	
	Complete();
}