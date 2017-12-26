// ALDS1_13_B.cpp
// Heuristic Search - 8 Puzzle

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
const int N = 3;
const int N2 = 9;
vector<int> in(N2);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
const char dir[4] = {'u', 'l', 'd', 'r'};
struct Puzzle
{
    int f[N2];
    int space;
    string path;

    bool operator < (const Puzzle &p) const {
        for (int i = 0; i < N2; i++) {
            if (f[i] == p.f[i]) continue;
            return f[i] > p.f[i];
        }
        return false;
    }
};

bool isTarget(Puzzle p)
{
    for (int i = 0; i < N2; i++) {
        if (p.f[i] != i + 1)
            return false;
    }
    return true;
}

string bfs(Puzzle p)
{
    map<Puzzle, bool> mp;
    queue<Puzzle> mq;
    Puzzle u, v;
    mp[p] = true;
    mq.push(p);
    while(!mq.empty()) {
        u = mq.front();
        mq.pop();
        if (isTarget(u)) return u.path;
        int sx = u.space / N;
        int sy = u.space % N;

        for (int r = 0; r < 4; r++) {
            int tx = sx + dx[r];
            int ty = sy + dy[r];
            if (tx < 0 || ty < 0 || tx >= N || ty >= N)
                continue;
            v = u;
            swap(v.f[tx * N + ty], v.f[sx * N + sy]);
            v.space = tx * N + ty;

            if (!mp[v]) {
                mp[v] = true;
                v.path += dir[r];
                mq.push(v);
            }
        }
    }
    return "unsolveable";
}

int main()
{
    Puzzle in;
    for (int i = 0; i < N2; i++) {
        cin >> in.f[i];
        if (in.f[i] == 0) {
            in.space = i;
            in.f[i] = N2;
        }
    }
    string ans = bfs(in);
    cout << ans.size() << endl;
    return 0;
}