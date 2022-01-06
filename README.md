# Summary
Summary of LeetCode problems 

## Overall
- 把要删除item的放到额外的set里面，然后创建结果的时候遇到set里面的item就忽略 e.g. 1249
- undefined behavior 要么是segmentation fault，要么是需要初始化
- average runtime 就是amortized runtime,注意这个和runtime的差异
- 题目没有思路的时候考虑极端情况，或许会有启发
- 避免int 和 .size()-1 比较（可能会有unsigned overflow），最好改成左侧+1
- lamda function []里面的variable是不能中途改变的，就是不能有side effect，否则会有undefined behavior
- 注意观察题目条件，例如所有都是正数,出现次数超过一半，帮助算法思考 e.g.40
- 类似于"2，3次改变"，可以先拆分成单独一次如何处理，然后多次是由哪些单次组成 e.g.1509
- 注意边界条件
    - two pointers 互相不能够越界 e.g.125
- 多使用temp variable来记住一些condition,帮助解题 e.g.008, 049
- 题目可以拆分成为subtask,一步步解决 e.g.57
- 存储状态的时候,可以考虑使用input的空间 e.g.73
    - 让1st row, 1st col 记住对应行列的状态
- 记住是否访问过
    - board 用bool[][]
    - 或者unsigned long long来保存两个int index
- edge case
    - 把数值分界区和特殊值都列举出来，一一测试

## Class
- member variable 要初始化

## LinkedList
- 相较于stack和queue，可以从头和尾读取，双向
- 如果更改结构,考虑用多个temp pointer来记住之前的 e.g.206,24
- 交换位置，更改结构之类，都要记住之前的node，避免next断链 e.g.24，82
- 把list断开，重新续接，可以考虑改造成环形列表来处理 e.g.61

## Dynamic Programming
- 如果一下子没有idea,先写出recursion的方法
- 再思考这个recursion是从哪里开始recurse back的, DP iteration就是按照这个顺序 e.g.300, 91, 518
- dp 最后完成的一个stage是整个的过程结果 e.g.62,63
- dp 不只是从左上填到右下，也可以left and right，然后取大的，这样可以考虑两个方向 e.g. 1937
- 要思考所有能够到达最后一个stage的路径都考虑到 e.g.91
- 如果问一开始的时候需要多少数值才能完成任务,思考bottom up的DP e.g.174
- 计算到终点有多少种方法,是+=累积能够抵达当前state的走法 e.g.91
- 如果要取走或者不取走,最后数值最大,思考DP e.g.53
- 规定搜索方向的path cost思考使用DP e.g.64
- 可以记住之前到达这个state的信息 e.g.84,85

## HashTable 
- 如果有明确数值目标,寻找一个数值对应的内容,用hashtable e.g.15, 3
- operator[] vs. at(): at会丢出exception 如果key does not exist 
- override hash function
```c++
auto hash = [](const pair<int, int> &p) { return p.first * 31 + p.second; };
unordered_set<pair<int, int>, decltype(hash)> u_edge_(points.size(), hash);
```

## Recursion
- 下一个状态由上一个状态延伸而来 e.g.129
- 为了记住parent，可以把 current node和next node 都放在parameter里面 e.g.019

## BFS
- 适合寻找最短路线，同时考虑dijkstra e.g.505
- 保存探索过的区域，避免重复探索e.g. 723
- internal node也是可以优化的,例如用hashtable保存所有可能的中间节点,把对应的状态挂在key的value里面 e.g.127
- 还有A*, bi-directional e.g.127

## DFS
- 只要有一个valid的出现就行 e.g.79

## Backtracking
- 适用于要尝试所有的可能，哪些能够达成目标 e.g. 698
- 是加上一个item,recursion,再去掉加上的item e.g.22, 698
- permutation是把内部所有element都互相交换了一遍位置，每交换一次，一个recursion e.g.46
- combination是将要囊括这个元素及之后的元素 e.g.77, 39
- subset是size从0到n的所有combination e.g.78

