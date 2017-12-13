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
    int w_min = MAXW;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        w_sorted[w[i]]++;
        w_min = min(w_min, w[i]);
    }

    int w_cnt = 0;
    for (int i = 0; i < w_sorted.size(); i++) {
        if (w_sorted[i] >= 0) {
            w_sorted[i] += w_cnt;
            w_cnt++;
        }
    }

    int w_sum = 0;

    for (int i = 0; i < n; i++) {
        if (w_sorted[w[i]] == -1) continue;
        int w_cnt1 = 0;
        int w_min_partial = w[i];
        for (int j = i; w_sorted[w[j]] != -1; ) {
            w_min_partial = min(w_min_partial, w[j]);
            w_cnt1++;
            w_sum += w[j];
            int tmp = j;
            j = w_sorted[w[j]];
            w_sorted[w[tmp]] = -1;
        }
        w_sum += min((w_cnt1 - 2) * w_min_partial, (w_cnt1 + 1) * w_min + w_min_partial);
    }

    cout << w_sum << endl;
    return 0;
}