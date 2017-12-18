#include <cstdio>
#include <cstdlib>
 
using namespace std;
 
struct Node {
    int key;
    Node *left;
    Node *right;
};
 
int n, pos;
char command[7];
 
Node tree[500000];
Node *root;
 
inline Node *new_node(int key) {
    Node *node = &tree[pos++];
    node->key = key;
    return node;
}
 
bool insert_key(int key) {
    if (root == NULL) {
        root = new_node(key);
        return true;
    }
 
    Node *node = root, *parent = NULL;
    while (node) {
        parent = node;
        if (node->key > key) {
            node = node->left;
        }
        else if (node->key < key) {
            node = node->right;
        }
        else {
            return false;
        }
    }
 
    Node *newnode = new_node(key);
    if (key < parent->key) {
        parent->left = newnode;
    }
    else {
        parent->right = newnode;
    }
    return true;
}
 
Node *find_key(int key) {
    Node *node = root;
    while (node) {
        if (node->key > key) {
            node = node->left;
        }
        else if (node->key < key) {
            node = node->right;
        }
        else {
            return node;
        }
    }
    return NULL;
}
 
Node* delete_key(int key) {
 
    int direction = 0;
    Node *node = tree, *parent = NULL;
    while (node) {
        if (node->key > key) {
            parent = node;
            node = node->left;
            direction = -1;
        }
        else if (node->key < key) {
            parent = node;
            node = node->right;
            direction = 1;
        }
        else {
            break;      // node->key == key 
        }
    }
 
    if (node == NULL) {
        return NULL;    // Not Found 
    }
 
    // the node has one child only or none. 
    if (node->left == NULL || node->right == NULL) {
        if (node->left == NULL) {
            if (direction == -1) {
                parent->left = node->right;
            }
            else if (direction == 1) {
                parent->right = node->right;
            }
            else {
                root = node->right;
            }
        }
        else {
            if (direction == -1) {
                parent->left = node->left;
            }
            else if (direction == 1) {
                parent->right = node->left;
            }
            else {
                root = node->left;
            }
        }
    }
    else {  // the node has both left and right child. 
        Node *nextnode = node->right;
        parent = node;
        direction = 1;
        while (nextnode->left) {
            parent = nextnode;
            nextnode = nextnode->left;
            direction = -1;
        }
        node->key = nextnode->key;
        if (direction == -1) {
            parent->left = nextnode->right;
        }
        else {
            parent->right = nextnode->right;
        }
        node = nextnode;
    }
    return node;
}
 
void pre_order(Node *node) {
    printf(" %d", node->key);
    if (node->left) {
        pre_order(node->left);
    }
    if (node->right) {
        pre_order(node->right);
    }
}
 
void in_order(Node *node) {
    if (node->left) {
        in_order(node->left);
    }
    printf(" %d", node->key);
    if (node->right) {
        in_order(node->right);
    }
}
 
int main(void) {
 
    scanf("%d", &n);
 
    for (int i = 0, key; i < n; ++i) {
        scanf("%s", command);
        if (command[0] == 'i') {
            scanf("%d", &key);
            insert_key(key);
        }
        else if (command[0] == 'f') {
            scanf("%d", &key);
            printf("%s\n", find_key(key) ? "yes" : "no");
        }
        else if (command[0] == 'd') {
            scanf("%d", &key);
            delete_key(key);
        }
        else {  // print 
            if (root == NULL) { continue; }
            in_order(root);
            printf("\n");
            pre_order(root);
            printf("\n");
        }
    }
    return 0;
}