//
// Created by Yuyang Huang on 10/11/21.
//

/*
 * 418. Sentence Screen Fitting
 * Medium
 *
 * Given a rows x cols screen and a sentence represented as a list of strings,
 * return the number of times the given sentence can be fitted on the screen.
 * The order of words in the sentence must remain unchanged, and a word cannot be split into two lines.
 * A single space must separate two consecutive words in a line.
 *
 * Example 1:
 * Input: sentence = ["hello","world"], rows = 2, cols = 8
 * Output: 1
 * Explanation:
 * hello--
 * world---
 * The character '-' signifies an empty space on the screen.
 *
 * Example 2:
 * Input: sentence = ["a", "bcd", "e"], rows = 3, cols = 6
 * Output: 2
 * Explanation:
 * a-bcd-
 * e-a---
 * bcd-e-
 * The character '-' signifies an empty space on the screen.
 *
 * Example 3:
 * Input: sentence = ["i","had","apple","pie"], rows = 4, cols = 5
 * Output: 1
 * Explanation:
 * i-had
 * apple
 * pie-i
 * had--
 * The character '-' signifies an empty space on the screen.
 *
 * Constraints:
 * 1 <= sentence.length <= 100
 * 1 <= sentence[i].length <= 10
 * sentence[i] consists of lowercase English letters.
 * 1 <= rows, cols <= 2 * 104
 */

#include "LeetCodeLib.h"

class Solution {
public:
	/*
	 * Time complexity: O(n)
	 * use idx to simulate whether it ends on a space or on a character
	 * if it is a character, then goes back until there is a space
	 */
	int wordsTyping(vector<string> &sentence, int rows, int cols) {
		string s;
		int idx = 0, length;
		for (auto &word: sentence) { s += word + ' '; }
		length = s.size();
		
		for (int row = 0; row < rows; row++) {
			idx += cols;
			// if this column ends at space
			if (s[idx % length] == ' ') {
				idx++;
			} else {
				// go back until there is a space
				while (idx > 0 && s[(idx - 1) % length] != ' ') {
					idx--;
				}
			}
		}
		return idx / length;
	}
};