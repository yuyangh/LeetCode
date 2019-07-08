#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (34.47%)
 * Likes:    920
 * Dislikes: 124
 * Total Accepted:    188.7K
 * Total Submissions: 542.8K
 * Testcase Example:  '{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}'
 *
 * Given a binary tree
 *
 *
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 *
 *
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 *
 *
 * Example:
 *
 *
 *
 *
 * Input:
 * {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}
 *
 * Output:
 * {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}
 *
 * Explanation: Given the above binary tree (Figure A), your function should
 * populate each next pointer to point to its next right node, just like in
 * Figure B.
 *
 *
 *
 *
 * Note:
 *
 *
 * You may only use constant extra space.
 * Recursive approach is fine, implicit stack space does not count as extra
 * space for this problem.
 *
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
	// The first level (root) is connected already,
	// so connect the next level,
	// and then walk through the linked list created and so on.
	Node *connect(Node *root) {
		Node *curr = root, *next_level_head, *next_level_ptr = nullptr;
		while (curr != nullptr) {
			// find first not nullptr child as next level head
			next_level_head = nullptr;
			for (Node *node = curr; node != nullptr; node = node->next) {
				if (node->left != nullptr) {
					next_level_head = node->left;
					break;
				}
				if (node->right != nullptr) {
					next_level_head = node->right;
					break;
				}
			}
			next_level_ptr = next_level_head;
			
			// traverse current level to link next level together
			while (curr != nullptr) {
				// avoid self loop
				if (curr->left != nullptr && curr->left != next_level_ptr) {
					next_level_ptr->next = curr->left;
					next_level_ptr = next_level_ptr->next;
				}
				if (curr->right != nullptr && curr->right != next_level_ptr) {
					next_level_ptr->next = curr->right;
					next_level_ptr = next_level_ptr->next;
				}
				curr = curr->next;
			}
			
			// go to next level
			curr = next_level_head;
		}
		return root;
	}
};

int main() {
	int size = 10;
	vector<Node> nodes(size);
	for (int i = 0; i < size; ++i) {
		nodes[i]=Node(i);
	}
	nodes[0].left=&nodes[1];
	nodes[1].right=&nodes[2];
	
	Solution solution;
	auto tree = solution.connect(&nodes[0]);
	vector<vector<int>> result;
	Node::levelOrder(result,tree);
	PrintVectorVector(result);
	return 0;
}

