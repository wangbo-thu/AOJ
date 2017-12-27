// ALDS1_14_B.cpp
// String Search - String Search
// TLE 通过32个测试用例
#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int R = 256;
vector<vector<int>> createDfa(string &P) {
    vector<vector<int> > dfa(R, vector<int>(P.size(), 0));
    dfa[P[0]][0] = 1;
    for (int X = 0, i = 1; i < P.size(); i++) {
        for (int j = 0; j < R; j++) {
            dfa[j][i] = dfa[j][X];
        }
        dfa[P[i]][i] = i + 1;
        X = dfa[P[i]][X];
    }
    return dfa;
}

vector<int> strSearch(string &T, string &P)
{
    vector<int> res;
    vector<vector<int>> dfa = createDfa(P);
    int tlen = T.size();
    int plen = P.size();
    int i, j;
    for (i = 0, j = 0; i < tlen; i++) {
        j = dfa[T[i]][j];
        if (j == plen) {
            res.push_back(i + 1 - plen);
            j = 0;
            i += 1 - plen;
        }
    }
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