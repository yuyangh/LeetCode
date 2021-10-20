//
// Created by Yuyang Huang on 10/23/21.
//

/*
 * 1244. Design A Leaderboard
Medium

333

63

Add to List

Share
Design a Leaderboard class, which has 3 functions:

addScore(playerId, score): Update the leaderboard by adding score to the given player's score. If there is no player with such id in the leaderboard, add him to the leaderboard with the given score.
top(K): Return the score sum of the top K players.
reset(playerId): Reset the score of the player with the given id to 0 (in other words erase it from the leaderboard). It is guaranteed that the player was added to the leaderboard before calling this function.
Initially, the leaderboard is empty.



Example 1:

Input:
["Leaderboard","addScore","addScore","addScore","addScore","addScore","top","reset","reset","addScore","top"]
[[],[1,73],[2,56],[3,39],[4,51],[5,4],[1],[1],[2],[2,51],[3]]
Output:
[null,null,null,null,null,null,73,null,null,null,141]

Explanation:
Leaderboard leaderboard = new Leaderboard ();
leaderboard.addScore(1,73);   // leaderboard = [[1,73]];
leaderboard.addScore(2,56);   // leaderboard = [[1,73],[2,56]];
leaderboard.addScore(3,39);   // leaderboard = [[1,73],[2,56],[3,39]];
leaderboard.addScore(4,51);   // leaderboard = [[1,73],[2,56],[3,39],[4,51]];
leaderboard.addScore(5,4);    // leaderboard = [[1,73],[2,56],[3,39],[4,51],[5,4]];
leaderboard.top(1);           // returns 73;
leaderboard.reset(1);         // leaderboard = [[2,56],[3,39],[4,51],[5,4]];
leaderboard.reset(2);         // leaderboard = [[3,39],[4,51],[5,4]];
leaderboard.addScore(2,51);   // leaderboard = [[2,51],[3,39],[4,51],[5,4]];
leaderboard.top(3);           // returns 141 = 51 + 51 + 39;


Constraints:

1 <= playerId, K <= 10000
It's guaranteed that K is less than or equal to the current number of players.
1 <= score <= 100
There will be at most 1000 function calls.
 */

#include "LeetCodeLib.h"

class Leaderboard {
public:
	Leaderboard() : topPlayers(comp) {
	
	}
	/*
	 * Time complexity: O(logn)
	 */
	void addScore(int playerId, int score) {
		topPlayers.erase({playerScore[playerId], playerId});
		playerScore[playerId] += score;
		topPlayers.insert({playerScore[playerId], playerId});
	}
	
	int top(int K) {
		int sum = 0;
		auto it = topPlayers.begin();
		for (int i = 0; i < min(K, (int) topPlayers.size()); i++) {
			sum += it->first;
			++it;
		}
		return sum;
	}
	
	void reset(int playerId) {
		topPlayers.erase({playerScore[playerId], playerId});
		playerScore[playerId] = 0;
	}

private:
	map<int, int> playerScore;
	// must specify what to do when first are the same, otherwise the value would be overwritten
	std::function<bool(pair<int, int>, pair<int, int>)> comp = [](const pair<int, int> lhs, const pair<int, int> rhs) {
		if (lhs.first == rhs.first) {
			return lhs.second < rhs.second;
		} else {
			return lhs.first > rhs.first;
		}
	};
	// {value,id} to distinguish same score different players
	set<pair<int, int>, decltype(comp)> topPlayers;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

int main() {
	Leaderboard leaderboard;
	int result;
	leaderboard.addScore(1, 73);   // leaderboard = [[1,73]];
	leaderboard.addScore(2, 56);   // leaderboard = [[1,73],[2,56]];
	leaderboard.addScore(3, 39);   // leaderboard = [[1,73],[2,56],[3,39]];
	leaderboard.addScore(4, 51);   // leaderboard = [[1,73],[2,56],[3,39],[4,51]];
	leaderboard.addScore(5, 4);    // leaderboard = [[1,73],[2,56],[3,39],[4,51],[5,4]];
	result = leaderboard.top(1);           // returns 73;
	PrintSingleResult(result);
	leaderboard.reset(1);         // leaderboard = [[2,56],[3,39],[4,51],[5,4]];
	leaderboard.reset(2);         // leaderboard = [[3,39],[4,51],[5,4]];
	leaderboard.addScore(2, 51);   // leaderboard = [[2,51],[3,39],[4,51],[5,4]];
	result = leaderboard.top(3);           // returns 141 = 51 + 51 + 39;
	PrintSingleResult(result);
}