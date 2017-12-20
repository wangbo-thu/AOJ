// ALDS1_11_D.cpp
// Graph I - Connected Components

#include <iostream>
#include <vector>
using namespace std;

bool isFriend(vector<vector<int>> &sns, vector<int> &arrived, int x, int y)
{
    if (sns[x][y] == 1) return true;
    bool res = false;
    arrived[x] = 1;
    for (int i = 0; i < sns.size(); i++) {
        if (sns[x][i] == 1 && !arrived[i]) {
            bool tmp = isFriend(sns, arrived, i, y);
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
    int m, n, q;
    cin >> n >> m;
    vector<vector<int> > sns(n, vector<int>(n, 0));
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        sns[x][y] = 1;
        sns[y][x] = 1;
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