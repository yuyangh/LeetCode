#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (34.81%)
 * Likes:    1074
 * Dislikes: 144
 * Total Accepted:    131.9K
 * Total Submissions: 374K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given a complete binary tree, count the number of nodes.
 *
 * Note:
 *
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2^h nodes inclusive at the last level
 * h.
 *
 * Example:
 *
 *
 * Input:
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠/ \  /
 * 4  5 6
 *
 * Output: 6
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
	 * O(log(n)*log(n))
	 */
	int countNodes(TreeNode *root) {
		return recursion(root);
	}

private:
	int recursion(TreeNode *node) {
		if (node == nullptr) {
			return 0;
		}
		int num_nodes = 0;
		int left_height = CalculateTreeHeight(node->left);
		int right_height = CalculateTreeHeight(node->right);
		
		if (left_height == right_height) {
			// right side may not all have equal height
			num_nodes += CalculateNumNodes(left_height);
			num_nodes += recursion(node->right);
		} else {
			// right side must has left height - 1,so check left side
			num_nodes += CalculateNumNodes(right_height);
			num_nodes += recursion(node->left);
		}
		// add the count of self
		return num_nodes + 1;
	}
	
	int CalculateNumNodes(int height) {
		return static_cast<int>(pow(2, height) - 1);
	}
	
	int CalculateTreeHeight(TreeNode *node) {
		if (node == nullptr) {
			return 0;
		}
		return 1 + CalculateTreeHeight(node->left);
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
		
		int ret = Solution().countNodes(root);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}