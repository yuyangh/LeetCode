#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (42.59%)
 * Likes:    674
 * Dislikes: 24
 * Total Accepted:    186.9K
 * Total Submissions: 438.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number
 * 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 * Input: [1,2,3]
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * Output: 25
 * Explanation:
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Therefore, sum = 12 + 13 = 25.
 *
 * Example 2:
 * Input: [4,9,0,5,1]
 * ⁠   4
 * ⁠  / \
 * ⁠ 9   0
 * / \
 * 5   1
 * Output: 1026
 * Explanation:
 * The root-to-leaf path 4->9->5 represents the number 495.
 * The root-to-leaf path 4->9->1 represents the number 491.
 * The root-to-leaf path 4->0 represents the number 40.
 * Therefore, sum = 495 + 491 + 40 = 1026.
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
	/*
	 * Time complexity: O(n)
	 * dfs
	 */
	int sumNumbers(TreeNode *root) {
		sum = 0;
		vector<int> result;
		traverse(result, root, 0);
		return sum;
	}

private:
	
	int sum;
	
	void traverse(vector<int> &result, TreeNode *node, int value) {
		if (node == nullptr) {
			return;
		}
		// update the current value
		value *= 10;
		value += node->val;
		// leaf node update sum
		if (node->left == nullptr && node->right == nullptr) {
			sum += value;
			return;
		}
		// go to next node
		traverse(result, node->left, value);
		traverse(result, node->right, value);
	}
};
