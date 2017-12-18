// ALDS1_8_A.cpp
// Binary search trees - Binary Search Tree I

#include <iostream>
#include <vector>
using namespace std;
const int NIL = -1;
struct TreeNode {
	int val;
	TreeNode* lchild;
	TreeNode* rchild;
	//TreeNode* parent;
	TreeNode(int x): val(x), lchild(NULL), rchild(NULL) {}
};

void insert(TreeNode &tree, TreeNode &node)
{
	if (!tree) {
		
		TreeNode tmp = tree;
		while (tree != NULL) {
			tmp = tree;
			if (node.val < tree.val) {
				tree = tree->lchild;
			}
			else {
				tree = tree->rchild;
			}
		} 
		if (node.val < tmp.val) {
			tmp->lchild = node;
		}
		else {
			tmp->rchild = node;
		}
	}
	else {
		tree.val = node.val;
	}
}

void inorder(TreeNode &tree) {
	if (!tree) return;
	inorder(tree->lchild);
	cout << " " << tree->val;
	inorder(tree->rchild);
}

void preorder(TreeNode &tree) {
	if (!tree) return;
	cout << " " << tree->val;
	preorder(tree->lchild);
	preorder(tree->rchild);
}

void print(TreeNode &tree) {
	inorder(tree);
	cout << endl;
	preorder(tree);
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	string cmd;
	int num;
	TreeNode tree;
	while(n--) {	
		cin >> cmd;
		if (cmd == "insert") {
			cin >> num;
			TreeNode node = TreeNode(num);
			insert(tree, node);
		}
		if (cmd == "print")
			print(tree);
	}
	return 0;
}