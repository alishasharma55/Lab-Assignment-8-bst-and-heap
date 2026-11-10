#include <iostream>
#include <climits>
using namespace std;

// Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Function to check BST
bool isBST(Node* root, int minVal, int maxVal) {
    if (root == NULL)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

int main() {
    /*
            50
           /  \
         30    70
        / \   / \
      20  40 60 80
    */

    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    if (isBST(root, INT_MIN, INT_MAX))
        cout << "The given binary tree is a BST." << endl;
    else
        cout << "The given binary tree is NOT a BST." << endl;

    return 0;
}
