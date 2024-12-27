#include "AVLNode.h"

AVLNode::AVLNode(int key) : key(key), left(nullptr), right(nullptr), height(1) {}

AVLNode::~AVLNode() {
    delete left;
    delete right;
}