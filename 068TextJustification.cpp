#include "LeetCodeLib.h"

/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 *
 * https://leetcode.com/problems/text-justification/description/
 *
 * algorithms
 * Hard (23.38%)
 * Likes:    373
 * Dislikes: 1042
 * Total Accepted:    99.3K
 * Total Submissions: 420.9K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * Given an array of words and a width maxWidth, format the text such that each
 * line has exactly maxWidth characters and is fully (left and right)
 * justified.
 *
 * You should pack your words in a greedy approach; that is, pack as many words
 * as you can in each line. Pad extra spaces ' ' when necessary so that each
 * line has exactly maxWidth characters.
 *
 * Extra spaces between words should be distributed as evenly as possible. If
 * the number of spaces on a line do not divide evenly between words, the empty
 * slots on the left will be assigned more spaces than the slots on the right.
 *
 * For the last line of text, it should be left justified and no extra space is
 * inserted between words.
 *
 * Note:
 *
 *
 * A word is defined as a character sequence consisting of non-space characters
 * only.
 * Each word's length is guaranteed to be greater than 0 and not exceed
 * maxWidth.
 * The input array words contains at least one word.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * words = ["This", "is", "an", "example", "of", "text", "justification."]
 * maxWidth = 16
 * Output:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * words = ["What","must","be","acknowledgment","shall","be"]
 * maxWidth = 16
 * Output:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * Explanation: Note that the last line is "shall be    " instead of "shall
 * be",
 * because the last line must be left-justified instead of fully-justified.
 * ⁠            Note that the second line is also left-justified becase it
 * contains only one word.
 *
 *
 * Example 3:
 * Input:
 * words =
 * ["Science","is","what","we","understand","well","enough","to","explain",
 * "to","a","computer.","Art","is","everything","else","we","do"]
 * maxWidth = 20
 * Output:
 * [
 * "Science  is  what we",
 * ⁠"understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 *
 *
 */
class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int maxWidth) {
		vector<string> result;
		if (maxWidth == 0) {
			return result;
		}
		
		for (int index = 0; index < words.size();) {
			int begin = index;
			int length = 0;
			int num_on_line = 0;
			string line;
			
			// count how many words fit in
			while (index < words.size() && length + words[index].size() <= maxWidth) {
				++num_on_line;
				length += words[index].size() + 1;
				++index;
			}
			
			// add the gap to the line
			if (index < words.size()) {
				int spaces = maxWidth - length + num_on_line;
				vector<int> gaps(std::move(CalculateGapsWidth(spaces, num_on_line - 1)));
				for (int i = begin; i < index; ++i) {
					line += words[i];
					if (i - begin >= gaps.size()) {
						break;
					}
					for (int j = 0; j < gaps[i - begin]; ++j) {
						line += ' ';
					}
				}
			} else {
				for (int i = begin; i < words.size(); ++i) {
					line += words[i];
					if (i < words.size() - 1) {
						line += ' ';
					}
				}
				for (int i = line.size(); i < maxWidth; ++i) {
					line += ' ';
				}
			}
			
			// line += '\n';
			result.emplace_back(line);
		}
		return result;
	}

private:
	// calculate each gap width
	vector<int> CalculateGapsWidth(int spaces, int num_gaps) {
		if (num_gaps <= 1) {
			return {spaces};
		}
		int base_width = spaces / num_gaps;
		int left = spaces - base_width * num_gaps;
		vector<int> result(num_gaps, base_width);
		for (int i = 0; i < left; ++i) {
			if (left > 0) {
				++result[i];
			} else {
				break;
			}
		}
		return result;
	}
};

int main() {
	vector<string> arr = {"What", "must", "be", "acknowledgment", "shall", "be"};
	arr = {"This", "is", "an", "example", "of", "text", "justification."};
	arr = {"ask", "not", "what", "your", "country", "can", "do", "for", "you", "ask", "what", "you", "can", "do", "for",
	       "your", "country"};
	// arr={"Science","is","what","we","understand","well","enough","to","explain",
	//      "to","a","computer.","Art","is","everything","else","we","do"};
	int maxWidth = 16;
	Solution solution;
	auto result = solution.fullJustify(arr, maxWidth);
	for (const auto &item : result) {
		cout << "\"" << item << "\"" << endl;
	}
	return 0;
}

