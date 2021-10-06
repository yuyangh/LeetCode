//
// Created by Yuyang Huang on 10/10/21.
//

/*
 * 1110. Delete Nodes And Return Forest
 * Medium
 *
 * Given the root of a binary tree, each node in the tree has a distinct value.
 * After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
 * Return the roots of the trees in the remaining forest. You may return the result in any order.
 *
 * Example 1:
 * Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
 * Output: [[1,2,null,4],[6],[7]]
 *
 * Example 2:
 * Input: root = [1,2,4,null,3], to_delete = [3]
 * Output: [[1,2,4]]
 *
 * Constraints:
 * The number of nodes in the given tree is at most 1000
 * Each node has a distinct value between 1 and 1000.
 * to_delete.length <= 1000
 * to_delete contains distinct values between 1 and 1000.
 */

#include "LeetCodeLib.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		vector<TreeNode*> ans;
		unordered_set<int> nodeDel;
		for(int num:to_delete){
			nodeDel.emplace(num);
		}
		helper(root, true, ans, nodeDel);
		return ans;
	}

private:
	void helper(TreeNode* node, bool newRoot, vector<TreeNode*>& ans, unordered_set<int>& nodeDel){
		if(node== nullptr){
			return;
		}
		auto it=nodeDel.find(node->val);
		
		bool beDeleted=(it!=nodeDel.end());
		// curr node will be a new root iff not deleted and is a new root
		if(!beDeleted&&newRoot){
			ans.emplace_back(node);
		}
		helper(node->left, beDeleted, ans, nodeDel);
		helper(node->right, beDeleted, ans, nodeDel);
		
		if(node->left!= nullptr&&nodeDel.count(node->left->val)>0){
			node->left= nullptr;
		}
		if(node->right!= nullptr&&nodeDel.count(node->right->val)>0){
			node->right= nullptr;
		}
	}
};
