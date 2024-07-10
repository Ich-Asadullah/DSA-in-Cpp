#include <iostream>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int val) : key(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    TreeNode* root;

    int _get_height(TreeNode* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int _get_balance(TreeNode* node) {
        if (node == nullptr) return 0;
        return _get_height(node->left) - _get_height(node->right);
    }

    TreeNode* _rotate_left(TreeNode* z) {
        TreeNode* y = z->right;
        TreeNode* T2 = y->left;

        y->left = z;
        z->right = T2;

        z->height = 1 + max(_get_height(z->left), _get_height(z->right));
        y->height = 1 + max(_get_height(y->left), _get_height(y->right));

        return y;
    }

    TreeNode* _rotate_right(TreeNode* z) {
        TreeNode* y = z->left;
        TreeNode* T3 = y->right;

        y->right = z;
        z->left = T3;

        z->height = 1 + max(_get_height(z->left), _get_height(z->right));
        y->height = 1 + max(_get_height(y->left), _get_height(y->right));

        return y;
    }

    TreeNode* _insert(TreeNode* node, int key) {
        if (node == nullptr) return new TreeNode(key);

        if (key < node->key)
            node->left = _insert(node->left, key);
        else if (key > node->key)
            node->right = _insert(node->right, key);
        else
            return node;

        node->height = 1 + max(_get_height(node->left), _get_height(node->right));

        int balance = _get_balance(node);

        if (balance > 1 && key < node->left->key)
            return _rotate_right(node);
        if (balance < -1 && key > node->right->key)
            return _rotate_left(node);
        if (balance > 1 && key > node->left->key) {
            node->left = _rotate_left(node->left);
            return _rotate_right(node);
        }
        if (balance < -1 && key < node->right->key) {
            node->right = _rotate_right(node->right);
            return _rotate_left(node);
        }

        return node;
    }

    TreeNode* _get_min_value_node(TreeNode* node) {
        TreeNode* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    TreeNode* _delete(TreeNode* node, int key) {
        if (node == nullptr) return node;

        if (key < node->key)
            node->left = _delete(node->left, key);
        else if (key > node->key)
            node->right = _delete(node->right, key);
        else {
            if (node->left == nullptr || node->right == nullptr) {
                TreeNode* temp = node->left ? node->left : node->right;
                // No Child
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else { // One Child
                    *node = *temp;
                }
                delete temp;
            } else { // 2 Childern
                TreeNode* temp = _get_min_value_node(node->right);
                node->key = temp->key;
                node->right = _delete(node->right, temp->key);
            }
        }

        if (node == nullptr) return node;

        node->height = 1 + max(_get_height(node->left), _get_height(node->right));

        int balance = _get_balance(node);

        if (balance > 1 && _get_balance(node->left) >= 0)
            return _rotate_right(node);
        if (balance < -1 && _get_balance(node->right) <= 0)
            return _rotate_left(node);
        if (balance > 1 && _get_balance(node->left) < 0) {
            node->left = _rotate_left(node->left);
            return _rotate_right(node);
        }
        if (balance < -1 && _get_balance(node->right) > 0) {
            node->right = _rotate_right(node->right);
            return _rotate_left(node);
        }

        return node;
    }

public:
    // Public Functions for access
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = _insert(root, key);
    }

    void deleteKey(int key) {
        root = _delete(root, key);
    }

    int height() {
        return _get_height(root);
    }
};

int main() {
    AVLTree avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    cout << "AVL tree height: " << avl.height() << endl;

    avl.deleteKey(30);
    avl.deleteKey(25);

    cout << "AVL tree height after deletions: " << avl.height() << endl;

    return 0;
}
