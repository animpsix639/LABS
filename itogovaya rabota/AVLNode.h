#ifndef AVLNODE_H
#define AVLNODE_H

#include <iostream> 

class AVLNode {
public:
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int key);
    virtual ~AVLNode();
};

#endif // AVLNODE_H