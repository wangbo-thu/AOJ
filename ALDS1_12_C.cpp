// ALDS1_12_C.cpp
// Graph II - Single Source Shortest Path II
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

struct Node {
    int v;
    int c;
    Node(int v, int c): v(v), c(c) {}
};

const int maxN = 10000;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
static const int INF = (1<<21);
vector<Node> G[maxN];
vector<int> dist(maxN, INF);
vector<int> p(maxN);
vector<int> color(maxN, WHITE);
priority_queue<pair<int, int>> mq;
int n;

void dijkstra(int x)
{
    dist[x] = 0;
    p[x] = -1;
    mq.push({-dist[x], x});
    while(!mq.empty()) {
        pair<int, int> P = mq.top();
        mq.pop();
        int mindist = -P.first;
        int u = P.second;
        if (color[u] == BLACK) continue;

        for (int i = 0; i < G[u].size(); i++) {
            if (color[u] == BLACK) continue;
            int v = G[u][i].v;
            int c = G[u][i].c;
            if (dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
                p[v] = u;
                color[v] = GRAY;
                mq.push({-dist[v], v});
            }
        }
        color[u] = BLACK;
    }
}

int main()
{
//    freopen("in7.txt", "r", stdin);
//    freopen("out7.txt", "w", stdout);
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
    dijkstra(0);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", i, dist[i]);
    }
    return 0;
}