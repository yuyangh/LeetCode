# Summary
## LinkedList
* 如果更改结构，可以考虑用多个temp pointer来记住之前的 e.g. 206

## Binary Tree
* 寻找数值的时候，可以用recursion来找，把是否存在的信息保存在return里面 e.g. 236
* heap结构适用于tree左右较为平衡的结构
* 改变结构的时候，recursion可以用temp variable来记住parent， e.g. 114

## Greedy algorithm
* 思考schedule的时候列出各种样式来尝试 e.g.452
* 创建extra variable来记住当前状态 e.g.376

## string operation
* 如果用int来保存string里面的字符的时候，要注意special character也会被保存为数字，和数字信息相冲突！ e.g.224

## custom comparator
* 当持续不断地添加并且获取最大/最小的数值的时候，考虑priority_queue
* priority_queue<int, vector<int>, less<int>> 是把大的数字放在前面 e.g. 295
* auto ListNodeComp=[](ListNode *lhs, ListNode *rhs){return lhs->val > rhs->val;} // 把小的放在前面
* priority_queue<ListNode* vector<ListNode*>, decltype<ListNodeComp>> pq(ListNodeComp); // e.g. 023
    * decltyple(comp) is a function, similar to greater<int>
    * yourself defined comparator is a function object, which is still an object
    * comp class we usually used has its own 括号运算符, so we do not need to pass comparator object to pq
    * self-defined function's 括号运算符 replies on function
    * so this decltype(comp) needs its comp object
