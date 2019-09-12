#include "LeetCodeLib.h"

/*
 * n    mapping
 * 1    1
 * 2    10
 * 3    1001
 * 4    10010110
 */
int mapping(int n, int k) {
	if (n == 1) {
		return 1;
	}
	int result = mapping(n - 1, k / 2);
	if (result == 1) {
		// 1:10
		if (k % 2 == 0) {
			return 1;
		} else {
			return 0;
		}
	} else {
		// 0:01
		if (k % 2 == 0) {
			return 0;
		} else {
			return 1;
		}
	}
}


int main() {
	vector<vector<int>> result = {{},
	                              {1},
	                              {1, 0},
	                              {1, 0, 0, 1},
	                              {1, 0, 0, 1, 0, 1, 1, 0}};
	PrintSingleResult(mapping(1, 0) == result[1][0]);
	PrintSingleResult(mapping(2, 0)== result[2][0]);
	PrintSingleResult(mapping(2, 1)== result[2][1]);
	PrintSingleResult(mapping(3, 2)== result[3][2]);
	PrintSingleResult(mapping(3, 3)== result[3][3]);
	PrintSingleResult(mapping(4, 5)== result[4][5]);
	PrintSingleResult(mapping(4, 7)== result[4][7]);
	return 0;
}