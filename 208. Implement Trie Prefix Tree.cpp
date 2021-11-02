#include "LeetCodeLib.h"

/*
 * 208. Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium
 *
 * Implement a trie with insert, search, and startsWith methods.
 *
 * Example:
 * Trie trie = new Trie();
 *
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");
 * trie.search("app");     // returns true
 *
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 *
 */
/**
 * each node has n pointers to the next level
 * each node has a mark that whether current node is an end of word
 */
class Trie {
public:
	/** Initialize your data structure here.
	 * initialize each pointer to nullptr
	 */
	Trie() :  _word_end(false) {
		for (auto & leaf : leaves) {
			leaf= nullptr;
		}
	}
	
	/** Inserts a word into the trie.
	 * either create a connection or reuse current one
	 * mark the node as an end for a word
	 */
	void insert(string word) {
		auto trie_ptr = this;
		for (const auto &ch : word) {
			int index = ch - 'a';
			Trie *trie;
			// build a connection or reuse
			if (trie_ptr->leaves[index] != nullptr) {
				trie = trie_ptr->leaves[index];
			} else {
				trie = new Trie();
			}
			trie_ptr->leaves[index] = trie;
			trie_ptr = trie;
		}
		trie_ptr->_word_end = true;
	}
	
	/** Returns if the word is in the trie.
	 * check whether word exist in the trie
	 * and whether that node is an end of a word
	 * */
	bool search(string word) {
		auto trie_ptr = this;
		for (const auto &item : word) {
			int index = item - 'a';
			auto trie = trie_ptr->leaves[index];
			if (trie != nullptr) {
				trie_ptr = trie;
			} else {
				return false;
			}
		}
		// check if the we reach the leaf of the trie
		return (trie_ptr->_word_end);
	}
	
	/** Returns if there is any word in the trie that starts with the given prefix.
	 * similar to seach method
	 */
	bool startsWith(string prefix) {
		auto trie_ptr = this;
		for (const auto &item : prefix) {
			int index = item - 'a';
			auto trie = trie_ptr->leaves[index];
			if (trie != nullptr) {
				trie_ptr = trie;
			} else {
				return false;
			}
		}
		return true;
	}

private:
	Trie * leaves[26]{};
	bool _word_end;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
	Trie trie = Trie();
	bool result;
	
	trie.insert("apple");
	result = trie.search("apple");   // returns true
	PrintSingleResult(result);
	result = trie.search("app");     // returns false
	PrintSingleResult(result);
	result = trie.startsWith("app"); // returns true
	PrintSingleResult(result);
	trie.insert("app");
	result = trie.search("app");     // returns true
	PrintSingleResult(result);
	
	return 0;
}

