#include "LeetCodeLib.h"
/*
 * 24. Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 * Example:
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
	ListNode *swapPairs(ListNode *head) {
		if (head == nullptr) {
			return nullptr;
		}
		ListNode *curr = head, *nextNode, *nextCurr, *prev = nullptr;
		
		// go two pointers
		while (curr != nullptr) {
			nextNode = curr->next;
			if (nextNode != nullptr) {
				nextCurr = nextNode->next;
				// check header
				if (prev != nullptr) {
					prev->next = nextNode;
				} else {
					head = nextNode;
				}
				nextNode->next = curr;
				curr->next = nextCurr;
				prev = curr;
				curr = nextCurr;
			} else {
				return head;
			}
		}
		return head;
	}
};

