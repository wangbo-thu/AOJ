// ALDS1_11_D.cpp
// Graph I - Connected Components

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &sns, vector<int> &color, int x, int y)
{
    if (color[y] != 0) return;
    queue<int> mq;
    mq.push(x);
    while(!mq.empty()) {
        int curr = mq.front();
        mq.pop();
        color[curr] = 2;
        for (int i = 0; i < sns[curr].size(); i++) {
            int next = sns[curr][i];
            if (color[next] == 0) {
                mq.push(next);
                color[next] = 1;
            }
        }
    }
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
	vector<int> color(n);
    cin >> q;
    while (q--) {    
        cin >> x >> y;
        bfs(sns, color, x, y);
        if (color[y]) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}