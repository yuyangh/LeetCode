//
// Created by Yuyang Huang on 10/23/21.
//

/*
 * 1169. Invalid Transactions
 * Medium
 *
 * A transaction is possibly invalid if:
 * the amount exceeds $1000, or;
 * if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
 * You are given an array of strings transaction where transactions[i]
 * consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.
 * Return a list of transactions that are possibly invalid. You may return the answer in any order.
 *
 * Example 1:
 * Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
 * Output: ["alice,20,800,mtv","alice,50,100,beijing"]
 * Explanation: The first transaction is invalid
 * because the second transaction occurs within a difference of 60 minutes,
 * have the same name and is in a different city. Similarly the second one is invalid too.
 *
 * Example 2:
 * Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
 * Output: ["alice,50,1200,mtv"]
 *
 * Example 3:
 * Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
 * Output: ["bob,50,1200,mtv"
 *
 * Constraints:
 * transactions.length <= 1000
 * Each transactions[i] takes the form "{name},{time},{amount},{city}"
 * Each {name} and {city} consist of lowercase English letters, and have lengths between 1 and 10.
 * Each {time} consist of digits, and represent an integer between 0 and 1000.
 * Each {amount} consist of digits, and represent an integer between 0 and 2000.
 * */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(n*n)
	 */
	vector<string> invalidTransactions(vector<string> &transactions) {
		unordered_map<string, vector<Transaction>> data;
		vector<string> result;
		
		// parse each transaction
		for (auto &transaction: transactions) {
			stringstream ss(transaction);
			string buffer;
			vector<string> arr;
			while (getline(ss, buffer, ',')) {
				arr.push_back(buffer);
			}
			
			Transaction t(arr[0], stoi(arr[1]), stoi(arr[2]), arr[3], transaction);
			data[t.name].emplace_back(t);
		}
		
		for (auto &person: data) {
			unordered_set<int> invalidTransactionIdx;
			auto &personTransactions = person.second;
			// sort by time
			sort(personTransactions.begin(), personTransactions.end());
			
			for (int idx = 0; idx < personTransactions.size(); idx++) {
				auto &transaction = personTransactions[idx];
				if (transaction.amount > 1000) {
					invalidTransactionIdx.emplace(idx);
				}
				
				// go through previous Transactions to find invalid pairs
				for(int prevIdx=0;prevIdx<idx;prevIdx++){
					auto &prevTransaction = personTransactions[prevIdx];
					if (transaction.time - prevTransaction.time <= 60 &&
					    transaction.loc != prevTransaction.loc) {
						invalidTransactionIdx.emplace(prevIdx);
						invalidTransactionIdx.emplace(idx);
					}
				}
			}
			
			for (auto &idx: invalidTransactionIdx) {
				result.emplace_back(personTransactions[idx].content);
			}
		}
		
		return result;
	}

private:
	struct Transaction {
		string name;
		int time;
		int amount;
		string loc;
		string content;
		
		Transaction(string &name, int time, int amount, string &loc, string &verbo) : name(name), time(time),
		                                                                              amount(amount),
		                                                                              loc(loc), content(verbo) {};
		
		Transaction() = default;
		
		friend bool operator<(const Transaction &lhs, const Transaction &rhs) {
			return lhs.time < rhs.time;
		};
	};
};

int main() {
	Solution solution;
	vector<string> transactions;
	transactions = {"alice,20,800,mtv", "alice,50,100,beijing"};
	PrintVector(solution.invalidTransactions(transactions));
	
	transactions = {"alice,20,800,mtv", "alice,50,1200,mtv"};
	PrintVector(solution.invalidTransactions(transactions));
	
	transactions = {"alice,20,800,mtv", "bob,50,1200,mtv"};
	PrintVector(solution.invalidTransactions(transactions));
}