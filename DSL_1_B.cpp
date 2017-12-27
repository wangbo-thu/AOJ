// DSL_2_B.cpp
// Range Query - Range Sum Query
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int INF = (1 << 31) - 1;
struct SegmentTreeNode {
    int val;
    int start, end;
    SegmentTreeNode *left, *right;
    SegmentTreeNode() {}
    SegmentTreeNode(int start, int end) :
            start(start), end(end), val(INF), left(NULL), right(NULL) {}
};

SegmentTreeNode* buildTree(int start, int end) {
    if (start > end) return NULL;
    SegmentTreeNode* head = new SegmentTreeNode(start, end);
    if (start < end) {
        int mid = start + (end - start) / 2;
        head->left = buildTree(start, mid);
        head->right = buildTree(mid + 1, end);
    }
    return head;
}

void update(SegmentTreeNode* node, int i, int x) {
    int lt, rt, mid;
    stack<SegmentTreeNode* > ms;
    while (node) {
        lt = node->start;
        rt = node->end;
        mid = lt + (rt - lt) / 2;
        ms.push(node);
        if (i <= mid) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    while (!ms.empty()) {
        node = ms.top();
        ms.pop();
        if (!node->left && !node->right) node->val = x;
        else node->val = min(node->left->val, node->right->val);
    }
}

int find(SegmentTreeNode* node, int s, int t) {
    if (!node) return INF;
    if (node->start == s && node->end == t)
        return node->val;
    int mid = (node->start + node->end) / 2;
    if (t <= mid) {
        return find(node->left, s, t);
    }
    else if (s > mid) {
        return find(node->right, s, t);
    }
    else {
        return min(find(node->left, s, mid), find(node->right, mid + 1, t));
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    SegmentTreeNode* st = buildTree(0, n-1);
    int com, x, y;
    while (q--) {
        cin >> com >> x >> y;
        if (com) {
            cout << find(st, x, y) << endl;
        }
        else {
            update(st, x, y);
        }
    }
    return 0;
}