//
// Created by Yuyang Huang on 7/2/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (50.79%)
 * Likes:    1844
 * Dislikes: 297
 * Total Accepted:    275.9K
 * Total Submissions: 498.7K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given a singly linked list, group all odd nodes together followed by the
 * even nodes. Please note here we are talking about the node number and not
 * the value in the nodes.
 *
 * You should try to do it in place. The program should run in O(1) space
 * complexity and O(nodes) time complexity.
 *
 * Example 1:
 *
 *
 * Input: 1->2->3->4->5->NULL
 * Output: 1->3->5->2->4->NULL
 *
 *
 * Example 2:
 *
 *
 * Input: 2->1->3->5->6->4->7->NULL
 * Output: 2->3->6->7->1->5->4->NULL
 *
 *
 *
 * Constraints:
 *
 *
 * The relative order inside both the even and odd groups should remain as it
 * was in the input.
 * The first node is considered odd, the second node even and so on ...
 * The length of the linked list is between [0, 10^4].
 *
 *
 */

// @lc code=start
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
	 */
	ListNode *oddEvenList(ListNode *head) {
		if (head == nullptr) {
			return nullptr;
		}
		ListNode *oddHead = head, *evenHead = head->next;
		auto odd = oddHead, even = evenHead;
		
		// because we only need evenHead,
		// so the termination criteria is even  and even.next is null
		while (even != nullptr && even->next != nullptr) {
			odd->next=even->next;
			odd=odd->next;
			
			even->next=odd->next;
			even=even->next;
		}
		odd->next=evenHead;
		return oddHead;
	}
};
// @lc code=end

int main(){
	Solution solution;
	
	PrintSingleResult(solution.oddEvenList(nullptr)->toString());
	
	auto node=ListNode::CreateList(1,5);
	PrintSingleResult(solution.oddEvenList(node)->toString());
	
	node=ListNode::CreateList(1,1);
	PrintSingleResult(solution.oddEvenList(node)->toString());
	
	node=ListNode::CreateList(1,2);
	PrintSingleResult(solution.oddEvenList(node)->toString());
	
	vector<int> nums={2,1,3,5,6,4,7};
	node=ListNode::CreateList(nums);
	PrintSingleResult(solution.oddEvenList(node)->toString());
	
	Complete();
}

