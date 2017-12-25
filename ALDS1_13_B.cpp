// ALDS1_13_B.cpp
// Heuristic Search - 8 Puzzle
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int N = 3;
const int N2 = 9;
const int INF = 50;
struct Puzzle {
    int f[N2];
    //int space;
    string path;

    bool operator < (const Puzzle &p) const {
        for (int i = 0; i < N2; i++) {
            if (f[i] == p.f[i]) continue;
            return f[i] > p.f[i];
        }
        return false;
    }
};
static const int dx[4] = {-1, 0, 1, 0};
static const int dy[4] = {0, -1, 0, 1};
static const char dir[4] = {'u', 'l', 'd', 'r'};
map<Puzzle, bool> ms;
Puzzle in;
int ministep = INF;
int sx = 0;
int sy = 0;

bool isTarget(Puzzle p)
{
    for (int i = 0; i < N2; i++) {
        if (p.f[i] != i + 1)
            return false;
    }
    return true;
}

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

void bfs(int i)
{
    if (isTarget(in)) {
        ministep = min(ministep, i);
        return;
    }
    if (ms[in] || ministep < i) {
        return;
    }

    if (in.path == "ldrd")
        int debug = 0;
    ms[in] = true;
    for (int u = 0; u < 4; u++) {
        int tx = sx + dx[u];
        int ty = sy + dy[u];
        if (tx < 0 || tx >= N || ty < 0 || ty >= N)
            continue;
        swap(in.f[sx * N + sy], in.f[tx * N + ty]);
        sx = tx;
        sy = ty;
        in.path += dir[u];
        bfs(i+1);
        sx = sx - dx[u];
        sy = sy - dy[u];
        swap(in.f[sx * N + sy], in.f[tx * N + ty]);
        in.path.pop_back();
    }
    ms[in] = false;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    for (int i = 0; i < N2; i++) {
        cin >> in.f[i];
        if (in.f[i] == 0) {
            sx = i / N;
            sy = i % N;
            in.f[i] = 9; // 便于isTarget的比较
        }
    }
    bfs(0);
    cout << ministep << endl;
    return 0;
}