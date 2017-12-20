// ALDS1_11_D.cpp
// Graph I - Connected Components

#include <iostream>
#include <vector>
using namespace std;

bool isFriend(vector<vector<int>> &sns, vector<int> &arrived, int x, int y)
{
    for (int i = 0; i < sns[x].size(); i++) {
        if (sns[x][i] == y) return true;
    }

    bool res = false;
    arrived[x] = 1;
    for (int i = 0; i < sns[x].size(); i++) {
        int next = sns[x][i];
        if (!arrived[next]) {
            bool tmp = isFriend(sns, arrived, next, y);
            if (tmp) {
                res = true;
                break;
            }
        }
    }
    return res;
}

int main()
{
//    freopen("ALDS1_11_D_in20.txt", "r", stdin);
//    freopen("out20.txt", "w", stdout);
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
        bool res = isFriend(sns, arrived, x, y);
        if (res) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}