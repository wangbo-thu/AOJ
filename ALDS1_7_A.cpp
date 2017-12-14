// ALDS1_7_A.cpp
// Tree - Rooted Tree
// printf 不能直接输出string类型,得加上.c_str()转换，或者用cout

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;

struct Node
{
	int id;
	int parent = -1;
	int depth = 0;
	string type = "internal node";
	vector<int> children = {};
};

int main()
{
	int n;
	cin >> n;
	vector<Node> nodes(n);
	for (int i = 0; i < n; i++) {
		int id;
		int child_num;
		cin >> id >> child_num;
		nodes[id].id = id;
		if (!child_num) nodes[id].type = "leaf";
		while (child_num--) {
			int tmp;
			cin >> tmp;
			nodes[id].children.push_back(tmp);
			nodes[tmp].parent = id;
		}
	}

	for (int i = 0; i < n; i++) {
		int depth = 0;
		int j = i;
		while (nodes[j].parent != -1) {
			j = nodes[j].parent;
			depth++;
		}
		nodes[i].depth = depth;
		if (!depth)
			nodes[i].type = "root";
		printf("node %d: parent = %d, depth = %d, ",
			nodes[i].id, nodes[i].parent, nodes[i].depth);

		cout << nodes[i].type << ", [";
		for (int k = 0; k < nodes[i].children.size(); k++) {
			if (k > 0) printf(", ");
			printf("%d", nodes[i].children[k]);
		}
		printf("]\n");
	}

	return 0;
}