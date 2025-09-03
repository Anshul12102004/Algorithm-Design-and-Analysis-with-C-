#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char d) : data(d), left(nullptr), right(nullptr) {}
};

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    // Construct the tree 
    Node* F = new Node('F');
    Node* B = new Node('B');
    Node* G = new Node('G');
    Node* A = new Node('A');
    Node* D = new Node('D');
    Node* I = new Node('I');
    Node* C = new Node('C');
    Node* E = new Node('E');
    Node* H = new Node('H');

    F->left = B;
    F->right = G;
    B->left = A;
    B->right = D;
    D->left = C;
    D->right = E;
    G->right = I;
    I->left = H;

    cout << "Preorder traversal: ";
    preorder(F);
    cout << endl;

    return 0;
}
