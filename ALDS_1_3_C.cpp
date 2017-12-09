// ALSD_1_3_C.cpp
// Doubly Linked List
// deque的实现
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n;
    string cmd;
    int num;
    deque<int> nums;
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "insert") {
            cin >> num;
            nums.push_front(num);
        }
        else if (cmd == "delete") {
            cin >> num;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == num) {
                    nums.erase(nums.begin() + i);
                    break;
                }
            }

        }
        else if (cmd == "deleteFirst") {
            nums.pop_front();
        }
        else if (cmd == "deleteLast") {
            nums.pop_back();
        }

    }

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << nums[i];
    }
    cout << endl;
    return 0;
}