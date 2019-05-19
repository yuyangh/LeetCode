#include "LeetCodeLib.h"

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
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode *head = nullptr, *tail=head, *ptr;
		// how to write lamda comparator, very important
		auto ListNodeComp = [](const ListNode *lhs, const ListNode *rhs) {
			return lhs->val > rhs->val;
		};
		
		// how to implement lamda comparator with pq
		/*
		 * decltype(comp) is a function
		 * your self defined comparator is a function（object）, which is still an object
		 * comp class we usually used has its own 括号运算符, so we do not need to pass comparator object
		 * function这个type本身括号运算符依赖于具体的function
		 * so this function needs its object
		 */
		priority_queue<ListNode *, vector<ListNode *>, decltype(ListNodeComp)> pq(ListNodeComp);
		for (auto node:lists) {
			if (node != nullptr) {
				pq.push(node);
			}
		}
		while (!pq.empty()) {
			ptr = pq.top();
			if (head == nullptr) {
				head = ptr;
				tail = ptr;
			} else {
				tail->next = ptr;
				tail = ptr;
			}
			pq.pop();
			ptr = ptr->next;
			if (ptr != nullptr) {
				pq.push(ptr);
			}
		}
		return head;
	}
};