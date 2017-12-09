// ALDS1_4D.cpp
// Search - Allocation
// 枚举法

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; // packages
    int k; // trucks
    cin >> n >> k;
    vector<int> w(n);
    int w_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        w_sum += w[i];
    }
    int w_min = w_sum / k;

    while (true) {
        int cnt = k;
        int i = 0;
        while (cnt--) {
            int curr_sum = 0;
            while (i < n && curr_sum + w[i] <= w_min) {
                curr_sum += w[i];
                i++;
            }
        }
        if (i == n) {
            break;
        }
        else w_min++;
    }
    cout << w_min << endl;

    return 0;
}