// ALDS_1_3_A.cpp
// Stack
// 使用sstream进行string转int

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string str;
    stack<int> nums;
    while (cin >> str) {
        if (str[0] == '+') {
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();
            nums.push(a + b);
        }
        else if (str[0] == '-') {
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();
            nums.push(b - a);
        }
        else if (str[0] == '*') {
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();
            nums.push(a * b);
        }
        else {
            int num;
            stringstream ss(str);
            ss >> num;
            nums.push(num);
        }
    }
    int res = nums.top();
    cout << res << endl;
    return 0;
}