// ALDS1_5_A.cpp
// Divide and Conquer - Exhaustive Search

#include <iostream>
#include <vector>
using namespace std;

bool solve(vector<int>& A, int cnt, int m)
{
	if (m == 0) return true;
	if (cnt == A.size()) return false;
	return solve(A, cnt + 1, m) || solve(A, cnt + 1, m - A[cnt]);
}

int main()
{
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int q;
	cin >> q;
	vector<int> M(q);
	for (int i = 0; i < q; i++) {
		cin >> M[i];
		if (solve(A, 0, M[i])) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}