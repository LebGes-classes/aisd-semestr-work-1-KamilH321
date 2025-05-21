//
// Created by Камиль on 20.05.2025.
//

#ifndef AVL_TREE_H
#define AVL_TREE_H



class Node {
    public:
        int key;
        int height;
        Node* left;
        Node* right;
        Node(int key) {
            this->key = key;
            this->left = nullptr;
            this->right = nullptr;
            this->height = 1;
        }
};

Node* newNode(int key);
int getHeight(Node* root);
Node* leftRotate(Node* root);
Node* rightRotate(Node* root);
int delta(Node* root);
Node* insert(Node* root, int key);
Node* erase(Node* root, int key);
bool search(Node *root, int key);

#endif //AVL_TREE_H
