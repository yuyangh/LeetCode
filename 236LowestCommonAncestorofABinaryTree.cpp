#include "LeetCodeLib.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<TreeNode*> nodes;
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// It's recursive and expands the meaning of the function.
		// If the current (sub)tree contains both p and q,
		// then the function result is their LCA.
		// If only one of them is in that subtree,
		// then the result is that one of them.
		// If neither are in that subtree, the result is null
		if (root==nullptr || root == p || root == q){
			return root;
		}
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if(left==nullptr){
			return right;
		}else{
			if(right==nullptr){
				return left;
			}else{
				return root;
			}
		}
	}
	
	// heap implementation, use too much memory when unbalanced
	bool debug=false;
	// TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	// 	if(root==nullptr){
	// 		return nullptr;
	// 	}
	// 	if(debug){
	// 		if(p==nullptr){
	// 			cout<<"p null"<<endl;;
	// 		}
	// 		if(q==nullptr){
	// 			cout<<"q null"<<endl;;
	// 		}
	// 	}
	//
	// 	auto level=storeNodes(root,p->val,q->val);
	// 	if(debug){
	// 		cout<<level.first<<"\t"<<level.second<<endl;
	// 	}
	// 	int index=getCommonParent(level);
	// 	return nodes[index];
	// }
	//
	// pair<int,int> storeNodes(TreeNode* node,int pval, int qval ){
	// 	int ppos=-1,qpos=-1;
	// 	nodes.push_back(node);
	// 	// since two nodes must exist in tree
	// 	for(int i=0;true;i++){
	// 		if(debug){
	// 			cout<<"index:"<<i<<"\t";
	// 			cout<<"p pos:"<<ppos<<"\tq pos:"<<qpos;
	// 			if(nodes[i]){
	// 				cout<<"\t node value:"<<nodes[i]->val;
	// 			}
	// 			cout<<endl;
	// 		}
	//
	// 		if(nodes[i]){
	// 			if(nodes[i]->val==pval){
	// 				ppos=i;
	// 			}
	// 			if(nodes[i]->val==qval){
	// 				qpos=i;
	// 			}
	// 		}
	// 		if(ppos>=0&&qpos>=0){
	// 			break;
	// 		}
	// 		if(nodes[i]!=nullptr){
	// 			nodes.push_back(nodes[i]->left);
	// 		}else{
	// 			nodes.push_back(nullptr);
	// 		}
	// 		if(nodes[i]!=nullptr){
	// 			nodes.push_back(nodes[i]->right);
	// 		}else{
	// 			nodes.push_back(nullptr);
	// 		}
	// 	}
	// 	return make_pair(ppos,qpos);
	// }
	//
	// int getCommonParent(pair<int, int> level){
	// 	int a=level.first;
	// 	int b=level.second;
	// 	while(abs(a-b)!=0){
	// 		if(a>b){
	// 			a=(a-1)/2;
	// 		}else{
	// 			b=(b-1)/2;
	// 		}
	// 	}
	// 	return a;
	// }
};

/*
* [3,5,1,6,2,0,8,null,null,7,4]
* 5
* 4
*/

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	if (!input.size()) {
		return nullptr;
	}
	
	string item;
	stringstream ss;
	ss.str(input);
	
	getline(ss, item, ',');
	TreeNode* root = new TreeNode(stoi(item));
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);
	
	while (true) {
		TreeNode* node = nodeQueue.front();
		nodeQueue.pop();
		
		if (!getline(ss, item, ',')) {
			break;
		}
		
		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int leftNumber = stoi(item);
			node->left = new TreeNode(leftNumber);
			nodeQueue.push(node->left);
		}
		
		if (!getline(ss, item, ',')) {
			break;
		}
		
		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int rightNumber = stoi(item);
			node->right = new TreeNode(rightNumber);
			nodeQueue.push(node->right);
		}
	}
	return root;
}

string treeNodeToString(TreeNode* root) {
	if (root == nullptr) {
		return "[]";
	}
	
	string output = "";
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()) {
		TreeNode* node = q.front();
		q.pop();
		
		if (node == nullptr) {
			output += "null, ";
			continue;
		}
		
		output += to_string(node->val) + ", ";
		q.push(node->left);
		q.push(node->right);
	}
	return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		TreeNode* root = stringToTreeNode(line);
		getline(cin, line);
		TreeNode* p = stringToTreeNode(line);
		getline(cin, line);
		TreeNode* q = stringToTreeNode(line);
		
		TreeNode* ret = Solution().lowestCommonAncestor(root, p, q);
		
		string out = treeNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}