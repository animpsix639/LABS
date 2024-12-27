#include "AVLTree.h"
#include <algorithm>
#include <iostream>

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    delete root;
}

int AVLTree::height(AVLNode* node) {
    return node ? node->height : 0;
}

int AVLTree::balanceFactor(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

AVLNode* AVLTree::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* AVLTree::leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode* AVLTree::insert(AVLNode* node, int key) {
    if (!node) return new AVLNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVLNode* AVLTree::minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left)
        current = current->left;
    return current;
}

AVLNode* AVLTree::deleteNode(AVLNode* root, int key) {
    if (!root) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            AVLNode* temp = root->left ? root->left : root->right;

            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {
            AVLNode* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root) return root;

    root->height = 1 + std::max(height(root->left), height(root->right));

    int balance = balanceFactor(root);

    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void AVLTree::inorder(AVLNode* root) {
    if (root) {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }
}

void AVLTree::insert(int key) {
    root = insert(root, key);
}

void AVLTree::deleteKey(int key) {
    root = deleteNode(root, key);
}

void AVLTree::printInorder() {
    inorder(root);
    std::cout << std::endl;
}