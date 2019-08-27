#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 *
 * https://leetcode.com/problems/gas-station/description/
 *
 * algorithms
 * Medium (34.29%)
 * Likes:    805
 * Dislikes: 297
 * Total Accepted:    150.4K
 * Total Submissions: 437.1K
 * Testcase Example:  '[1,2,3,4,5]\n[3,4,5,1,2]'
 *
 * There are N gas stations along a circular route, where the amount of gas at
 * station i is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to
 * travel from station i to its next station (i+1). You begin the journey with
 * an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the circuit
 * once in the clockwise direction, otherwise return -1.
 *
 * Note:
 * If there exists a solution, it is guaranteed to be unique.
 * Both input arrays are non-empty and have the same length.
 * Each element in the input arrays is a non-negative integer.
 *
 *
 * Example 1:
 * Input:
 * gas  = [1,2,3,4,5]
 * cost = [3,4,5,1,2]
 *
 * Output: 3
 *
 * Explanation:
 * Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 +
 * 4 = 4
 * Travel to station 4. Your tank = 4 - 1 + 5 = 8
 * Travel to station 0. Your tank = 8 - 2 + 1 = 7
 * Travel to station 1. Your tank = 7 - 3 + 2 = 6
 * Travel to station 2. Your tank = 6 - 4 + 3 = 5
 * Travel to station 3. The cost is 5. Your gas is just enough to travel back
 * to station 3.
 * Therefore, return 3 as the starting index.
 *
 *
 * Example 2:
 * Input:
 * gas  = [2,3,4]
 * cost = [3,4,3]
 *
 * Output: -1
 *
 * Explanation:
 * You can't start at station 0 or 1, as there is not enough gas to travel to
 * the next station.
 * Let's start at station 2 and fill up with 4 unit of gas.
 * Your tank = 0 + 4 = 4
 * Travel to station 0. Your tank = 4 - 3 + 2 = 3
 * Travel to station 1. Your tank = 3 - 3 + 3 = 3
 * You cannot travel back to station 2, as it requires 4 unit of gas but you
 * only have 3.
 * Therefore, you can't travel around the circuit once no matter where you
 * start.
 */
class Solution {
public:
	/*
	 * If the total number of gas is bigger than the total number of cost. There must be a solution.
	 * The tank should never be negative, so restart whenever there is a negative number.
	 * the question guaranteed that the solution is unique(The first one I found is the right one).
	 */
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int start = 0, tank = 0, total = 0;
		for (int i = 0; i < gas.size(); ++i) {
			int gain = gas[i] - cost[i];
			total += gain;
			tank += gain;
			
			// if tank is not enough, restart
			if (tank < 0) {
				start = i + 1;
				tank = 0;
			}
		}
		
		// if total gas not enough,
		// then definitely not solution
		if (total >= 0) {
			return start;
		} else {
			return -1;
		}
	}
};


void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> gas = stringToIntegerVector(line);
		getline(cin, line);
		vector<int> cost = stringToIntegerVector(line);
		
		int ret = Solution().canCompleteCircuit(gas, cost);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}