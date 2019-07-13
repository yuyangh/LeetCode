#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (35.81%)
 * Likes:    1304
 * Dislikes: 118
 * Total Accepted:    143.6K
 * Total Submissions: 397K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 *
 * Example:
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 *
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 *
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<TreeNode *> generateTrees(int n) {
		if (n == 0) {
			return {};
		}
		vector<TreeNode *> result;
		result = generate(1, n);
		return result;
	}

private:
	/**
	 * @param start the smallest value in this subtree
	 * @param end largest value in this subtree
	 * @return list of possible subtrees
	 */
	vector<TreeNode *> generate(int start, int end) {
		// base case
		if (start > end) {
			return {nullptr};
		}
		if (start == end) {
			return {new TreeNode(start)};
		}
		
		vector<TreeNode *> level;
		for (int num = start; num <= end; ++num) {
			// generate list of left subtrees and right subtrees
			vector<TreeNode *> left = generate(start, num - 1);
			vector<TreeNode *> right = generate(num + 1, end);
			// every left subtree can match one right subtree
			for (auto &left_item : left) {
				for (auto &right_item : right) {
					// node value is larger than all left,
					// and smaller than all right
					level.emplace_back(new TreeNode(num));
					level.back()->left = left_item;
					level.back()->right = right_item;
				}
			}
		}
		return level;
	}
};

int main() {
	Solution solution;
	int num = 3;
	auto trees = solution.generateTrees(num);
	int count = 0;
	for (const auto &tree : trees) {
		PrintTree(tree);
		++count;
		cout << endl;
	}
	printf("total trees:%d \n", count);
	return 0;
}