## Binary Search
- 基础的binary search是当left超过right退出,所以如果数值不存在,要插入的位置是left的结果 e.g.035
- binary search 延伸,rightMostSearch,leftMostSearch 不return mid,return left 和right e.g.34
  - 可以用lower_bound
- 并非完全sorted，但是通过排除条件，确定数值在either left or right,也可以用binary search e.g. 33,081

## Binary Search Tree
- 寻找数值的时候,可以用recursion来找,把是否存在的信息保存在return里面 e.g.236
- 改变结构的时候,recursion可以用temp variable来记住parent, e.g.114
- traverse order
    - pre-order: self, left, right. used to copy the structure
    - in-order: left, self, right. used to get nodes in numerical order
    - post-order:left, right, self. used to delete the tree
- serialize and deserialize BST e.g.449
- heap结构适用于tree左右较为平衡的结构
- 展现每层的内容：用层数来作为参数，存储在vector里面
- 计算tree里面最长的list时，是either取2个children or 取parent+ 1 child 

## State Machine
- 用array[][]来记住状态机 e.g. 17

## Greedy algorithm
- 思考结果是由哪些因子影响的 e.g. 857
- 思考如何放置第一个，第一个放完之后怎么放置第二个，以此类推 e.g. 406
- 思考schedule的时候列出各种样式来尝试 e.g.452, 56
    - 先开始的放前面（是否需要同时考虑长度）
    - 先结束的放前面
- 创建extra variable来记住当前状态 e.g.376

## string operation
- 如果用int来保存string里面的字符的时候,要注意special character也会被保存为数字,和数字信息相冲突！ e.g.224

## stack 使用场景
- 两两match e.g.20
- 保存一个个parent e.g.449
- 从recursion转化过来

## Math Problem
- 考虑overflow,是否可以用long来handle e.g. 50
- 考虑奇偶性 e.g.50
    - odd:  x * power(x * x,n/2);
    - even: power(x*x,n/2);
- num string的加法是要把string reverse，尾部对齐，并且考虑carry e.g.67
- 用binary search来查找如何满足一个数字的要求 e.g.69
- 要计算log(num,base)时，用log(num)/log(base),数学上的换底大法
- 数学运算的string可以用运算符作为分隔，左右两边继续recursion，直到只剩下数字为止 241

## Prefix Sum
- 到当前位置的累积sum，适合计算continuous array e.g. 525
- 多个数字相差特定数值的时候考虑用prefix sum
- 多个数字相差k的倍数的时候考虑用mod相同
- 当前sum和以前sum的差值mod K 为0的话，那么中间的array的sum就是K的倍数 e.g. 974, 523
- 多少个continuous subarray 的sum = k， 用hashmap + prefix sum e.g. 560

## Counting or Matching
- 用vector of counter 来+，- ，看有没有match e.g.299
- bucket sort + counting 适合有限范围之内，例如26个字母的排序 e.g.791

## Bit Manipulation
- 检查重复的时候可以考虑 XOR, a XOR b XOR a = b e.g.136
- 每一次 num XOR i, num 会记或忘i，可以用多个variable来检查num是否出现过 e.g.137
- 使用bitwise 来指数级增长数字，和target 进行比较，这样是O(n) e.g.029

## Priority Queue
- 要查询是否是序列中最早(晚)时，可以把所有state放入pq，把新加入的和pq.top()比较 e.g.253
- 要保持top k element 的时候，把要持有的放在pq的底部，这样到了size之后，就pop顶部的 e.g.692

## Priority Queue Custom Comparator
- 当持续不断地添加并且获取最大/最小的数值的时候,考虑priority_queue
- priority_queue<int, vector<int>, less<int>> maxheap,less<T>是把大的数字放在前面 e.g.295
- auto ListNodeComp=[](ListNode *lhs, ListNode *rhs){return lhs->val > rhs->val;} // 把小的放在前面
- priority_queue<ListNode* ,vector<ListNode*>, decltype(ListNodeComp)> pq(ListNodeComp); // e.g.023
    - decltyple(comp) is a function, similar to greater<int>
    - yourself defined comparator is a function object, which is still an object
    - comp class we usually used has its own 括号运算符, so we do not need to pass comparator object to pq
    - self-defined function's 括号运算符 replies on function
    - so this decltype(comp) needs its comp object

