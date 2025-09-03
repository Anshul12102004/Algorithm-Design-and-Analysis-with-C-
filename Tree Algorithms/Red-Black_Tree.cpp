#include <iostream>
using namespace std;

// Red-Black Tree Colors
enum Color { RED, BLACK };

// Red-Black Tree Node
struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data): data(data) {
        left = right = parent = nullptr;
        color = RED;
    }
};

// Util - Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Left rotate
void leftRotate(Node* &root, Node* &x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left) y->left->parent = x;
    y->parent = x->parent;
    if (!x->parent) root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

// Right rotate
void rightRotate(Node* &root, Node* &x) {
    Node* y = x->left;
    x->left = y->right;
    if (y->right) y->right->parent = x;
    y->parent = x->parent;
    if (!x->parent) root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->right = x;
    x->parent = y;
}

// Fix Red-Black Tree violations after insertion
void fixViolation(Node* &root, Node* &pt) {
    while (pt != root && pt->color == RED && pt->parent->color == RED) {
        Node* parent = pt->parent;
        Node* grandparent = parent->parent;

        // Parent is left child of grand-parent
        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;
            // Case 1: Uncle is RED
            if (uncle && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = uncle->color = BLACK;
                pt = grandparent;
            } else {
                // Case 2: pt is right child
                if (pt == parent->right) {
                    leftRotate(root, parent);
                    pt = parent;
                    parent = pt->parent;
                }
                // Case 3: pt is left child
                rightRotate(root, grandparent);
                swap(parent->color, grandparent->color);
                pt = parent;
            }
        }
        // Parent is right child of grand-parent
        else {
            Node* uncle = grandparent->left;
            if (uncle && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = uncle->color = BLACK;
                pt = grandparent;
            } else {
                if (pt == parent->left) {
                    rightRotate(root, parent);
                    pt = parent;
                    parent = pt->parent;
                }
                leftRotate(root, grandparent);
                swap(parent->color, grandparent->color);
                pt = parent;
            }
        }
    }
    root->color = BLACK;
}

// Standard BST insert + add Red-Black Tree fixup
void insert(Node* &root, int data) {
    Node* pt = new Node(data);
    Node* parent = nullptr;
    Node* cur = root;

    // BST insert
    while (cur) {
        parent = cur;
        if (data < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    pt->parent = parent;
    if (!parent) root = pt;
    else if (data < parent->data) parent->left = pt;
    else parent->right = pt;

    // Fix Red-Black properties
    fixViolation(root, pt);
}

int main() {
    Node* root = nullptr;
    int keys[] = {13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
    int n = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < n; ++i)
        insert(root, keys[i]);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}
