#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (46.35%)
 * Likes:    1807
 * Dislikes: 69
 * Total Accepted:    206.6K
 * Total Submissions: 441.9K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 *
 * Example:
 *
 *
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 *
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 *
 *
 */
class Solution {
public:
	int numTrees(int n) {
		return iterative(n);
	}

private:
	int iterative(int num) {
		// base case
		vector<int> records = {1, 1};
		
		int level = records.size();
		while (level <= num && num + 1 > records.size()) {
			int num_arrange = 0;
			int left = level - 1, right = 0;
			for (int i = 0; i < level; ++i) {
				// asymmetric scenario can swap two sides
				if (left > right) {
					num_arrange += 2 * (records[left] * records[right]);
				} else {
					// symmetric scenario
					if (left == right) {
						num_arrange += (records[left] * records[right]);
					} else {
						break;
					}
				}
				--left;
				++right;
			}
			records.emplace_back(num_arrange);
			++level;
		}
		return records[num];
	}
};


int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int n = stringToInteger(line);
		
		int ret = Solution().numTrees(n);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}

