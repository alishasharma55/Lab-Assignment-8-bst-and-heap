#include <iostream>
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

// Insert Node in BST
Node* insert(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// (a) Recursive Search
Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);

    return searchRecursive(root->right, key);
}

// (a) Non-Recursive Search
Node* searchNonRecursive(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return root;

        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

// (b) Minimum Element
Node* findMin(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// (c) Maximum Element
Node* findMax(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

// (d) Inorder Successor
Node* inorderSuccessor(Node* root, Node* x) {
    Node* succ = NULL;

    if (x->right != NULL)
        return findMin(x->right);

    while (root != NULL) {
        if (x->data < root->data) {
            succ = root;
            root = root->left;
        }
        else if (x->data > root->data) {
            root = root->right;
        }
        else
            break;
    }
    return succ;
}

// (e) Inorder Predecessor
Node* inorderPredecessor(Node* root, Node* x) {
    Node* pred = NULL;

    if (x->left != NULL)
        return findMax(x->left);

    while (root != NULL) {
        if (x->data > root->data) {
            pred = root;
            root = root->right;
        }
        else if (x->data < root->data) {
            root = root->left;
        }
        else
            break;
    }
    return pred;
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

    // Search
    int key = 40;

    if (searchRecursive(root, key))
        cout << "Recursive Search: Found " << key << endl;
    else
        cout << "Recursive Search: Not Found" << endl;

    if (searchNonRecursive(root, key))
        cout << "Non-Recursive Search: Found " << key << endl;
    else
        cout << "Non-Recursive Search: Not Found" << endl;

    // Minimum and Maximum
    cout << "Minimum Element: " << findMin(root)->data << endl;
    cout << "Maximum Element: " << findMax(root)->data << endl;

    // Successor & Predecessor
    Node* node = searchRecursive(root, 40);

    Node* succ = inorderSuccessor(root, node);
    Node* pred = inorderPredecessor(root, node);

    if (succ)
        cout << "Inorder Successor of 40: " << succ->data << endl;

    if (pred)
        cout << "Inorder Predecessor of 40: " << pred->data << endl;

    return 0;
}
