#include "LeetCodeLib.h"

class SegmentTreeNode {
public:
	SegmentTreeNode(int start, int end) : start_(start), end_(end) {};
	
	int start_;
	int end_;
	unsigned int sum_ = 0;
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
			node->sum_ = node->left_node_->sum_ xor node->right_node_->sum_;
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
			node->sum_ = node->left_node_->sum_ xor node->right_node_->sum_;
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
					return sumRange(node->left_node_, start, mid) xor
					       sumRange(node->right_node_, mid + 1, end);
				}
			}
		}
	}
};

unsigned int XORSum(unsigned int num) {
	unsigned int sum = 0;
	while (num > 0) {
		sum += num & 1;
		num >>= 1;
	}
	return sum ;
}

int XORSum(NumArray &numArray, int size) {
	int max_sum = 0;
	for (int len = size; len > 0; --len) {
		for (int i = 0; i <= size - len; ++i) {
			int num = numArray.sumRange(i, i + len - 1);
			int sum=XORSum(num);
			if (sum% 2 == 0) {
				return sum;
			}
		}
	}
	return max_sum;
}


int main() {
	int lines = 0;
	string line;
	getline(cin, line);
	lines = stoi(line);
	for (int i = 0; i < lines; ++i) {
		getline(cin, line);
		stringstream ss(line);
		int N, Q;
		ss >> N;
		ss >> Q;
		vector<int> arr;
		arr.reserve(N);
		getline(cin, line);
		ss.clear();
		ss.str(line);
		for (int index = 0; index < N; ++index) {
			int num;
			ss >> num;
			arr.emplace_back(num);
		}
		
		NumArray numArray(arr);
		
		cout<<"Case #"<<i+1<<":";
		for (int modification = 0; modification < Q; ++modification) {
			getline(cin, line);
			ss.clear();
			ss.str(line);
			int index, new_number;
			ss >> index;
			ss >> new_number;
			numArray.update(index, new_number);
			int sum=XORSum(numArray,N);
			cout<<" "<<sum;
		}
		cout<<endl;
	}
	return 0;
	// https://img-blog.csdnimg.cn/20190408221756861.png
}