//
// Created by Yuyang Huang on 1/2/22.
//

/*
 * 351. Android Unlock Patterns
 * Medium
 *
 * Android devices have a special lock screen with a 3 x 3 grid of dots.
 * Users can set an "unlock pattern" by connecting the dots in a specific sequence,
 * forming a series of joined line segments where each segment's endpoints are two consecutive dots in the sequence.
 * A sequence of k dots is a valid unlock pattern if both of the following are true:
 *
 * All the dots in the sequence are distinct.
 * If the line segment connecting two consecutive dots in the sequence passes through the center of any other dot,
 * the other dot must have previously appeared in the sequence.
 * No jumps through the center non-selected dots are allowed.
 * For example, connecting dots 2 and 9 without dots 5 or 6 appearing beforehand is valid
 * because the line from dot 2 to dot 9 does not pass through the center of either dot 5 or 6.
 * However, connecting dots 1 and 3 without dot 2 appearing beforehand is invalid
 * because the line from dot 1 to dot 3 passes through the center of dot 2.
 * Here are some example valid and invalid unlock patterns:
 *
 * The 1st pattern [4,1,3,6] is invalid because the line connecting dots 1 and 3 pass through dot 2,
 * but dot 2 did not previously appear in the sequence.
 * The 2nd pattern [4,1,9,2] is invalid because the line connecting dots 1 and 9 pass through dot 5,
 * but dot 5 did not previously appear in the sequence.
 * The 3rd pattern [2,4,1,3,6] is valid because it follows the conditions.
 * The line connecting dots 1 and 3 meets the condition because dot 2 previously appeared in the sequence.
 * The 4th pattern [6,5,4,1,9,2] is valid because it follows the conditions.
 * The line connecting dots 1 and 9 meets the condition because dot 5 previously appeared in the sequence.
 * Given two integers m and n, return the number of unique and valid unlock patterns of the Android grid lock screen
 * that consist of at least m keys and at most n keys.
 * Two unlock patterns are considered unique if there is a dot in one sequence that is not in the other,
 * or the order of the dots is different.
 *
 * Example 1:
 * Input: m = 1, n = 1
 * Output: 9
 *
 * Example 2:
 * Input: m = 1, n = 2
 * Output: 65
 *
 * Constraints:
 * 1 <= m, n <= 9
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(9^n)
	 * add 1 to the DFS whenever the function with length<n && length >=m is called
	 * It is because for all leaves, they have one valid parent node counted to the result
	 */
	int numberOfPatterns(int m, int n) {
		// jump array represents number to skip between two pairs
		vector<vector<int>> jumps(10, vector<int>(10, 0));
		jumps[1][3] = jumps[3][1] = 2;
		jumps[1][7] = jumps[7][1] = 4;
		jumps[3][9] = jumps[9][3] = 6;
		jumps[7][9] = jumps[9][7] = 8;
		jumps[1][9] = jumps[9][1] = jumps[2][8] = jumps[8][2] = jumps[4][6] = jumps[6][4] = jumps[3][7] = jumps[7][3] = 5;
		
		vector<bool> visited(10, false);
		
		int result = 0;
		// 1, 3, 7, 9 are symmetric
		result += helper(jumps, visited, m, n, 1, 1) * 4;
		result += helper(jumps, visited, m, n, 2, 1) * 4;
		result += helper(jumps, visited, m, n, 5, 1);
		return result;
	}

private:
	int helper(vector<vector<int>> &jumps, vector<bool> &visited, int low, int high, int curr, int step) {
		if (step > high) {
			return 0;
		}
		if (step == high) {
			return 1;
		}
		int result = 0;
		visited[curr] = true;
		for (int i = 1; i <= 9; i++) {
			// if not visited and either not jump or jump visited
			if (!visited[i] && (jumps[curr][i] == 0 || visited[jumps[curr][i]])) {
				result += helper(jumps, visited, low, high, i, step + 1);
			}
		}
		visited[curr] = false;
		// add 1 to the result whenever the function with length<n && length >=m is called
		return result + (step >= low ? 1 : 0);
	}
};

int main() {
	Solution solution;
	int ans;
	PrintSingleResult(solution.numberOfPatterns(1, 1));
	PrintSingleResult(solution.numberOfPatterns(1, 2));
}