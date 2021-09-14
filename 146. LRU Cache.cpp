#include "LeetCodeLib.h"

/*
 *
 * 146. LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 *
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 *
 * The cache is initialized with a positive capacity.
 *
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 *
 * Example:
 * LRUCache cache = new LRUCache( 2 // capacity // );
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 */
class LRUCache {
public:
	/*
	 * use a hashtable and double-linked list to implement
	 * iterator of the list will not change
	 * unordered_map<int, pair<int, std::list<int>::iterator>> _record : key to value
	 * list<int> _order: a list of keys
	 */
	LRUCache(int capacity) : _capacity(capacity) {
		// reserve enough space to decrease number of rehash
		_record.reserve(2 * capacity);
	}
	
	int get(int key) {
		auto it = _record.find(key);
		if (it == _record.end()) {
			return -1;
		} else {
			// if we find the key, update the key's place
			_order.erase(it->second.second);
			_order.emplace_front(key);
			it->second.second=_order.begin();
			
			return it->second.first;
		}
	}
	
	void put(int key, int value) {
		auto it = _record.find(key);
		if (it != _record.end()) {
			// if we find the key,
			// update the key's place and value
			it->second.first=value;
			_order.erase(it->second.second);
			_order.emplace_front(key);
			it->second.second=_order.begin();
		} else {
			// remove the oldest element
			if (_record.size() >= _capacity) {
				int earliest_key = _order.back();
				_record.erase(earliest_key);
				_order.pop_back();
			}
			// add the element
			_order.emplace_front(key);
			_record.emplace(key, make_pair(value, _order.begin()));
		}
	}

private:
	unordered_map<int, pair<int, std::list<int>::iterator>> _record;
	list<int> _order;
	int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
int main(){
	int result;
	LRUCache cache =  LRUCache( 2 /* capacity */ );
	
	// cache.put(1, 1);
	// cache.put(2, 2);
	// result=cache.get(1);        // returns 1
	// PrintSingleResult(result);
	// cache.put(3, 3);            // evicts key 2
	// result=cache.get(2);        // returns -1 (not found)
	// PrintSingleResult(result);
	// cache.put(4, 4);            // evicts key 1
	// result=cache.get(1);        // returns -1 (not found)
	// PrintSingleResult(result);
	// result=cache.get(3);        // returns 3
	// PrintSingleResult(result);
	// result=cache.get(4);        // returns 4
	// PrintSingleResult(result);
	
	cache =  LRUCache( 1 /* capacity */ );
	cache.put(2, 1);
	result=cache.get(2);        // returns 1
	PrintSingleResult(result);
	cache.put(3, 2);            // evicts key 2
	result=cache.get(2);        // returns -1 (not found)
	PrintSingleResult(result);           // evicts key 1
	result=cache.get(3);        // returns -1 (not found)
	PrintSingleResult(result);
	
	return 0;
}

