// ALDS1_10_C.cpp
// Dynamic Programming - Longest Common Subsequence

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int LCS(string s, string t)
{
	int res = 0;
	if (s.empty() || t.empty())
		return res;
	string s1(s.begin() + 1, s.end());
	string t1(t.begin() + 1, t.end());
	if (s[0] == t[0]) {
		res = 1 + LCS(s1, t1);
	}
	else {
		res = max(LCS(s1, t), LCS(s, t1));
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	string s, t;
	while (n--) {
		cin >> s >> t;
		int res = LCS(s, t);
		cout << res << endl;
	}
	return 0;
}

