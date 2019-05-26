

#ifndef LEETCODE_LEETCODELIB_H
#define LEETCODE_LEETCODELIB_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <assert.h>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	
	ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //LEETCODE_LEETCODELIB_H
