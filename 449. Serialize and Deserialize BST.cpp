#include "LeetCodeLib.h"
/*
 * 449. Serialize and Deserialize BST
 *
 * https://leetcode.com/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium
 *
 * Serialization is the process of converting a binaryIndexTree structure or object into a
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
	
	// Decodes your encoded binaryIndexTree to tree.
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

