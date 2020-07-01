#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.76%)
 * Likes:    5950
 * Dislikes: 1551
 * Total Accepted:    1M
 * Total Submissions: 3.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example:
 *
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 *
 *
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
	/*
	 * Time complexity: O(n)
	 */
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		auto node = ListNode(0);
		auto ptr = &node;
		int carry = 0;
		
		while (l1 != nullptr || l2 != nullptr || carry != 0) {
			int val1 = l1 == nullptr ? 0 : l1->val;
			int val2 = l2 == nullptr ? 0 : l2->val;
			int sum = val1 + val2 + carry;
			ptr->next = new ListNode(sum % 10);
			carry = sum / 10;
			
			// go to the next node
			ptr = ptr->next;
			l1 = l1 == nullptr ? nullptr : l1->next;
			l2 = l2 == nullptr ? nullptr : l2->next;
		}
		
		return node.next;
	}
};

int main() {

}