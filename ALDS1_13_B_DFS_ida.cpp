// ALDS1_13_B.cpp
// Heuristic Search - 8 Puzzle
// AC
// 加了曼哈顿距离进行剪枝，顺利AC，但效率不高
// 增加迭代加深
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int N = 3;
const int N2 = 9;
const int INF = 40;
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
int limit;

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

bool isTarget(Puzzle p)
{
    for (int i = 0; i < N2; i++) {
        if (p.f[i] != i + 1)
            return false;
    }
    return true;
}

int getAllMD(Puzzle p)
{
    int dist = 0;
    int x, y;
    int ux, uy;
    for (int i = 0; i < N2; i++) {
        if (p.f[i] == N2) continue; // 不计0的点
        x = (p.f[i] - 1) / N;
        y = (p.f[i] - 1) % N;
        ux = i / N;
        uy = i % N;
        dist += abs(x - ux) + abs(y - uy);
    }
    return dist;
}

bool bfs(int i)
{
    if (isTarget(in)) {
        ministep = min(ministep, i);
//        cout << "ministep = " << ministep << endl;
        return true;
    }
    if (ms[in] || limit < i + getAllMD(in)) {
        return false;
    }

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
        /* test */
//    cout << "(i = " << i << ") " << in.path << endl;
//    for (int j = 0; j < N2; j++)
//        cout << " " << in.f[j];
//    cout << endl;
//    cout << "MD: " << getAllMD(in) << endl;
        if(bfs(i+1)) return true;
        sx = sx - dx[u];
        sy = sy - dy[u];
        swap(in.f[sx * N + sy], in.f[tx * N + ty]);
        in.path.pop_back();
    }
    ms[in] = false;
    return false;
}

string iterative_deepening()
{
    limit = getAllMD(in);
    for ( ; limit <= INF; limit++) {
        if (bfs(0)) {
            return in.path;
        }
    }
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    for (int i = 0; i < N2; i++) {
        cin >> in.f[i];
        if (in.f[i] == 0) {
            sx = i / N;
            sy = i % N;
            in.f[i] = 9; // 便于isTarget的比较
        }
    }
    string ans = iterative_deepening();
    cout << ans.size() << endl;
    return 0;
}