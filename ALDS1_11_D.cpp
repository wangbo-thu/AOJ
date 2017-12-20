// ALDS1_11_D.cpp
// Graph I - Connected Components

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &sns, vector<int> &arrived, int x, int y)
{
    if (arrived[y] != 0 && arrived[x] == 2) return;
    arrived[x]++;
    for (int i = 0; i < sns[x].size(); i++) {
        int next = sns[x][i];
        if (arrived[next] == 0) {
            dfs(sns, arrived, next, y);
        }
    }
    arrived[x]++;
}

int main()
{
//    freopen("ALDS1_11_D_in22.txt", "r", stdin);
//    freopen("out22.txt", "w", stdout);
    int m, n, q;
    cin >> n >> m;
    vector<vector<int> > sns(n, vector<int>());
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        sns[x].push_back(y);
        sns[y].push_back(x);
    }

    cin >> q;
    while (q--) {
        vector<int> arrived(n);
        cin >> x >> y;
        dfs(sns, arrived, x, y);
        if (arrived[y]) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}