#include <iostream>
#include <algorithm>
using namespace std;

// BST Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Insert (No Duplicates Allowed)
Node* insert(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        cout << "Duplicate element not allowed: " << key << endl;

    return root;
}

// Find Minimum Node
Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete Node
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // Node with no child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Node with one child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Maximum Depth
int maxDepth(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Minimum Depth
int minDepth(Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL)
        return 1 + minDepth(root->right);

    if (root->right == NULL)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// Inorder Traversal
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "BST (Inorder): ";
    inorder(root);

    cout << "\nMaximum Depth: " << maxDepth(root);
    cout << "\nMinimum Depth: " << minDepth(root);

    root = deleteNode(root, 70);

    cout << "\nBST after deleting 70: ";
    inorder(root);

    cout << endl;

    return 0;
}
