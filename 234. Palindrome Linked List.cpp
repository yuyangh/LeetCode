//
// Created by Yuyang Huang on 8/29/21.
//

/*
 * 234. Palindrome Linked List
 * Easy
 *
 * Given the head of a singly linked list, return true if it is a palindrome.
 * Example 1:
 * Input: head = [1,2,2,1]
 * Output: true
 *
 * Example 2:
 * Input: head = [1,2]
 * Output: false
 *
 * Constraints:
 * The number of nodes in the list is in the range [1, 105].
 * 0 <= Node.val <= 9
 * Follow up: Could you do it in O(n) time and O(1) space?
 */

#include "LeetCodeLib.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * Space complexity: O(1) if does not count recursion
	 */
	bool isPalindrome(ListNode *head) {
		ListNode *frontNode = head;
		return helper(head, frontNode);
	}
	
	bool helper(ListNode *node, ListNode *&frontNode) {
		if (node->next == nullptr) {
			return node->val == frontNode->val;
		}
		bool isValid = helper(node->next, frontNode);
		if (!isValid) {
			return false;
		}
		frontNode = frontNode->next;
		return node->val == frontNode->val;
	}
};