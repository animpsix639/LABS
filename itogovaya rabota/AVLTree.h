#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"
#include <algorithm>

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node);
    int balanceFactor(AVLNode* node);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
    AVLNode* insert(AVLNode* node, int key);
    AVLNode* minValueNode(AVLNode* node);
    AVLNode* deleteNode(AVLNode* root, int key);
    void inorder(AVLNode* root);

public:
    AVLTree();
    ~AVLTree();

    void insert(int key);
    void deleteKey(int key);
    void printInorder();
};

#endif // AVLTREE_H