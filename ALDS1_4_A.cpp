// ALDS1_4_A.cpp
// Linear Search
// 交集的大小

#include <iostream>
#include <set>
using namespace std;

int intersectionCnt(set<int>& S, set<int>& T)
{
    int C = 0;
    set<int>::iterator it1 = S.begin();
    set<int>::iterator it2 = T.begin();
    while (it1 != S.end() && it2 != T.end()) {
        if (*it2 == *it1) {
            C++;
            ++it1;
            ++it2;
        }
        else if (*it2 < *it1) {
            ++it2;
        }
        else {
            ++it1;
        }
    }
    return C;
}

int main()
{
    int n;
    cin >> n;
    set<int> S;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        S.insert(tmp);
    }

    int q;
    cin >> q;
    set<int> T;
    for (int i = 0; i < q; i++) {
        cin >> tmp;
        T.insert(tmp);
    }

    int C = intersectionCnt(S, T);
    cout << C << endl;
    return 0;
}