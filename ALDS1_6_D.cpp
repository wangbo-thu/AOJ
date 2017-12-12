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
	
	int w_min = MAXW;	
	int w_cnt = 0;
	for (int i = 0; i < w_sorted.size(); i++) {
		w_min = min(w_min, w[i]);
		if (w_sorted[i] >= 0) {
			w_sorted[i] += w_cnt;
			w_cnt++;
		}
	}

	int w_sum = 0;

	for (int i = 0; i < n; i++) {
		int w_cnt1 = 0;
		int w_min_partial = MAXW;
		for (int j = i; w_sorted[w[j]] != -1; j = w_sorted[w[j]], w_sorted[w[j]] = -1) {
			w_min_partial = min(w_min_partial, w[j]);
			w_cnt1++;
			w_sum += w[j];
		}
		w_sum += min((w_cnt1 - 2) * w_min_partial, (w_cnt1 - 2) * w_min + 2 * (w_min_partial + w_min));
	}

	cout << res << endl;
	return 0;
}