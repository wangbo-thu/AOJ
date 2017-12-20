// ALDS1_11_A.cpp
// Graph I - Graph

#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> &A, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) cout << " ";
            cout << A[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int id;
    int num;
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> id >> num;
        if (num == 0) continue;
        else {
            int tmp;
            for (int j = 0; j < num; j++) {
                cin >> tmp;
                A[id - 1][tmp - 1] = 1;
            }
        }
    }

    print(A, n);

    return 0;
}