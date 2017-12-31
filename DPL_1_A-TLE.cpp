// DPL_1_A.cpp
// Combinatorial - Coin Changing Problem
// TLE - 通过8个测试用例

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXM = 20;
const int INF = 50000;
int res;
vector<int> nums(MAXM);
int dfs(int sum, int pos) {
    if (sum < 0 || pos < 0) return INF;
    if (sum == 0) {
        return res;
    }
    if (sum < nums[pos]){
        return dfs(sum, pos - 1);
    }
    else {
        return min(dfs(sum - nums[pos], pos) + 1, dfs(sum, pos - 1));
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.begin() + m);
    int mini = dfs(n, m-1);
    cout << mini << endl;
    return 0;
}