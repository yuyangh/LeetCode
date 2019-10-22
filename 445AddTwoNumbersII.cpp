//
// Created by Yuyang Huang on 10/21/19.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (51.62%)
 * Likes:    903
 * Dislikes: 120
 * Total Accepted:    112.4K
 * Total Submissions: 217.7K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 *
 *
 *
 * Example:
 *
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 *
 *
 */

// @lc code=start
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
	 * time complexity: O(n), space complexity:O(n)
	 * store all contents of list node into stack
	 */
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		
		stack<int> left;
		stack<int> right;
		
		ListNode *l1node = l1;
		ListNode *l2node = l2;
		while (l1node != nullptr) {
			left.emplace(l1node->val);
			l1node = l1node->next;
		}
		
		while (l2node != nullptr) {
			right.emplace(l2node->val);
			l2node = l2node->next;
		}
		
		int carry = 0;
		ListNode *result = nullptr;
		while (!left.empty() || !right.empty()) {
			int leftNum = 0, rightNum = 0;
			if (!left.empty()) {
				leftNum = left.top();
				left.pop();
			}
			
			if (!right.empty()) {
				rightNum = right.top();
				right.pop();
			}
			
			int sum = carry + leftNum + rightNum;
			carry = sum / 10;
			auto node = new ListNode(sum % 10);
			node->next = result;
			result = node;
			
		}
		if (carry != 0) {
			auto node = new ListNode(carry);
			node->next = result;
			result = node;
		}
		
		return result;
	}
};
// @lc code=end

