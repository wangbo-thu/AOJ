// ALDS_1_2_B.cpp
// Selection Sort
#include <iostream>
#include <vector>
using namespace std;

void trace(vector<int> &nums, int N)
{
	for (int i = 0; i < N; i++) {
		if (i >= 1) cout << " ";
		cout << nums[i];
	}
	cout << endl;
}

void myswap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void selectionSort(vector<int> &nums, int N, int& cnt)
{
	for (int i = 0; i < N; i++) {
		int minPos = i;
		for (int j = i+1; j < N; j++) {
			if (nums[j] < nums[minPos]) minPos = j;
		}
		if (i != minPos) {
			myswap(nums[i], nums[minPos]);
			cnt++;
		}
	}
	
}

int main()
{
	int N;
	cin >> N;
	vector<int> nums(N);
	for (int i =0; i < N; i++) {
		cin >> nums[i];
	}
	int cnt = 0;
	selectionSort(nums, N, cnt);
	trace(nums, N);
	cout << cnt << endl;
	return 0;
}