## Scheduling
- 安排时考虑：间隔gap，很多同种类型的task，很多不同类型的task
- 有没有可能用array[][]来表示 e.g.621

## Union Find
- 把不同的group合并
```c++
    unordered_map<int, int> itemParent;
    
    /*
     * when union a new item, the item will be created 
     */
    void unionItems(int item1, int item2) {
        if (findParent(item1) == findParent(item2)) {
            return;
        } else {
            itemParent[findParent(item1)] = findParent(item2);
        }
    }
    
    /*
     * Time complexity: O(reverse arkeman)
     * find with path compression
     */
    int findParent(int item) {
    	// case for adding new element
        if (itemParent.count(item) == 0) {
            itemParent[item] = item;
            return item;
        }
        
        if (itemParent[item] == item) {
            return item;
        }
        
        // let parent be the root
        itemParent[item] = findParent(itemParent[item]);
        return itemParent[item];
    }
```

## Sliding Window
- 适合求array里面连续的，最长的部分 e.g. 904
- Problems
    - 1425 Constrained Subsequence Sum
    - 1358 Number of Substrings Containing All Three Characters
    - 1248 Count Number of Nice Subarrays
    - 1234 Replace the Substring for Balanced String
    - 1004 Max Consecutive Ones III
    - 930 Binary Subarrays With Sum
    - 992 Subarrays with K Different Integers
    - 904 Fruit Into Baskets
    - 862 Shortest Subarray with Sum at Least K
    - 209 Minimum Size Subarray Sum
```c++
// return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
int longestOnes(vector<int> &nums, int k) {
    int start = 0, end = 0, buffer = k;
    for (; end < nums.size(); ++end) {
        if (nums[end] == 0) { buffer--; }
        if (buffer < 0) {
            if (nums[start] == 0) { buffer++; }
            start++;
        }
    }
    return end - start;
}
```    

## Sum Range
- 计算一个区间里面的sum e.g. 315
- 通用做法：segment tree，如果数字数值不大，可以用binary index tree
```c++
#define lowbit(x) ((x) & (-(x)))

class BinaryIndexTree {
public:
    BinaryIndexTree(int size) {
        // it can contain numbers from 0 to size
		binaryIndexTree.resize(size + 1);
	}
	
	void update(int i, int val) {
		int delta = val - sumRange(i, i);
		for (i++; i < binaryIndexTree.size(); i += lowbit(i))
			binaryIndexTree[i] += delta;
	}
	
	int sumRange(int start, int end) {
		return sum(end) - sum(start - 1);
	}

private:
	vector<int> binaryIndexTree;
	
	int sum(int i) {
		int ret = 0;
		for (i++; i; i -= lowbit(i))
			ret += binaryIndexTree[i];
		return ret;
	}
};
```

## sort
- quick sort
```c++
/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high){ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++){ 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot){ 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high){ 
    if (low < high){ 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before, partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
```

## Eulerian path
- traverse all edge, e.g. 332
```c++
/*
 * Eulerian path algorithm
 * Time complexity: ( E log E)
 */
vector<string> findItinerary(vector<vector<string>> &tickets) {
    unordered_map<string, multiset<string>> flightMap;
    vector<string> routes;
    
    for (const auto &ticket : tickets) {
        flightMap[ticket[0]].emplace(ticket[1]);
    }
    string depart = "JFK";
    visit(flightMap, routes, depart);
    
    reverse(routes.begin(), routes.end());
    return routes;
}


void visit(unordered_map<string, multiset<string>> &flightMap, vector<string> &routes, string &airport) {
    while (!flightMap[airport].empty()) {
        string nextAirport = *flightMap[airport].begin();
        flightMap[airport].erase(flightMap[airport].begin());
        visit(flightMap, routes, nextAirport);
    }
    routes.emplace_back(airport);
}

```

