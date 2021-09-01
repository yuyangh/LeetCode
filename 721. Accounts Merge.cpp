//
// Created by Yuyang Huang on 8/22/21.
//

/*
 * 721. Accounts Merge
 * Medium
 *
 * Given a list of accounts where each element accounts[i] is a list of strings,
 * where the first element accounts[i][0] is a name,
 * and the rest of the elements are emails representing emails of the account.
 *
 * Now, we would like to merge these accounts.
 * Two accounts definitely belong to the same person if there is some common email to both accounts.
 * Note that even if two accounts have the same name,
 * they may belong to different people as people could have the same name.
 * A person can have any number of accounts initially, but all of their accounts definitely have the same name.
 *
 * After merging the accounts, return the accounts in the following format:
 * the first element of each account is the name, and the rest of the elements are emails in sorted order.
 * The accounts themselves can be returned in any order.
 *
 * Example 1:
 * Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],
 * ["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],
 * ["John","johnnybravo@mail.com"]]
 * Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
 * ["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
 * Explanation:
 * The first and third John's are the same person as they have the common email "johnsmith@mail.com".
 * The second John and Mary are different people as none of their email addresses are used by other accounts.
 * We could return these lists in any order,
 * for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'],
 * ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
 *
 * Example 2:
 * Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],
 * ["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],
 * ["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
 * Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],
 * ["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],
 * ["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
 *
 * Constraints:
 * 1 <= accounts.length <= 1000
 * 2 <= accounts[i].length <= 10
 * 1 <= accounts[i][j] <= 30
 * accounts[i][0] consists of English letters.
 * accounts[i][j] (for j > 0) is a valid email.
 */
#include "LeetCodeLib.h"

class UnionFind {
public:
	unordered_map<string, string> itemParent;
	
	void unionItem(string &item1, string &item2) {
		if (findParent(item1) == findParent(item2)) {
			return;
		} else {
			itemParent[findParent(item1)] = findParent(item2);
		}
	}
	
	string findParent(string &item) {
		if (itemParent.count(item) == 0) {
			itemParent[item] = item;
			return item;
		}
		if (itemParent[item] == item) {
			return item;
		}
		
		itemParent[item] = findParent(itemParent[item]);
		return itemParent[item];
	}
};

class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * use union find to group accounts
	 */
	vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
		UnionFind unionFind;
		unordered_map<string, string> emailNameMap;
		
		for (auto &entry:accounts) {
			string userName = entry.front();
			string firstAccount = entry[1];
			unionFind.findParent(firstAccount);
			emailNameMap[firstAccount] = userName;
			
			// group emails
			for (int i = 2; i < entry.size(); ++i) {
				string currAccount = entry[i];
				emailNameMap[currAccount] = userName;
				unionFind.unionItem(firstAccount, currAccount);
			}
		}
		
		// find groups
		unordered_map<string, set<string>> emailGroups;
		for (auto &item:unionFind.itemParent) {
			emailGroups[unionFind.findParent(const_cast<string &>(item.first))].insert(item.first);
		}
		
		vector<vector<string>> result;
		for (auto &emailGroup:emailGroups) {
			result.push_back({emailNameMap[emailGroup.first]});
			for (auto &email:emailGroup.second) {
				result.back().emplace_back(email);
			}
		}
		return result;
	}
};

int main(){
	Solution solution;
	vector<vector<string>> accounts;
	
	// accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},
	// {"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},
	// {"John","johnnybravo@mail.com"}};
	// PrintVectorVector(solution.accountsMerge(accounts),20," ");
	// EmptyLine();
	
	accounts = {{"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"},
	 {"Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"},{"Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"},
	 {"Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"},{"Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"}};
	PrintVectorVector(solution.accountsMerge(accounts),20," ");
}