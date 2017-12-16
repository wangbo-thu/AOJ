// ALDS1_7_C.cpp
// Tree - Tree Walk

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int id;
	int lchild;
	int rchild;
	int parent = -1;
};

void Preorder(Node& root)
{
	if (root.lchild == -1 && root.rchild == -1)
		return;
	cout << " " << root.id;
	Preorder(root.lchild);
	Preorder(root.rchild);
}

void Inorder(Node& root)
{
	if (root.lchild == -1 && root.rchild == -1)
		return;
	Inorder(root.lchild);
	cout << " " << root.id;
	Inorder(root.rchild);
}

void Postorder(Node& root)
{
	if (root.lchild == -1 && root.rchild == -1)
		return;
	Postorder(root.lchild);
	Postorder(root.rchild);
	cout << " " << root.id;
}

int main()
{
	int n;
	cin >> n;
	vector<Node> nodes(n);
	for (int i = 0; i < n; i++) {
		int id, lc, rc;
		cin >> id >> lc >> rc;
		nodes[id].id = id;
		nodes[id].lchild = lc;
		nodes[id].rchild = rc;
		if (lc != -1) {
			nodes[lc].parent = id;
		}
		if (rc != -1) {
			nodes[rc].parent = id;
		}
	}
	
	Node root;
	for (int i = 0; i < n; i++) {
		if (nodes[i].parent == -1) {
			root = nodes[i];
			break;
		}
	}
	
	cout << "Preorder" << endl;
	Preorder(root);
	cout << "Inorder" << endl;
	Inorder(root);
	cout << "Postorder" << endl;
	Postorder(root);
	return 0;
}