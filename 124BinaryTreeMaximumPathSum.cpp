#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (30.11%)
 * Likes:    1707
 * Dislikes: 127
 * Total Accepted:    201.6K
 * Total Submissions: 665.4K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty binary tree, find the maximum path sum.
 *
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3]
 *
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 *
 * Output: 6
 *
 *
 * Example 2:
 *
 *
 * Input: [-10,9,20,null,null,15,7]
 *
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 *
 * Output: 42
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
 *
 * recursively to find max with single child + current + parent, or current with two children
 */
class Solution {
public:
	int maxPathSum(TreeNode *root) {
		if (root == nullptr) {
			return INT_MIN;
		}
		path_max_ = INT_MIN;
		traverse(root);
		return path_max_;
	}

private:
	int path_max_;
	
	int traverse(TreeNode *node) {
		if (node == nullptr) {
			printf("should not exist\n");
			return 0;
		}
		int left_increase = 0, right_increase = 0;
		
		// get increase for choosing left or right
		if (node->left != nullptr) {
			left_increase = traverse(node->left);
		}
		if (node->right != nullptr) {
			right_increase = traverse(node->right);
		}
		
		int max_single_increase = max(left_increase, right_increase);
		int both_increase = left_increase + right_increase;
		int max_children_increase = max(max_single_increase, both_increase);
		
		// update path_max_ for a path
		path_max_ = max({path_max_, node->val, node->val + max_children_increase});
		
		// update max path either choosing only this node or with one child
		max_single_increase = max(max_single_increase + node->val, node->val);
		
		return max_single_increase;
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

TreeNode *stringToTreeNode(string input) {
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	if (!input.size()) {
		return nullptr;
	}
	
	string item;
	stringstream ss;
	ss.str(input);
	
	getline(ss, item, ',');
	TreeNode *root = new TreeNode(stoi(item));
	queue<TreeNode *> nodeQueue;
	nodeQueue.push(root);
	
	while (true) {
		TreeNode *node = nodeQueue.front();
		nodeQueue.pop();
		
		if (!getline(ss, item, ',')) {
			break;
		}
		
		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int leftNumber = stoi(item);
			node->left = new TreeNode(leftNumber);
			nodeQueue.push(node->left);
		}
		
		if (!getline(ss, item, ',')) {
			break;
		}
		
		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int rightNumber = stoi(item);
			node->right = new TreeNode(rightNumber);
			nodeQueue.push(node->right);
		}
	}
	return root;
}

int main() {
	string line;
	while (getline(cin, line)) {
		TreeNode *root = stringToTreeNode(line);
		
		int ret = Solution().maxPathSum(root);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}
