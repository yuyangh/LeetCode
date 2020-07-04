//
// Created by Yuyang Huang on 7/3/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=957 lang=cpp
 *
 * [957] Prison Cells After N Days
 *
 * https://leetcode.com/problems/prison-cells-after-n-days/description/
 *
 * algorithms
 * Medium (38.18%)
 * Likes:    612
 * Dislikes: 885
 * Total Accepted:    74.7K
 * Total Submissions: 182.9K
 * Testcase Example:  '[0,1,0,1,1,0,0,1]\n7'
 *
 * There are 8 prison cells in a row, and each cell is either occupied or
 * vacant.
 *
 * Each day, whether the cell is occupied or vacant changes according to the
 * following rules:
 *
 *
 * If a cell has two adjacent neighbors that are both occupied or both vacant,
 * then the cell becomes occupied.
 * Otherwise, it becomes vacant.
 *
 *
 * (Note that because the prison is a row, the first and the last cells in the
 * row can't have two adjacent neighbors.)
 *
 * We describe the current state of the prisonÂ in the following way:Â cells[i]
 * == 1 if the i-th cell is occupied, else cells[i] == 0.
 *
 * Given the initial state of the prison, return the state of the prison after
 * N days (and N such changes described above.)
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: cells = [0,1,0,1,1,0,0,1], N = 7
 * Output: [0,0,1,1,0,0,0,0]
 * Explanation:
 * The following table summarizes the state of the prison on each day:
 * Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
 * Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
 * Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
 * Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
 * Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
 * Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
 * Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
 * Day 7: [0, 0, 1, 1, 0, 0, 0, 0]
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
 * Output: [0,0,1,1,1,1,1,0]
 *
 *
 *
 *
 * Note:
 *
 *
 * cells.length == 8
 * cells[i] is in {0, 1}
 * 1 <= N <= 10^9
 *
 *
 *
 *
 */

// @lc code=start

class Solution {
public:
	/*
	 * Time complexity: min( N, 2^K)
	 * use cycle detection and binary operation to transit states
	 */
	vector<int> prisonAfterNDays(vector<int> &cells, int N) {
		unsigned char state = 0;
		
		// convert vector into unsigned char
		for (const auto &cell : cells) {
			state = (state << static_cast<unsigned >(1)) | static_cast<unsigned >(cell);
		}
		
		unordered_map<unsigned char, int> StateMap;
		
		int remainIteration = N;
		bool detectCycle = false;
		
		while (remainIteration > 0) {
			unsigned char nextState = GetNextState(state);
			// detect cycle in state transitions
			if (!detectCycle) {
				if (StateMap.count(state)) {
					int cycle = StateMap[state] - remainIteration;
					remainIteration %= cycle;
					detectCycle = true;
				} else {
					StateMap[state] = remainIteration;
				}
			}
			
			// handle remainIteration is 0 case
			if(remainIteration>0){
				state = nextState;
				remainIteration--;
			}
		}
		
		auto result = ConvertUnsignedCharToBinaryVector(state);
		return result;
	}

private:
	vector<int> ConvertUnsignedCharToBinaryVector(unsigned char state) {
		vector<int> result;
		result.reserve(8);
		for (int i = 0; i < 8; ++i) {
			result.emplace_back(state & static_cast<unsigned >(1));
			state >>= static_cast<unsigned >(1);
		}
		reverse(result.begin(), result.end());
		return result;
	}
	
	unsigned char GetNextState(unsigned char state) {
		unsigned char leftShift = state << static_cast<unsigned >(1);
		unsigned char rightShift = state >> static_cast<unsigned >(1);
		unsigned char nextState = (~static_cast<unsigned >(leftShift xor rightShift))
		                          & static_cast<unsigned >(0b01111110);
		return nextState;
	}
};
// @lc code=end

int main() {
	Solution solution;
	vector<int> cells;
	
	cells = {0, 1, 0, 1, 1, 0, 0, 1};
	PrintVector(solution.prisonAfterNDays(cells, 7));
	
	cells = {1, 0, 0, 1, 0, 0, 1, 0};
	PrintVector(solution.prisonAfterNDays(cells, 1000000000));
	
	cells={1,0,0,0,1,0,0,1};
	PrintVector(solution.prisonAfterNDays(cells, 99));
	
	Complete();
}