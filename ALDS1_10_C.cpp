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
    int s_len = s.size();
    int t_len = t.size();
    int len = min(s_len, t_len);
//    int lcs[s_len][t_len];
    vector<vector<int>> lcs(s_len, vector<int>(t_len));
    bool found = false;
    for (int i = 0; i < s_len; i++) {
        if (s[i] == t[0] || found) {
            lcs[i][0] = 1;
            found = true;
        }
    }
    found = false;
    for (int j = 0; j < t_len; j++) {
        if (s[0] == t[j] || found) {
            lcs[0][j] = 1;
            found = true;
        }
    }
    for (int i = 1; i < s_len; i++) {
        for (int j = 1; j < t_len; j++) {
            if (s[i] == t[j]) {
                lcs[i][j] = 1 + lcs[i-1][j-1];
            }
            else {
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    return lcs[s_len - 1][t_len - 1];
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

