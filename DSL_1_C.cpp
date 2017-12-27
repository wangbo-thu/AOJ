// DSL_2_B.cpp
// Range Query - Range Sum Query
// Refs:
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2128527#1
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1824167#1
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int INIT = 0;
struct SegmentTreeNode {
    int val;
    int start, end;
    SegmentTreeNode *left, *right;
    SegmentTreeNode() {}
    SegmentTreeNode(int start, int end) :
            start(start), end(end), val(INIT), left(NULL), right(NULL) {}
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

void add(SegmentTreeNode* node, int i, int x) {
    int lt, rt, mid;
    while (node) {
        lt = node->start;
        rt = node->end;
        mid = lt + (rt - lt) / 2;
        node->val += x;
        if (i <= mid) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
}

int getSum(SegmentTreeNode* node, int s, int t) {
    if (!node) return INIT;
    if (node->start == s && node->end == t)
        return node->val;
    int mid = (node->start + node->end) / 2;
    if (t <= mid) {
        return getSum(node->left, s, t);
    }
    else if (s > mid) {
        return getSum(node->right, s, t);
    }
    else {
        return getSum(node->left, s, mid) + getSum(node->right, mid + 1, t);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    SegmentTreeNode* st = buildTree(1, n);
    int com, x, y;
    while (q--) {
        cin >> com >> x >> y;
        if (com) {
            cout << getSum(st, x, y) << endl;
        }
        else {
            add(st, x, y);
        }
    }
    return 0;
}