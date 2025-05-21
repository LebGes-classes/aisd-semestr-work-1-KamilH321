//
// Created by Камиль on 20.05.2025.
//

#include "avl_tree.h"
#include <iostream>

using namespace std;

// создание нового узла
Node* newNode(int key) {
    Node* node = new Node(key);
    return node;
}

// получение высоты
int getHeight(Node* root) {
    return root ? root->height : 0;
}

// получение коэффицента баланса
int delta(Node *root) {
    if (root == nullptr)
        return 0;
    return (getHeight(root->left) - getHeight(root->right));

}

// поворот поддерева вправо
Node *rightRotate(Node *root) {
    Node *x = root->left;
    Node *y = x->right;

    x->right = root;
    root->left = y;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

// поворот поддерева влево
Node *leftRotate(Node *root) {
    Node *x = root->right;
    Node *y = x->left;

    x->left = root;
    root->right = y;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

//поиск элемента
bool search(Node *root, int key) {
    // возвращает false, если значение не найдено
    if (root == nullptr) {
        return false;
    }

    // возвращает true, если значение найдено
    if (root->key == key) {
        return true;
    }

    // если принимаемое значение меньше текущего, передвигаемся в левое поддерево
    if (key < root->key) {
        return search(root->left, key);
    }

    // если принимаемое значение больше текущего, передвигаемся в правое поддерево
    if (key > root->key) {
        return search(root->right, key);
    }
}

//вставка элемента
Node *insert(Node *root, int key) {
    // если дерево пустое
    if (root == nullptr) {
        root = newNode(key);
    }

    // идём в левое поддерево
    else if (key < root->key) {
        root->left = insert(root->left, key);
    }

    //идём в правое поддерево
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    // случай если ключ уже существует
    else {
        return root;
    }

    // обновляем высоту
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // проверка баланса дерева
    int balance = delta(root);
    if (balance > 1 && key < root->left->key) {
        return rightRotate(root);
    }

    if (balance < -1 && key > root->right->key) {
        return leftRotate(root);
    }

    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// удаление элемента
Node *erase(Node *root, int key) {
    // если дерево пустое
    if (root == nullptr) {
        return nullptr;
    }

    // идём в левое поддерево
    if (key < root->key) {
        root->left = erase(root->left, key);
    }

    //идём в правое поддерево
    else if (key > root->key) {
        root->right = erase(root->right, key);
    }

    else {
        // узел не имеет потомков или только один потомок
        if (root->left == nullptr || root->right == nullptr) {
            Node *temp;
            if (root->left == nullptr) {
                temp = root->right;
            }
            else {
                temp = root->left;
            }
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else {
                *root = *temp;
            }
            delete temp;
        }
        // у узла есть оба потомка
        else {
            //ищем минимальный элемент дерева
            Node *temp = root;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            root->key = temp->key;
            root->right = erase(root->right, temp->key);
        }
    }

    if (root == nullptr) {
        return root;
    }

    // обновляем высоту
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // проверка баланса дерева
    int balance = delta(root);
    if (balance > 1 && key < root->left->key) {
        return rightRotate(root);
    }

    if (balance < -1 && key > root->right->key) {
        return leftRotate(root);
    }

    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}






