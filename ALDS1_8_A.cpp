// ALDS1_8_A.cpp
// Binary search trees - Binary Search Tree I

#include <iostream>
#include <vector>
using namespace std;
const int NIL = -1;
struct TreeNode {
	int val;
	int lchild;
	int rchild;
	int parent;
};

void insert(TreeNode &tree, int num)
{
	
	while (x != NIL) {
		y = x;
		if ()
	} 
}

int main()
{
	int n;
	cin >> n;
	string cmd;
	int num;
	vector<TreeNode> tree;
	while(n--) {	
		cin >> cmd;
		if (cmd == "insert") {
			cin >> num;
			insert(tree, num);
		}
		if (cmd == "print")
			print(tree);
	}
	return 0;
}