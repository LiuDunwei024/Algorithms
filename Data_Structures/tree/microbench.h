#include <iostream>
#include "Node_define.h"

#ifdef BINARY_TREE
        BinaryTree<int> tree;
#endif

enum traverse_type
{
        UNKNOWN = 0,
        PREORDER = 1,
        INORDER = 2,
        EPILOGUE = 3,
        LEVEL = 4
};

void crteate_tree() {
        Node<int> *root = NULL;
        tree.root = tree.create_tree(root);
}

void test_traverse(int ope) {
        if (PREORDER == ope) {
                tree.preorder_tree(tree.root);
        } else if (INORDER == ope) {
                tree.inorder_tree(tree.root);
        } else if (EPILOGUE == ope) {
                tree.epilogue_tree(tree.root);
        } else if (LEVEL == ope) {
                tree.level_traverse(tree.root);
        }
        std::cout << std::endl;
}

int main(int argc, char *argv[]) {
        if (2 != argc) {
                std::cout << "./programe_name param" << std::endl;
                return 0;
        }

        std::string programe_name = argv[0];
        int ope = atoi(argv[1]);

        crteate_tree();
        test_traverse(ope);

        return 0;
}