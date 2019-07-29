#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 *
 * https://leetcode.com/problems/unique-email-addresses/description/
 *
 * algorithms
 * Easy (70.10%)
 * Likes:    515
 * Dislikes: 143
 * Total Accepted:    132.7K
 * Total Submissions: 190.1K
 * Testcase Example:  '["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]'
 *
 * Every email consists of a local name and a domain name, separated by the @
 * sign.
 *
 * For example, in alice@leetcode.com, alice is the local name, and
 * leetcode.com is the domain name.
 *
 * Besides lowercase letters, these emails may contain '.'s or '+'s.
 *
 * If you add periods ('.') between some characters in the local name part of
 * an email address, mail sent there will be forwarded to the same address
 * without dots in the local name.  For example, "alice.z@leetcode.com" and
 * "alicez@leetcode.com" forward to the same email address.  (Note that this
 * rule does not apply for domain names.)
 *
 * If you add a plus ('+') in the local name, everything after the first plus
 * sign will be ignored. This allows certain emails to be filtered, for example
 * m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule
 * does not apply for domain names.)
 *
 * It is possible to use both of these rules at the same time.
 *
 * Given a list of emails, we send one email to each address in the list.  How
 * many different addresses actually receive mails? 
 *
 * Example 1:
 * Input:
 * ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
 * Output: 2
 * Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually
 * receive mails
 *
 * Note:
 * 1 <= emails[i].length <= 100
 * 1 <= emails.length <= 100
 * Each emails[i] contains exactly one '@' character.
 * All local and domain names are non-empty.
 * Local names do not start with a '+' character.
 *
 */
class Solution {
public:
	int numUniqueEmails(vector<string> &emails) {
		unordered_set<string> email_set;
		
		// go through each email address
		for (const auto &email : emails) {
			string temp;
			bool ignore_flag = false;
			for (int i = 0; i < email.size(); ++i) {
				if (email[i] == '+') {
					ignore_flag = true;
				}
				if (email[i] == '.') {
					continue;
				}
				if (email[i] == '@') {
					temp += email.substr(i);
					break;
				}
				if (!ignore_flag) {
					temp += email[i];
				}
			}
			
			// add to the set
			auto it = email_set.find(temp);
			if (it == email_set.end()) {
				email_set.emplace(temp);
			}
		}
		return email_set.size();
	}
};

int main() {
	vector<string> input = {"test.email+alex@leetcode.com",
	                        "test.e.mail+bob.cathy@leetcode.com",
	                        "testemail+david@lee.tcode.com"};
	Solution solution;
	auto result=solution.numUniqueEmails(input);
	PrintSingleResult(result);
	return 0;
}

