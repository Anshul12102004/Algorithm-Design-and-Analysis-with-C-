#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char d) : data(d), left(nullptr), right(nullptr) {}
};

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    // Construct the tree as shown in the image
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

    cout << "Postorder traversal: ";
    postorder(F);
    cout << endl;

    return 0;
}
