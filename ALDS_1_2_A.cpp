// ALDS_1_2_A.cpp
// Bubble Sort

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

void bubbleSort(vector<int> &nums, int N, int &cnt)
{
	for (int i = N; i >= 0; i--) {
		for (int j = 0; j + 1 < i; j++) {
			if (nums[j] > nums[j+1]) {
				myswap(nums[j], nums[j+1]);
				cnt++;
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	int cnt = 0;
	bubbleSort(nums, N, cnt);
	trace(nums, N);
	cout << cnt << endl;
	return 0;
}