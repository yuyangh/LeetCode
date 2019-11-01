#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 *
 * https://leetcode.com/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium (46.99%)
 * Likes:    611
 * Dislikes: 46
 * Total Accepted:    58.2K
 * Total Submissions: 123.5K
 * Testcase Example:  '[2,1,3]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary search tree. There
 * is no restriction on how your serialization/deserialization algorithm should
 * work. You just need to ensure that a binary search tree can be serialized to
 * a string and this string can be deserialized to the original tree
 * structure.
 *
 * The encoded string should be as compact as possible.
 *
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
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
class Codec {
public:
	// Encodes a tree to a single string.
	// pre order traversal to copy the structure
	// pre order: self, left, right
	string serialize(TreeNode *root) {
		string str;
		if (root == nullptr) {
			return str;
		} else {
			str += (to_string(root->val) + " ");
		}
		str += (serialize(root->left));
		str += (serialize(root->right));
		return str;
	}
	
	// Decodes your encoded data to tree.
	TreeNode *deserialize(string data) {
		if (data.empty()) {
			return nullptr;
		}
		
		queue<int> nums;
		int num;
		
		stringstream ss(data);
		while (ss >> num) {
			nums.push(num);
		}
		
		stack<TreeNode *> parents;
		TreeNode *result = preOrder(nums, parents);
		return result;
	}
	
	// pre order traversal to restore the structure
	TreeNode *preOrder(queue<int> &nums, stack<TreeNode *> &parents) {
		if (nums.empty()) {
			return nullptr;
		}
		TreeNode *root = new TreeNode(nums.front());
		nums.pop();
		parents.push(root);
		
		TreeNode *temp, *parent;
		
		while (!nums.empty()) {
			parent = parents.top();
			temp = new TreeNode(nums.front());
			nums.pop();
			
			// append either left or right
			if (temp->val < parents.top()->val) {
				parent->left = temp;
				parents.push(temp);
			} else {
				// pop the stack to get the parent
				while (!parents.empty() && parents.top()->val < temp->val) {
					parent = parents.top();
					parents.pop();
				}
				parent->right = temp;
				parents.push(temp);
			}
		}
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


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

string treeNodeToString(TreeNode *root) {
	if (root == nullptr) {
		return "[]";
	}
	
	string output = "";
	queue<TreeNode *> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode *node = q.front();
		q.pop();
		
		if (node == nullptr) {
			output += "null, ";
			continue;
		}
		
		output += to_string(node->val) + ", ";
		q.push(node->left);
		q.push(node->right);
	}
	return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		TreeNode *root = stringToTreeNode(line);
		Codec codec;
		TreeNode *ret = codec.deserialize(codec.serialize(root));
		
		string out = treeNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}
