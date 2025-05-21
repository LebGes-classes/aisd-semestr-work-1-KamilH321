#include <iostream>
#include "avl_tree.h"
using namespace std;

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 140);
    root = insert(root, 1);
    root = insert(root, 19);
    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 30);

    cout << "finding of element 20: ";
    if (search(root, 20) == true) {
        cout << "element is find!" << endl;
    }

    root = erase(root, 10);
    cout << "after deleting element 10: ";
    if (search(root, 10) == false) {
        cout << "Element is not found!" << endl;
    }

    cout << "root of tree: ";
    cout << root->key << endl;
    cout << "left and right branches of root: ";
    cout << root->left->key; cout << " "  << root->right->key << endl;
    cout << "Minimal element of tree: ";
    Node *temp = root;
    while (temp->left != nullptr) {
        temp = temp->left;
    }
    cout << temp->key << endl;
    cout << "Maximal element of tree: ";
    Node *temp2 = root;
    while (temp2->right != nullptr) {
        temp2 = temp2->right;
    }
    cout << temp2->key << endl;

    return 0;
}