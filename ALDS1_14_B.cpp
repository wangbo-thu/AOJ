// ALDS1_14_B.cpp
// String Search - String Search
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> strSearch(string &T, string &P)
{
	vector<int> res;
	
	return res;
}

int main()
{
	string T, P;
	cin >> T >> P;
	vector<int> res = strSearch(T, P);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}