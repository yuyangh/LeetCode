#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (29.27%)
 * Likes:    739
 * Dislikes: 60
 * Total Accepted:    75K
 * Total Submissions: 256K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 *
 * The update(i, val) function modifies nums by updating the element at index i
 * to val.
 *
 * Example:
 *
 *
 * Given nums = [1, 3, 5]
 *
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 *
 *
 * Note:
 *
 *
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is
 * distributed evenly.
 *
 *
 */

class SegmentTreeNode {
public:
	SegmentTreeNode(int start, int end) : start_(start), end_(end) {};
	
	int start_;
	int end_;
	int sum_ = 0;
	SegmentTreeNode *left_node_ = nullptr;
	SegmentTreeNode *right_node_ = nullptr;
};

class NumArray {
public:
	explicit NumArray(vector<int> &nums) {
		root = BuildTree(nums, 0, nums.size() - 1);
	}
	
	// O(logn)
	void update(int i, int val) {
		update(root, i, val);
	}
	
	// O(logn)
	int sumRange(int i, int j) {
		return sumRange(root, i, j);
	}

private:
	SegmentTreeNode *root = nullptr;
	
	SegmentTreeNode *BuildTree(vector<int> &nums, int start, int end) {
		if (start > end) {
			return nullptr;
		}
		
		// create the node
		auto node = new SegmentTreeNode(start, end);
		if (start == end) {
			// leaf node
			node->sum_ = nums[start];
			return node;
		} else {
			// internal node
			int mid = (start + end) / 2;
			// create sub nodes
			node->left_node_ = BuildTree(nums, start, mid);
			node->right_node_ = BuildTree(nums, mid + 1, end);
			// update sum
			node->sum_ = node->left_node_->sum_ + node->right_node_->sum_;
		}
		return node;
	}
	
	void update(SegmentTreeNode *node, int pos, int value) {
		if (node->start_ == node->end_) {
			node->sum_ = value;
		} else {
			int mid = (node->start_ + node->end_) / 2;
			// go to update sub node
			if (pos <= mid) {
				update(node->left_node_, pos, value);
			} else {
				update(node->right_node_, pos, value);
			}
			// update node value
			node->sum_ = node->left_node_->sum_ + node->right_node_->sum_;
		}
	}
	
	int sumRange(SegmentTreeNode *node, int start, int end) {
		// if the node match the range
		if (node->start_ == start && node->end_ == end) {
			return node->sum_;
		} else {
			int mid = (node->start_ + node->end_) / 2;
			if (end <= mid) {
				return sumRange(node->left_node_, start, end);
			} else {
				if (start > mid) {
					return sumRange(node->right_node_, start, end);
				} else {
					return sumRange(node->left_node_, start, mid) +
					       sumRange(node->right_node_, mid + 1, end);
				}
			}
		}
	}
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

int main() {
	vector<int> arr = {1, 3, 5};
	
	NumArray numArray(arr);
	int result;
	result = numArray.sumRange(0, 2);
	PrintSingleResult(result);
	numArray.update(1, 2);
	result = numArray.sumRange(0, 2);
	PrintSingleResult(result);
	
	cout<<endl;
	arr = {9, -8};
	NumArray numArray1(arr);
	numArray1.update(0, 3);
	result = numArray1.sumRange(1, 1);
	PrintSingleResult(result);
	result = numArray1.sumRange(0, 1);
	PrintSingleResult(result);
	numArray1.update(1, -3);
	result = numArray1.sumRange(0, 1);
	PrintSingleResult(result);
	return 0;
}

