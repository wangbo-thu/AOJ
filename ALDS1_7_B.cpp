// ALDS1_7_B.cpp
// Tree - Binary Trees

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Node
{
	int id;
	int parent = -1;
	int sibling = -1;
	int degree = 0;
	int depth = 0;
	int height = 0;
	string type = "internal node";
};

int main()
{
	int n;
	cin >> n;
	vector<Node> nodes(n);
	for (int i = 0; i < n; i++) {
		int idx, left, right;
		cin >> idx >> left >> right;
		nodes[idx].id = idx;
		if (left != -1) {
			nodes[left].parent = idx;
			nodes[idx].degree++;
			if (right != -1) {
				nodes[left].sibling = right;
				nodes[right].sibling = left;
			}
		}
		if (right != -1) {
			nodes[right].parent = idx;
			nodes[idx].degree++;
		}
		if (!nodes[idx].degree) nodes[idx].type = "leaf";
	}

	for (int i = 0; i < n; i++) {
		int j = i;
		while (nodes[j].parent != -1) {
			int child_h = nodes[j].height;
			j = nodes[j].parent;
			nodes[j].height = max(nodes[j].height, child_h + 1);
			nodes[i].depth++;
		}
		if (!nodes[i].depth) nodes[i].type = "root";
	}

	for (int i = 0; i < n; i++) {
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
			nodes[i].id, nodes[i].parent, nodes[i].sibling, nodes[i].degree, nodes[i].depth,
			nodes[i].height);
		cout << nodes[i].type << endl;
	}
	return 0;
}