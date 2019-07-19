#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 *
 * https://leetcode.com/problems/binary-search-tree-iterator/description/
 *
 * algorithms
 * Medium (49.31%)
 * Likes:    1452
 * Dislikes: 247
 * Total Accepted:    213.4K
 * Total Submissions: 432.4K
 * Testcase Example:  '["BSTIterator","next","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]\n' +
  '[[[7,3,15,null,null,9,20]],[null],[null],[null],[null],[null],[null],[null],[null],[null]]'
 *
 * Implement an iterator over a binary search tree (BST). Your iterator will be
 * initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 *
 * Example:
 * BSTIterator iterator = new BSTIterator(root);
 * iterator.next();    // return 3
 * iterator.next();    // return 7
 * iterator.hasNext(); // return true
 * iterator.next();    // return 9
 * iterator.hasNext(); // return true
 * iterator.next();    // return 15
 * iterator.hasNext(); // return true
 * iterator.next();    // return 20
 * iterator.hasNext(); // return false
 *
 *
 * Note:
 * next() and hasNext() should run in average O(1) time and uses O(h) memory,
 * where h is the height of the tree.
 * You may assume that next() call will always be valid, that is, there will be
 * at least a next smallest number in the BST when next() is called.
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
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		addStack(root);
	}
	
	/**
	 * this is ammortized to O(1)
	 * because we at most add n total nodes
	 * with n times calling this function
	 * @return the next smallest number
	 */
	int next() {
		auto node = nodes.top();
		nodes.pop();
		addStack(node->right);
		return node->val;
	}
	
	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !nodes.empty();
	}
	
	/*
	 * add nodes on the straight left
	 */
	void addStack(TreeNode *node) {
		while (node != nullptr) {
			nodes.push(node);
			node = node->left;
		}
	}

private:
	// the nodes stack at most take O(h) memory
	stack<TreeNode *> nodes;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
	int number = 10;
	vector<TreeNode> nodes(number);
	nodes[0].val = 7;
	nodes[1].val = 3;
	nodes[2].val = 15;
	nodes[3].val = 9;
	nodes[4].val = 20;
	
	
	nodes[0].left = &nodes[1];
	nodes[0].right = &nodes[2];
	nodes[2].left = &nodes[3];
	nodes[2].right = &nodes[4];
	
	PrintTree(&nodes[0]);
	int next = -1;
	bool hasNext = false;
	
	BSTIterator iterator = BSTIterator(&nodes[0]);
	next = iterator.next();    // return 3
	PrintSingleResult(next);
	next = iterator.next();    // return 7
	PrintSingleResult(next);
	hasNext = iterator.hasNext(); // return true
	PrintSingleResult(hasNext);
	next = iterator.next();    // return 9
	PrintSingleResult(next);
	hasNext = iterator.hasNext(); // return true
	PrintSingleResult(hasNext);
	next = iterator.next();    // return 15
	PrintSingleResult(next);
	hasNext = iterator.hasNext(); // return true
	PrintSingleResult(hasNext);
	next = iterator.next();    // return 20
	PrintSingleResult(next);
	hasNext = iterator.hasNext(); // return false
	PrintSingleResult(hasNext);
	
	return 0;
}
