// ALDS1_13_A.cpp
// Heuristic Search - 8 Queens Problem
#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;
const int N = 8;
vector<int> row(N);
vector<int> col(N);
vector<int> md(2*N - 1); // main diagonal
vector<int> ad(2*N - 1); // anti-diagnoal
vector<int> res(N);
//vector<int> flag(N);
int main()
{
    int k;
    cin >> k;
    int r, c;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        row[r] = 1;
        col[c] = 1;
        md[r+c] = 1;
        ad[c-r+N-1] = 1;
        res[r] = c;
    }
    stack<pair<int, int> > ms;
    bool found = true;
    r = 0;
    c = 0;
    while (r < N) {
        if (row[r]) {
            r++;
            continue;
        }
        if (c < N) {
            if (col[c] || md[r+c] || ad[c-r+N-1]) {
                c++;
            }
            else {
                ms.push({r, c});
                res[r] = c;
                col[c] = 1;
                md[r+c] = 1;
                ad[c-r+N-1] = 1;
                r++;
                c = 0;
            }
        }
        else {
            if (ms.empty()) {
                found = false;
                break;
            }
            r = ms.top().first;
            c = ms.top().second;
            ms.pop();
            col[c] = 0;
            md[r+c] = 0;
            ad[c-r+N-1] = 0;
            c++;
        }

    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (res[i] == j) printf("Q");
            else printf(".");
        }
        printf("\n");
    }

    return 0;
}