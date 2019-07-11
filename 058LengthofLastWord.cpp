#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.27%)
 * Likes:    392
 * Dislikes: 1646
 * Total Accepted:    278.2K
 * Total Submissions: 862.3K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 *
 * Example:
 *
 *
 * Input: "Hello World"
 * Output: 5
 */
class Solution {
public:
	// count length from the end of the string
	// going backward, until we find the first space character
	int lengthOfLastWord(string s) {
		int max_length = 0;
		int index = static_cast<int>(s.size()) - 1;
		while (index >= 0 && s[index] == ' ') {
			--index;
		}
		while (index >= 0 && s[index] != ' ') {
			--index;
			++max_length;
		}
		return max_length;
	}
	
	// count length from the begin of the string
	// because we only care about the last word length
	// so this method wastes time on going forward
	int lengthOfLastWordHead(string s) {
		int max_length = 0;
		for (int i = 0; i < s.size();) {
			while (i < s.size() && s[i] == ' ') {
				++i;
			}
			if (i >= s.size()) {
				break;
			}
			max_length = 0;
			while (i < s.size() && s[i] != ' ') {
				++max_length;
				++i;
			}
			
		}
		return max_length;
	}
};


string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
				case '\"':
					result.push_back('\"');
					break;
				case '/' :
					result.push_back('/');
					break;
				case '\\':
					result.push_back('\\');
					break;
				case 'b' :
					result.push_back('\b');
					break;
				case 'f' :
					result.push_back('\f');
					break;
				case 'r' :
					result.push_back('\r');
					break;
				case 'n' :
					result.push_back('\n');
					break;
				case 't' :
					result.push_back('\t');
					break;
				default:
					break;
			}
			i++;
		} else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);
		
		int ret = Solution().lengthOfLastWord(s);
		
		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}
