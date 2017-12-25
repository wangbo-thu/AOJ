// ALDS1_13_B.cpp
// Heuristic Search - 8 Puzzle
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
const int N = 3;
const int INF = 50;
vector<vector<int> > cell(N, vector<int>(N));
vector<vector<int> > ans = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
int q = 0;
unordered_set<int> ms;
int zero_x = 0;
int zero_y = 0;
int ministep = INF;

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}
int key(vector<vector<int> > cell)
{
	int res = 0;
	int p = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			res += cell[i][j] * p;
			p *= 10;
		}
	}
	return res;
}

void solve(int i)
{
	int p = key(cell);
	if (ms.find(p) != ms.end() || ministep < i) {
		return;
	}
	if (p == q) {
		ministep = min(ministep, i);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << " " << cell[i][j];
            }
            cout << endl;
        }
        cout << endl;
		return;
	}
	
	ms.insert(p);
	if (zero_x > 0) {
		swap(cell[zero_x][zero_y], cell[zero_x - 1][zero_y]);
        zero_x--;
		solve(i + 1);
		swap(cell[zero_x][zero_y], cell[zero_x + 1][zero_y]);
        zero_x++;
	}
	if (zero_x < N - 1) {
		swap(cell[zero_x][zero_y], cell[zero_x + 1][zero_y]);
        zero_x++;
		solve(i + 1);
		swap(cell[zero_x][zero_y], cell[zero_x - 1][zero_y]);
        zero_x--;
	}
	if (zero_y > 0) {
		swap(cell[zero_x][zero_y], cell[zero_x][zero_y - 1]);
        zero_y--;
		solve(i + 1);
		swap(cell[zero_x][zero_y], cell[zero_x][zero_y + 1]);
        zero_y++;
	}
	if (zero_y < N - 1) {
		swap(cell[zero_x][zero_y], cell[zero_x][zero_y + 1]);
        zero_y++;
		solve(i + 1);
		swap(cell[zero_x][zero_y], cell[zero_x][zero_y - 1]);
        zero_y--;
	}
	ms.erase(p);
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cell[i][j];
            if (cell[i][j] == 0) {
                zero_x = i;
                zero_y = j;
            }
		}
	}

	q = key(ans);
	solve(0);
	cout << ministep << endl;
	return 0;
}