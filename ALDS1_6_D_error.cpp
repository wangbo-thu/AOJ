// ALDS1_6_D.cpp
// Sort II - Minimum Cost Sort

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXW = 10005;
int main()
{
	int n;
	cin >> n;
	vector<int> w(n);
	vector<int> w_sorted(MAXW, -1);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		w_sorted[w[i]]++;
	}
	
	int w_cnt = 0;
	for (int i = 0; i < w_sorted.size(); i++) {
		if (w_sorted[i] >= 0) {
			w_sorted[i] += w_cnt;
			w_cnt++;
		}
	}

	int w_min = MAXW;
	// int w_max = -1;
	int w_sum = 0;
	int w_cnt1 = 0;
	for (int i = 0; i < n; i++) {
		if (w_sorted[w[i]] != i) {
			w_sum += w[i];
			w_min = min(w_min, w[i]);
			// w_max = max(w_max, w[i]);
			int tmp = w[w_sorted[w[i]]];
			if (w[w_sorted[tmp]] != w[i])
				w_cnt1++;
		}
	}
	int res = w_sum + w_min * max(w_cnt1 - 2, 0);
	cout << res << endl;
	return 0;
}