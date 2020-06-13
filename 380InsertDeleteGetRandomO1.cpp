//
// Created by Yuyang Huang on 6/12/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 *
 * https://leetcode.com/problems/insert-delete-getrandom-o1/description/
 *
 * algorithms
 * Medium (44.18%)
 * Likes:    2330
 * Dislikes: 153
 * Total Accepted:    224.7K
 * Total Submissions: 478.6K
 * Testcase Example:  '["RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"]\n' +
  '[[],[1],[2],[2],[],[1],[2],[]]'
 *
 * Design a data structure that supports all following operations in average
 * O(1) time.
 *
 *
 *
 * insert(val): Inserts an item val to the set if not already present.
 * remove(val): Removes an item val from the set if present.
 * getRandom: Returns a random element from current set of elements. Each
 * element must have the same probability of being returned.
 *
 *
 *
 * Example:
 *
 * // Init an empty set.
 * RandomizedSet randomSet = new RandomizedSet();
 *
 * // Inserts 1 to the set. Returns true as 1 was inserted successfully.
 * randomSet.insert(1);
 *
 * // Returns false as 2 does not exist in the set.
 * randomSet.remove(2);
 *
 * // Inserts 2 to the set, returns true. Set now contains [1,2].
 * randomSet.insert(2);
 *
 * // getRandom should return either 1 or 2 randomly.
 * randomSet.getRandom();
 *
 * // Removes 1 from the set, returns true. Set now contains [2].
 * randomSet.remove(1);
 *
 * // 2 was already in the set, so return false.
 * randomSet.insert(2);
 *
 * // Since 2 is the only number in the set, getRandom always return 2.
 * randomSet.getRandom();
 *
 *
 */

// @lc code=start

/*
 * use hashmap and vector
 * hashmap stores {val, val's pos in vector}
 * vector stores val
 */
class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {
	
	}
	
	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		int count = numsPosMap.count(val);
		if (count == 0) {
			nums.emplace_back(val);
			numsPosMap.emplace(val, nums.size() - 1);
			return true;
		} else {
			return false;
		}
	}
	
	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		auto targetIt = numsPosMap.find(val);
		if (targetIt == numsPosMap.end()) {
			return false;
		} else {
			auto lastIt = numsPosMap.find(nums.back());
			// set last item's nums' location be the val's position
			lastIt->second = targetIt->second;
			swap(nums[targetIt->second], nums.back());
			
			// delete val
			numsPosMap.erase(targetIt);
			nums.pop_back();
			
			return true;
		}
	}
	
	/** Get a random element from the set. */
	int getRandom() {
		return nums[rand() % nums.size()];
	}

private:
	unordered_map<int, int> numsPosMap;
	vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

