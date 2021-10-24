//
// Created by Yuyang Huang on 10/8/20.
//

#include "LeetCodeLib.h"

/*
 * 1472. Design Browser History
 * medium
 *
 * You have a browser of one tab where you start on the homepage and you can visit another url,
 * get back in the history number of steps or move forward in the history number of steps.
 *
 * Implement the BrowserHistory class:
 * BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
 *
 * void visit(string url) Visits url from the current page.
 * It clears up all the forward history.
 *
 * string back(int steps) Move steps back in history.
 * If you can only return x steps in the history and steps > x, you will return only x steps.
 * Return the current url after moving back in history at most steps.
 *
 * string forward(int steps) Move steps forward in history.
 * If you can only forward x steps in the history and steps > x,
 * you will forward only x steps. Return the current url after forwarding in history at most steps.
 */

class BrowserHistory {
public:
	/*
	 * Time complexity: O(1) for all operations
	 */
	BrowserHistory(string homepage) : validSteps(0), currStep(0) {
		histories.push_back(homepage);
	}
	
	void visit(string url) {
		currStep++;
		// reuse decleared space
		if (histories.size() > currStep) {
			histories[currStep] = url;
		} else {
			histories.push_back(url);
		}
		validSteps = currStep;
	}
	
	string back(int steps) {
		// avoid out of bounds
		currStep = max(0, currStep - steps);
		return histories[currStep];
	}
	
	string forward(int steps) {
		currStep = min(validSteps, currStep + steps);
		return histories[currStep];
	}

private:
	vector<string> histories;
	int validSteps;
	int currStep;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main() {
	string ans;
	BrowserHistory browserHistory = BrowserHistory("leetcode.com");
	browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
	browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
	browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
	ans = browserHistory.back(1);
	// You are in "youtube.com", move back to "facebook.com" return "facebook.com"
	PrintSingleResult(ans);
	ans = browserHistory.back(1);
	// You are in "facebook.com", move back to "google.com" return "google.com"
	PrintSingleResult(ans);
	ans = browserHistory.forward(1);
	// You are in "google.com", move forward to "facebook.com" return "facebook.com"
	PrintSingleResult(ans);
	
	browserHistory.visit("linkedin.com");
	// You are in "facebook.com". Visit "linkedin.com"
	ans = browserHistory.forward(2);
	// You are in "linkedin.com", you cannot move forward any steps.
	PrintSingleResult(ans);
	ans = browserHistory.back(2);
	// You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
	PrintSingleResult(ans);
	ans = browserHistory.back(7);
	// You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
	PrintSingleResult(ans);
}