#include <iostream>
#include <queue>
#include "Node_define.h"

#define BINARY_TREE

template <typename T>
class BinaryTree {
public:
        BinaryTree(){
                root = create_tree(root);
        }
        ~BinaryTree(){
                delete_tree(root);
        }
        void preorder_tree(Node<T> *tree);
        void inorder_tree(Node<T> *tree);
        void epilogue_tree(Node<T> *tree);
        void level_traverse(Node<T> *tree);

private:
        //问询法创建二叉树
        Node<T> *create_tree(Node<T> *tree);
        void delete_tree(Node<T> *tree);
        Node<T> *root;
};

template <typename T>
Node<T> *BinaryTree<T>::create_tree(Node<T> *tree) {
        char c;
        tree = new Node<T>();
        std::cout << "请输入一个数据： " << std::endl;
        std::cin >> tree->value; //输入value
        std::cin.sync(); //清除缓存区，读取'\n'换行
        std::cout << "是否为 " << tree->value << " 创建左子树: (y/n)" << std::endl;
        std::cin >> c;
        std::cin.sync();
        if ('y' == c) {
                tree->left = create_tree(tree->left);
        } else {
                tree->left = nullptr;
        }
        std::cout << "是否为 " << tree->value << " 创建右子树: (y/n)" << std::endl;
        std::cin >> c;
        std::cin.sync();
        if ('y' == c) {
                tree->right = create_tree(tree->right);
        } else {
                tree->right = nullptr;
        }

        return tree;
}

template <typename T>
void BinaryTree<T>::delete_tree(Node<T> *tree) {
        if (nullptr == tree) {
                return ;
        }

        delete_tree(tree->left);
        delete_tree(tree->right);
        delete tree;
        tree = nullptr;
        return ;
}

template <typename T>
void BinaryTree<T>::preorder_tree(Node<T> *tree) {
        if (nullptr != tree) {
                std::cout << tree->value;
                preorder_tree(tree->left);
                preorder_tree(tree->right);
        }
}

template <typename T>
void BinaryTree<T>::inorder_tree(Node<T> *tree) {
        if (nullptr != tree) {
                inorder_tree(tree->left);
                std::cout << tree->value;
                inorder_tree(tree->right);
        }
}

template <typename T>
void BinaryTree<T>::epilogue_tree(Node<T> *tree) {
        if (nullptr != tree) {
                epilogue_tree(tree->left);
                epilogue_tree(tree->right);
                std::cout << tree->value;
        }
}

template <typename T>
void BinaryTree<T>::level_traverse(Node<T> *tree) {
        Node<T> *node;
        std::queue<Node<T> *> que;
        que.push(tree);
        while (!que.empty()) {
                node = que.front();
                que.pop();
                std::cout << node->value;
                if (node->left) {
                        que.push(node->left);
                }
                if (node->right) {
                        que.push(node->right);
                }
        }
}