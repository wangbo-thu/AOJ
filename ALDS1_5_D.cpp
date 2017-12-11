// ALDS1_5_D.cpp
// Divide and Conquer - The Number of Inversions
// 套用mergesort的程序，注意cnt的范围，int和long一样长都是2^31 -1，得用long long

#include <iostream>
#include <vector>
using namespace std;
long long cnt = 0;
const int SENTINEL = 1E9 + 5;
void trace(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++) {
		if (i > 0) cout << " ";
		cout << nums[i];
	}
	cout << endl;
}

void merge(vector<int>& nums, int left, int mid, int right)
{
	vector<int> L(nums.begin() + left, nums.begin() + mid);
	vector<int> R(nums.begin() + mid, nums.begin() + right);
	L.push_back(SENTINEL);
	R.push_back(SENTINEL);
	int i = 0;
	int j = 0;
	for (int k = left; k < right; k++) {
		if (L[i] <= R[j]) {
			nums[k] = L[i++];
		}
		else {
			nums[k] = R[j++];
			cnt += L.size() - 1 - i;
		}
	}
}

void MergeSort(vector<int>& nums, int left, int right)
{
	if (left + 1 >= right) return;
	int mid = left + (right - left) / 2;
	MergeSort(nums, left, mid);
	MergeSort(nums, mid, right);
	merge(nums, left, mid, right);
}

// FILE *stream1, *stream2;

int main()
{
//	freopen_s(&stream1, "in.txt", "r", stdin);
//	freopen_s(&stream2, "out.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	MergeSort(nums, 0, n);
//	trace(nums);
	cout << cnt << endl;
	return 0;
}