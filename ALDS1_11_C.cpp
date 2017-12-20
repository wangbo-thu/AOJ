// ALDS1_11_C.cpp
// Graph I - BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Vertex
{
    int id = 0;
    vector<int> adjList;
};
int tt = 0;
void bfs(vector<Vertex> &V, vector<int> &dist, int i)
{
    queue<Vertex> mq;
    mq.push(V[i]);
    dist[i] = 0;
    while(!mq.empty()) {
        Vertex tmpV = mq.front();
        mq.pop();
        for (int j = 0; j < tmpV.adjList.size(); j++) {
            int next = tmpV.adjList[j];
            if (dist[next] == -1) {
                mq.push(V[next]);
                dist[next] = dist[tmpV.id] + 1;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<Vertex> V(n);
    vector<int> dist(n, -1);
    int id;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> id >> num;
        id--;
        V[id].id = id;
        int tmp;
        for (int j = 0; j < num; j++) {
            cin >> tmp;
            tmp--;
            V[id].adjList.push_back(tmp);
        }
    }
    bfs(V, dist, 0);
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << dist[i] << endl;
    }
    return 0;
}