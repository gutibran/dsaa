#include <iostream>

class Node {
    long int value;
    Node* left;
    Node* right;

    // constructor for Node
    Node(long int in_value) : value { in_value }, left { nullptr }, right { nullptr } {};

    // destructor for Node
    ~Node() {}
};

/*
    DRAWBACKS:
        * no control of the height -> depends on how nodes are inserted
        * AVL trees control their height -> solves this problem
        * insertion can be minimum logn or max n
*/
class BinarySearchTree {
    Node* root;
    size_t node_count;

    // constructor for BinarySearchTree
    BinarySearchTree() : root { nullptr }, node_count { 0 } {};

    // destructor for BinarySearchTree
    ~BinarySearchTree() {}

    // search for a given value
    bool recursive_search(Node* root, long int value) {
        // base case
        if (!root) {
            return false;
        }

        // check if the current element is a match
        if (root->val == value) {
            return true;
        }

        // check for which sub-tree to recurse down
        if (value < root->val) {
            return recursive_search(root->left, value);
        } else if (value > root->val) {
            return recursive_search(root->right, value);
        }
    }

    bool iterative_search(Node* root, long int value) {
        // while the current node is not nullptr
        // no need for stack because are not traversing back up the tree which would contain previous nodes
        while (root) {
            // check if the current node contains the value
            if (root->val == value) {
                return true;
            }

            // check which sub-tree to traverse down
            if (value < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return false;
    }

    // insert a value
    bool iterative_insert(Node* root, long int value) {

    }

    bool recursive_insert(Node* root, long int value) {

    }

    // delete a value
    bool iterative_delete(Node* root, long int value) {

    }

    bool recursive_delete(Node* root, long int value) {

    }

    // generate a binary tree from a given vector of numbers in pre-order
    bool recursive_generate() {

    }

    bool iterative_generate() {

    }
}

int main() {

    return 0;
}