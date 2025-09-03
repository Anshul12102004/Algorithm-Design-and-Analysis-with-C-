#include <iostream>
#include <algorithm>
using namespace std;

// AVL Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int d) : data(d), left(nullptr), right(nullptr), height(1) {}
};

// Utility functions
int height(Node* node) { return node ? node->height : 0; }
void updateHeight(Node* node) {
    node->height = 1 + max(height(node->left), height(node->right));
}
int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Rotations
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

// Insertion
Node* insert(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else return node;

    updateHeight(node);
    int balance = getBalance(node);

    // Balancing
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

// Get minimum value node in the subtree
Node* minValueNode(Node* node) {
    Node* cur = node;
    while (cur->left != nullptr)
        cur = cur->left;
    return cur;
}

// Deletion
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    if (!root) return root;
    updateHeight(root);
    int balance = getBalance(root);

    // Balancing after deletion
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

// Traversals
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Main
int main() {
    int keys[] = {12, 8, 18, 5, 11, 17, 4};
    int n = sizeof(keys) / sizeof(keys[0]);
    Node* root = nullptr;
    // Create initial AVL Tree
    for (int i = 0; i < n; ++i) root = insert(root, keys[i]);

    cout << "Original tree (inorder): ";
    inorder(root); cout << endl;
    cout << "Original tree (preorder): ";
    preorder(root); cout << endl << endl;

    // Insertion: insert 6
    cout << "After insertion of 6:" << endl;
    root = insert(root, 6);
    cout << "Inorder: "; inorder(root); cout << endl;
    cout << "Preorder: "; preorder(root); cout << endl << endl;

    // Deletion: delete 5
    cout << "After deletion of 5:" << endl;
    root = deleteNode(root, 5);
    cout << "Inorder: "; inorder(root); cout << endl;
    cout << "Preorder: "; preorder(root); cout << endl << endl;



    return 0;
}