## Data Structure Methods
- string
    - [], pop_back
    - find_first_of(char/char*/string, size_t pos=0), find_last_of, find_first_not_of, find_last_not_of
        - return: The position of the first character that matches. If no matches are found, the function returns string::npos.
        - Searches the string for the first character that matches any of the characters specified in its arguments.
- vector
    - iterator erase(iterator position);
        - Iterator pointing to a single element to be removed from the vector.
    - iterator erase(iterator first, iterator last);
        - Iterators specifying a range within the vector] to be removed: [first,last)
    - nums.erase(remove(nums.begin(),nums.end(),val),nums.end()); // 移出所有和val相等的element，并且删除
- stack
    - top, push, emplace, pop
- data
    - front, push, emplace, pop, back,
- priority_queue
    - top, push, emplace, pop
- set
- map
    - emplace 和 [] 的区别在于如果key已经存在，emplace不会更新，而[]会
    - [] 
        - If k matches the key of an element in the container, the function returns a reference to its mapped value.
        - If k does not match the key of any element in the container, the function inserts a new element with that key and returns a reference to its mapped value. Notice that this always increases the container size by one, even if no mapped value is assigned to the element (the element is constructed using its default constructor).
        - A similar member function, map::at, has the same behavior when an element with the key exists, but throws an exception when it does not.
- unordered_map 
```
    // 假设有unordered_map<string, vector<string>> result;
    result[key].emplace_back(str); 

    // 上面和下面这段代码是等效的

    auto find = result.find(key);
    if (find == result.end()) {
        result.emplace(key, vector<string>(1, str));
    } else {
        find->second.emplace_back(str);
    }
```
- unordered_set

## STD method
- sort
    - sort's comp is different from priority_queue's comp
    - smaller content would be at the front with std::less<int>, larger will be std::greater<int>
- partial_sort (RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last, Compare comp)
    - return : void
    - Time complexity: O(N*log(M))
    - Rearranges the elements in the range [first,last), 
    - in such a way that the elements before middle are the smallest elements in the entire range,
    - and are sorted in ascending order, while the remaining elements are left without any specific order.
- nth_element
    - return : void
    - Time complexity: O(N)
    - Rearranges the elements in the range [first,last), 
    - in such a way that the element at the nth position is the element that would be in that position in a sorted sequence.
    - The other elements are left without any specific order, 
    - except that none of the elements preceding nth are greater than it, and none of the elements following it are less.
    - The elements are compared using operator< for the first version, 
    - and comp for the second.
- remove(ForwardIterator first, ForwardIterator last, const T& val)
    - return: template <class ForwardIterator, class T> ForwardIterator
    - Transforms the range [first,last) into a range with all the elements that compare equal to val removed, and returns an iterator to the new end of that range.
    - nums.erase(remove(nums.begin(),nums.end(),val),nums.end());
- reverse
    - Reverses the order of the elements in the range [first,last).
- lower_bound
    - Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.
- upper_bound
- binary_search (ForwardIterator first, ForwardIterator last, const T& val);
    - return: bool
    - Returns true if any element in the range [first,last) is equivalent to val, and false otherwise
- isalnum ( int c )
    - return: int
    - Checks whether c is either a decimal digit or an uppercase or lowercase letter.
- isdigit ( int c )
    - return int ;
    - c is a Character to be checked, casted to an int, or EOF.
- isalpha
- iswspace (char c)
- is_sorted
- max_element (iterator begin, iterator end)
    - return: iterator
- accumulate (iterator begin, iterator end, T initValue)
    - return: T
- partial_sum (InputIt first, InputIt last, OutputIt d_first)
  - Computes the partial sums of the elements in the subranges of the range [first, last) and writes them to the range beginning at d_first.

## Git
- change most recent commit date
    -  git commit --amend --date="Jan 26 17:20:19 2022  -0800"
