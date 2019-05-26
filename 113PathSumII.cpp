#include "LeetCodeLib.h"
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
	vector<int> traverseNum;
	vector<vector<int>> result;
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if(root==nullptr){
			return result;
		}
		traverse(root,0,sum);
		return result;
	}
	
	void traverse(TreeNode* node, int sum, int goal){
		// node->val is int, the tree may have goal-> -1 -> +1, so cannot use this
		// if(node->val+sum>goal){
		//     return;
		// }
		traverseNum.push_back(node->val);
		if(node->val+sum==goal){
			if(node->left==nullptr&&node->right==nullptr){
				result.push_back(traverseNum);
			}else{
				// traverseNum.pop_back();
				// return;
			}
		}
		if(node->left!=nullptr){
			traverse(node->left,sum+node->val,goal);
		}
		if(node->right!=nullptr){
			traverse(node->right,sum+node->val,goal);
		}
		traverseNum.pop_back();
	}
};

/*
* [5,4,8,11,null,13,4,7,2,null,null,5,1]
* 22
*/