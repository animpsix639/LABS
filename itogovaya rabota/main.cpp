#include <iostream>
#include "AVLTree.h"

int main() {
    AVLTree tree;
    int n, key;

    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    std::cout << "Введите элементы: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> key;
        tree.insert(key);
    }

    std::cout << "Обход дерева в порядке возрастания: ";
    tree.printInorder();

    std::cout << "Введите ключ для удаления: ";
    std::cin >> key;
    tree.deleteKey(key);

    std::cout << "Обход дерева после удаления: ";
    tree.printInorder();

    return 0;
}