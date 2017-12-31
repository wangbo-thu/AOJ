// DPL_1_A.cpp
// Combinatorial - Coin Changing Problem
// AC - 参考书后写出

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 50000;
const int MAXM = 20;
const int INF = 50000;
int res;
vector<int> nums(MAXM);
vector<int> dp(MAXN);
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i <= n; i++)
        dp[i] = INF;
    dp[0] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j + nums[i] <= n; j++) {
            dp[j + nums[i]] = min(dp[j + nums[i]], dp[j] + 1);
        }
    }
    cout << dp[n] << endl;

    return 0;
}