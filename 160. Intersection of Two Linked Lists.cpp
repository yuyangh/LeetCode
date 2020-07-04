//
// Created by Yuyang Huang on 7/3/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (36.18%)
 * Likes:    3542
 * Dislikes: 412
 * Total Accepted:    465.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3'
 *
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 *
 * For example, the following two linked lists:
 *
 *
 * begin to intersect at node c1.
 *
 *
 *
 * Example 1:
 *
 *
 *
 * Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA =
 * 2, skipB = 3
 * Output: Reference of the node with value = 8
 * Input Explanation: The intersected node's value is 8 (note that this must
 * not be 0 if the two lists intersect). From the head of A, it reads as
 * [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2
 * nodes before the intersected node in A; There are 3 nodes before the
 * intersected node in B.
 *
 *
 *
 * Example 2:
 *
 *
 *
 * Input: intersectValÂ = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3,
 * skipB = 1
 * Output: Reference of the node with value = 2
 * Input Explanation:Â The intersected node's value is 2 (note that this must
 * not be 0 if the two lists intersect). From the head of A, it reads as
 * [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes
 * before the intersected node in A; There are 1 node before the intersected
 * node in B.
 *
 *
 *
 *
 * Example 3:
 *
 *
 *
 * Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB =
 * 2
 * Output: null
 * Input Explanation: From the head of A, it reads as [2,6,4]. From the head of
 * B, it reads as [1,5]. Since the two lists do not intersect, intersectVal
 * must be 0, while skipA and skipB can be arbitrary values.
 * Explanation: The two lists do not intersect, so return null.
 *
 *
 *
 *
 * Notes:
 *
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function
 * returns.
 * You may assume there are no cycles anywhere in the entire linked
 * structure.
 * Each valueÂ on each linked list is in the range [1, 10^9].
 * Your code should preferably run in O(n) time and use only O(1) memory.
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
	 * Time complexity: O(1)
	 * Space complexity: O(1)
	 */
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		auto a = headA, b = headB;
		auto aNum = 0, bNum = 0;
		if (a == nullptr || b == nullptr) {
			return nullptr;
		}
		
		// count length of the list
		while (a != nullptr && a->next != nullptr) {
			a = a->next;
			aNum++;
		}
		while (b != nullptr && b->next != nullptr) {
			b = b->next;
			bNum++;
		}
		
		// no intersection
		if (a != b) {
			return nullptr;
		}
		
		a = headA;
		b = headB;
		if (aNum >= bNum) {
			for (int i = 0; i < aNum - bNum; ++i) {
				a = a->next;
			}
		} else {
			for (int i = 0; i < bNum - aNum; ++i) {
				b = b->next;
			}
		}
		
		// find intersection
		while (a != nullptr) {
			if (a == b) {
				return a;
			}
			a = a->next;
			b = b->next;
		}
		
		return nullptr;
	}
};
// @lc code=end
