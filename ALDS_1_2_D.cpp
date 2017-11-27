// ALDS_1_2_D.cpp
// Shell Sort

#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;

void trace(vector<int> &A, int n)
{
	for (int i = 0; i < n; i++) {
		cout << A[i] << endl;
	}
}

void insertionSort(vector<int> &A, int n, int g)
{
	for (int i = g; i < n; i++) {
		int v = A[i];
		int j = i - g;

		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j -= g;
			cnt++;
		}
		A[j + g] = v;
	}
}

void shellSort(vector<int> &A, int n)
{
	cnt = 0;
	int m = 0;
	vector<int> G;
	for (int h = 1; h <= n; h = 3 * h + 1) {
		G.push_back(h);
		m++;
	}
	cout << m << endl;
	for (int i = m - 1; i >= 0; i--) {
		insertionSort(A, n, G[i]);
		if (i < m - 1) cout << " ";
		cout << G[i];
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
	shellSort(A, n);
	cout << cnt << endl;
	trace(A, n);

	return 0;
}