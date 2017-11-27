// ALDS_1_2_C.cpp
// Stable Sort

#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int V = 10;

void myswap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void myswap(char& a, char& b)
{
	int t = a;
	a = b;
	b = t;
}

void isStable(string s, string t) {
	if (s == t)
		cout << "Stable" << endl;
	else
		cout << "Not stable" << endl;
}

void trace(vector<int> &nums, vector<char> &labels, int N) {
	for (int i = 0; i < N; i++) {
		if (i > 0) {
			cout << " ";
		}
		cout << labels[i] << nums[i];
	}
	cout << endl;
}

void BubbleSort(vector<int> &nums, vector<char> &labels, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j > i; j--) {
			if (nums[j] < nums[j - 1]) {
				myswap(nums[j], nums[j - 1]);
				myswap(labels[j], labels[j - 1]);
			}
		}
	}
}

void SelectionSort(vector<int> &nums, vector<char> &labels, int N) {
	for (int i = 0; i < N; i++) {
		int minPos = i;
		for (int j = i; j < N; j++) {
			if (nums[j] < nums[minPos]) minPos = j;
		}
		myswap(nums[i], nums[minPos]);
		myswap(labels[i], labels[minPos]);
	}
}


int main()
{
	int N;
	cin >> N;
	vector<int> nums(N);
	vector<char> labels(N);
	vector<string> strs(V);
	for (int i = 0; i < N; i++) {
		cin >> labels[i] >> nums[i];
		strs[nums[i]].push_back(labels[i]);
	}
	// s为稳定排序的结果
	string s;
	for (int i = 1; i < V; i++) {
		s.append(strs[i]);
	}
	vector<int> nums1(nums);
	vector<char> labels1(labels);
	vector<int> nums2(nums);
	vector<char> labels2(labels);

	BubbleSort(nums1, labels1, N);
	trace(nums1, labels1, N);
	string t1;
	for (int i = 0; i < labels1.size(); i++) {
		t1.push_back(labels1[i]);
	}
	isStable(s, t1);

	SelectionSort(nums2, labels2, N);
	trace(nums2, labels2, N);
	string t2;
	for (int i = 0; i < labels2.size(); i++) {
		t2.push_back(labels2[i]);
	}
	isStable(s, t2);

	return 0;
}
