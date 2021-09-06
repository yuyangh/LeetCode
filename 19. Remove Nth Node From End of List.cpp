#include "LeetCodeLib.h"
/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * 19. Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 *
 * Example:
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 *
 * Note:
 * Given n will always be valid.
 *
 * Follow up:
 * Could you do this in one pass?
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		listHead = head;
		int distToEnd = -1;
		remove(nullptr, head, distToEnd, n);
		return listHead;
	}

private:
	ListNode *listHead;
	
	// save parent node, next node,
	// and distance to enable remember parent
	void remove(ListNode *parent, ListNode *node, int &distToEnd, int n) {
		// base case, count from end of the list
		if (node == nullptr) {
			distToEnd = 0;
			return;
		}
		
		// recursion
		remove(node, node->next, distToEnd, n);
		++distToEnd;
		// delete the node
		if (distToEnd == n) {
			// handle list head
			if (listHead == node) {
				listHead = node->next;
			} else {
				parent->next = node->next;
			}
			delete node;
		}
		if (distToEnd >= n) {
			return;
		}
	}
};
