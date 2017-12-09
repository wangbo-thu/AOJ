// ALDS1_4_B.cpp
// Binary Search

#include <iostream>
#include <vector>
using namespace std;

int is_in(vector<int>& S, int t)
{
    int lo = 0;
    int hi = S.size();
    int res = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (S[mid] == t) {
            res = 1;
            break;
        }
        else if (S[mid] < t) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    int q;
    cin >> q;
    vector<int> T(q);
    for (int i = 0; i < q; i++) {
        cin >> T[i];
    }
    int C = 0;
    for (int i = 0; i < q; i++) {
        C += is_in(S, T[i]);
    }
    cout << C << endl;
    return 0;
}