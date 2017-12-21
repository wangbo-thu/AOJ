// ALDS1_12_B.cpp
// Graph II - Single Source Shortest Path I
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Node {
    int v;
    int c;
    Node(int v, int c): v(v), c(c) {}
};

static const int maxN = 100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
//static const int INF = 100001;
vector<Node> G[maxN];
vector<int> dist(maxN, 0);
vector<int> color(maxN, WHITE);
int n;

void solve(int x)
{
    if (color[x] == BLACK) return;
    color[x] = GRAY;
    for (int i = 0; i < G[x].size(); i++) {
        int v = G[x][i].v;
        int c = G[x][i].c;
        if (dist[v] == 0 && color[v] == WHITE)
            dist[v] = dist[x] + c;
        else
            dist[v] = min(dist[v], dist[x] + c);
        if (color[v] == WHITE) {
            solve(v);
        }
    }
    color[x] = BLACK;
}

int main()
{
    cin >> n;
    int u, k;
    int v, c;
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            cin >> v >> c;
            G[i].push_back(Node(v, c));
        }
    }
    solve(0);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", i, dist[i]);
    }
    return 0;
}