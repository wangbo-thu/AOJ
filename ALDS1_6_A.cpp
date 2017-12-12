// ALDS1_6_A.cpp
// Sort II - Counting Sort
// 再思考，没有理得很清楚，直接照伪码写的

#include <iostream>
#include <vector>
using namespace std;
const int maxn = 10005;

void countingSort(vector<int>& A, vector<int>& B, int k)
{
	vector<int> C(k, 0);
	for (int j = 0; j < A.size(); j++) {
		C[A[j]] += 1;
	}
	for (int i = 1; i < k; i++) {
		C[i] += C[i - 1];
	}
	for (int j = A.size() - 1; j >= 0; j--) {
		B[C[A[j]] - 1] = A[j];
		C[A[j]]--;
	}
}

void trace(vector<int>& nums, int n)
{
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << nums[i];
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	vector<int> B(n);
	countingSort(A, B, maxn);
	trace(B, n);
	return 0;
}