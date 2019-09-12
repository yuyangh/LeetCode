//
// Created by Yuyang Huang on 9/12/19.
//
#include "LeetCodeLib.h"

void InsertionSort(vector<int> &arr) {
	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i] >= arr[i - 1]) {
			continue;
		}
		int index = i - 1;
		int temp = arr[i];
		while (index >= 0 && arr[index] > temp) {
			arr[index + 1] = arr[index];
			index--;
		}
		// index is 1 left, so need to add one place
		arr[index+1]=temp;
	}
}

int main() {
	vector<int> a={1,3,2,4,7,5,6};
	vector<int> b={1,2,3,4,5,5,6};
	vector<int> c={7,6,5,4,3,2};
	
	InsertionSort(a);
	InsertionSort(b);
	InsertionSort(c);
	
	PrintVector(a);
	PrintVector(b);
	PrintVector(c);
	
	return 0;
	
}


