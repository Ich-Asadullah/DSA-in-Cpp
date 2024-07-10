#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

// Function to find the minimum value node in a tree
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from a BST
Node* deleteNode(Node* root, int key) {
    // Base case: the tree is empty
    if (root == nullptr) return root;

    // Recur down the tree
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted is found
        // Case 1: Node has no children (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: Node has one child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Node has two children
        else {
            Node* temp = findMin(root->right); // Find the inorder successor
            root->key = temp->key; // Copy the inorder successor's content to this node
            root->right = deleteNode(root->right, temp->key); // Delete the inorder successor
        }
    }
    return root;
}

// Function to insert a new node with a given key
Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to perform an inorder traversal of the tree
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal of the given tree: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Delete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Delete 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Delete 50\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
