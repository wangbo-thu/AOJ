// ALDS_1_1_D.cpp
// Maximum Profit
#include <iostream>
#include <vector>
using namespace std;

int mymax(int a, int b)
{
	return a >= b ? a : b;
}

int main()
{
	int n;
	cin >> n;
	vector<int> Rt(n);
	for (int i = 0; i < n; i++) {
		cin >> Rt[i];
	}
	
	int posL = 0;
	int maxv = Rt[1] - Rt[0];
	for (int i = 1; i < n; i++) {
		if (Rt[i] < Rt[posL])
			posL = i;
		else
			maxv = mymax(maxv, Rt[i] - Rt[posL]);
	}
	cout << maxv << endl;
	return 0;
}