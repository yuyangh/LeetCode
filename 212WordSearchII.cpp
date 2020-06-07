//
// Created by Yuyang Huang on 6/6/20.
//

#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (30.60%)
 * Likes:    2177
 * Dislikes: 99
 * Total Accepted:    188.5K
 * Total Submissions: 567.7K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 *
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 *
 *
 *
 * Example:
 *
 *
 * Input:
 * board = [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * words = ["oath","pea","eat","rain"]
 *
 * Output: ["eat","oath"]
 *
 *
 *
 *
 * Note:
 *
 *
 * All inputs are consist of lowercase letters a-z.
 * The values of words are distinct.
 *
 *
 */

// @lc code=start

/*
 * Time complexity:
 * backtracking with trie and pruning
 */
class Solution {
public:
	vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
		Trie *trie = new Trie();
		for (const auto &word : words) {
			trie->insert(word);
		}
		
		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
		unordered_set<string> foundWords;
		unsigned int wordsSize = words.size();
		
		// do backtracking
		string buffer;
		for (int row = 0; row < board.size(); ++row) {
			for (int col = 0; col < board[0].size(); ++col) {
				findWord(trie, board, visited, buffer, row, col, trie, foundWords, wordsSize);
			}
		}
		
		vector<string> result;
		for (const auto &foundWord : foundWords) {
			result.emplace_back(foundWord);
		}
		
		return result;
	}

private:
	
	struct Trie {
		vector<Trie *> children;
		bool end = false;
		int pathCount = 0;
		
		Trie() : children(26, nullptr) {};
		
		void insert(string word) {
			auto node = this;
			for (const auto &letter : word) {
				if (node->children[letter - 'a'] == nullptr) {
					node->children[letter - 'a'] = new Trie();
				}
				node->pathCount++;
				node = node->children[letter - 'a'];
			}
			node->pathCount++;
			node->end = true;
		}
		
		void deleteWord(string word) {
			auto node = this;
			node->pathCount--;
			for (const auto &letter : word) {
				auto child = node->children[letter - 'a'];
				if (child == nullptr) {
					PrintSingleResult("null end");
					return;
				}
				child->pathCount--;
				if (child->pathCount == 0) {
					node->children[letter - 'a'] = nullptr;
				}
				node = child;
			}
			node->end = false;
		}
		
	};
	
	void
	findWord(Trie *root, vector<vector<char>> &board, vector<vector<bool>> visited, string &buffer, int row, int col,
	         Trie *trie,
	         unordered_set<string> &foundWords, unsigned int wordsSize) {
		// base case
		if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) {
			return;
		}
		if (visited[row][col]) {
			return;
		}
		
		// if already found all words
		if (wordsSize == foundWords.size()) {
			return;
		}
		
		// check child existence
		char currChar = board[row][col];
		auto currTrieNode = trie->children[currChar - 'a'];
		if (currTrieNode == nullptr) {
			return;
		}
		
		// check word existence
		buffer += currChar;
		visited[row][col] = true;
		if (currTrieNode->end) {
			foundWords.emplace(buffer);
			// pruning
			root->deleteWord(buffer);
		}
		
		// continue searching in trie
		findWord(root, board, visited, buffer, row, col + 1, currTrieNode, foundWords, wordsSize);
		findWord(root, board, visited, buffer, row, col - 1, currTrieNode, foundWords, wordsSize);
		findWord(root, board, visited, buffer, row + 1, col, currTrieNode, foundWords, wordsSize);
		findWord(root, board, visited, buffer, row - 1, col, currTrieNode, foundWords, wordsSize);
		
		visited[row][col] = false;
		buffer.pop_back();
	}
};
// @lc code=end

int main() {
	Solution solution;
	vector<vector<char>> board;
	vector<string> words;
	
	board = {
			{'o', 'a', 'a', 'n'},
			{'e', 't', 'a', 'e'},
			{'i', 'h', 'k', 'r'},
			{'i', 'f', 'l', 'v'}
	};
	words = {"oath", "pea", "eat", "rain"};
	// PrintVector(solution.findWords(board, words));
	
	words = {"oath", "o", "oa", "oathfl"};
	// PrintVector(solution.findWords(board, words));
	
	board = {{'b', 'a', 'a', 'b', 'a', 'b'},
	         {'a', 'b', 'a', 'a', 'a', 'a'},
	         {'a', 'b', 'a', 'a', 'a', 'b'},
	         {'a', 'b', 'a', 'b', 'b', 'a'},
	         {'a', 'a', 'b', 'b', 'a', 'b'},
	         {'a', 'a', 'b', 'b', 'b', 'a'},
	         {'a', 'a', 'b', 'a', 'a', 'b'}};
	words = {"aab", "aabbbbabbaababaaaabababbaaba"};
	PrintVector(solution.findWords(board, words));
	
	Complete();
}