// ALDS1_8_C.cpp
// Binary search trees - Binary Search Tree III

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* lchild;
	TreeNode* rchild;
	//TreeNode* parent;
	TreeNode(int x) : val(x), lchild(NULL), rchild(NULL) {}
};

TreeNode *root = NULL;

void insert(TreeNode *&tree, TreeNode *node)
{
	if (tree) {
		TreeNode *tmp = tree;
		TreeNode *tmp2 = tmp;
		while (tmp != NULL) {
			tmp2 = tmp;
			if (node->val < tmp->val) {
				tmp = tmp->lchild;
			}
			else {
				tmp = tmp->rchild;
			}
		}
		if (node->val < tmp2->val) {
			tmp2->lchild = node;
		}
		else {
			tmp2->rchild = node;
		}
	}
	else {
		tree = node;
	}
}

void inorder(TreeNode *tree) {
	if (!tree) return;
	inorder(tree->lchild);
	cout << " " << tree->val;
	inorder(tree->rchild);
}

void preorder(TreeNode *tree) {
	if (!tree) return;
	cout << " " << tree->val;
	preorder(tree->lchild);
	preorder(tree->rchild);
}

void print(TreeNode *tree) {
	inorder(tree);
	cout << endl;
	preorder(tree);
	cout << endl;
}

TreeNode* find(TreeNode *tree, int num) {
	while (tree) {
		if (tree->val == num) {
			cout << "yes" << endl;
			return tree;
		}
		else if (tree->val < num) {
			tree = tree->rchild;
		}
		else {
			tree = tree->lchild;
		}
	}
	cout << "no" << endl;
	return NULL;
}

void del(TreeNode *tree, int num) {
	bool found = false;
	TreeNode *p = tree;
	TreeNode *pos = tree;
	while (tree && !found) {
		if (tree->val == num) {
			pos = tree;
			found = true;
		}
		else if (tree->val < num) {
			p = tree;
			tree = tree->rchild;
		}
		else {
			p = tree;
			tree = tree->lchild;
		}
	}
	if (!found) return;
	if (pos->lchild == NULL && pos->rchild == NULL) {
		if (root == pos) {
			root = NULL;
		}
		else if (p->lchild == pos) {
			p->lchild = NULL;
		}
		else {
			p->rchild = NULL;
		}
	}
	else if (pos->lchild == NULL) {
		if (root == pos) {
			root = pos->rchild;
		}
		else if (p->lchild == pos) {
			p->lchild = pos->rchild;
		}
		else {
			p->rchild = pos->rchild;
		}
	}
	else if (pos->rchild == NULL) {
		if (root == pos) {
			root = pos->lchild;
		}
		else if (p->lchild == pos) {
			p->lchild = pos->lchild;
		}
		else {
			p->rchild = pos->rchild;
		}
	}
	else {
		TreeNode* lc = pos->lchild;
		TreeNode* rc = pos->rchild;
		TreeNode *rmin = rc;
		TreeNode *rminP = pos;
		if (root == pos) {
			if (!rmin->lchild) {
				rmin->lchild = lc;
				root = rmin;
			}
			else {
				while (rmin->lchild) {
					rminP = rmin;
					rmin = rmin->lchild;
				}
				rminP->lchild = NULL;
				rmin->lchild = lc;
				rmin->rchild = rc;
				root = rmin;
			}
		}
		else if (p->lchild == pos) {
			if (!rmin->lchild) {
				rmin->lchild = lc;
				p->lchild = rmin;
			}
			else {
				while (rmin->lchild) {
					rminP = rmin;
					rmin = rmin->lchild;
				}
				rminP->lchild = NULL;
				rmin->lchild = lc;
				rmin->rchild = rc;
				p->lchild = rmin;
			}

		}
		else {
			if (!rmin->lchild) {
				rmin->lchild = lc;
				p->rchild = rmin;
			}
			else {
				while (rmin->lchild) {
					rminP = rmin;
					rmin = rmin->lchild;
				}
				rminP->lchild = NULL;
				rmin->lchild = lc;
				rmin->rchild = rc;
				p->rchild = rmin;
			}
		}
	}
}

int main()
{
	FILE *ss1, *ss2;
	freopen_s(&ss1, "in3.txt", "r", stdin);
	freopen_s(&ss2, "out3.txt", "w", stdout);
	int n;
	cin >> n;
	string cmd;
	int num;

	while (n--) {
		cin >> cmd;
		if (cmd == "insert") {
			cin >> num;
			TreeNode *node = new TreeNode(num);
			if (num == 865) {
				num = 865;
			}
			insert(root, node);
			print(root);
		}
		if (cmd == "find") {
			cin >> num;
			find(root, num);
		}
		if (cmd == "delete") {
			cin >> num;
			del(root, num);
			print(root);
		}
		if (cmd == "print")
			print(root);
	}
	return 0;
}