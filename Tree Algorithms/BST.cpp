#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

// Insert a node
Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// In-order traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Search with path output
bool search(Node* root, int key) {
    Node* cur = root;
    cout << "Search path: ";
    while (cur != nullptr) {
        cout << cur->data << " ";
        if (cur->data == key) {
            cout << "\nElement " << key << " found in BST.\n";
            return true;
        } else if (key < cur->data) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    cout << "\nElement " << key << " not found in BST.\n";
    return false;
}

// Find minimum node
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// Delete a node from BST
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    // Insert values as in your image
    int keys[] = {21, 14, 28, 11, 18, 25, 32, 5, 12, 15, 19, 23, 27, 30, 37};
    int n = sizeof(keys) / sizeof(keys[0]);
    Node* root = nullptr;
    for (int i = 0; i < n; ++i)
        root = insert(root, keys[i]);

    cout << "In-order traversal: ";
    inorder(root);
    cout << endl;

    // Search for 27
    search(root, 27);

    // Delete 27
    cout << "\nDeleting 27...\n";
    root = deleteNode(root, 27);

    cout << "In-order after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
