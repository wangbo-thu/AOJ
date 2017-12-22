// ALDS1_12_B.cpp
// Graph II - Single Source Shortest Path I
// draw a graph using Graphviz
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

void create_graph()
{
	printf("digraph G {\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < G[i].size(); j++) {
			printf("    %d -> %d [label="%d"];\n", i, G[i][j].v, G[i][j].c);
		}
	}
	printf("}\n");
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.dot", "w", stdout);
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
	create_graph();
    return 0;
}