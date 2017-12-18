// ALDS1_14_A.cpp
// String Search - Naive String Search

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string P;
    string T;
    cin >> T >> P;

    for (int i = 0; i + P.size() <= T.size(); i++) {
        bool found = true;
        for (int j = 0; j < P.size(); j++) {
            if (P[j] != T[i + j]) {
                found = false;
                break;
            }
        }
        if (found) cout << i << endl;
    }
    return 0;
}