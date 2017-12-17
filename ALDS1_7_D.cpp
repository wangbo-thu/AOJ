// ALDS1_7_D.cpp
// Tree - Reconstruction of a Tree

#include <iostream>
#include <vector>
using namespace std;

void reconst(vector<int>& pre, vector<int>& in, vector<int>& post)
{
    if (pre.empty()) return;
    int root = pre[0];
    int in_root = 0;
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == root) {
            in_root = i;
            break;
        }
    }
    vector<int> in_left(in.begin(), in.begin() + in_root);
    vector<int> in_right(in.begin() + in_root + 1, in.end());
    vector<int> pre_left(pre.begin() + 1, pre.begin() + in_root + 1);
    vector<int> pre_right(pre.begin() + in_root + 1, pre.end());
    reconst(pre_left, in_left, post);
    reconst(pre_right, in_right, post);
    post.push_back(root);
}

int main()
{
    int n;
    cin >> n;
    vector<int> preorder(n);
    vector<int> inorder(n);
    vector<int> postorder;
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    reconst(preorder, inorder, postorder);
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << postorder[i];
    }
    cout << endl;
    return 0;
}