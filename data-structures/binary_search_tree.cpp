#include <iostream>

using namespace std;

class Node {
    public:
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
    public:
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
        if (root->value == value) {
            return true;
        }

        // check for which sub-tree to recurse down
        if (value < root->value) {
            return recursive_search(root->left, value);
        } else if (value > root->value) {
            return recursive_search(root->right, value);
        }
    }

    bool iterative_search(Node* root, long int value) {
        // while the current node is not nullptr
        // no need for stack because are not traversing back up the tree which would contain previous nodes
        while (root) {
            // check if the current node contains the valueue
            if (root->value == value) {
                return true;
            }

            // check which sub-tree to traverse down
            if (value < root->value) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return false;
    }

    // insert a valueue
    // if the root valueue is equal then it is already inserted -> base case
    // repeat till base case or able to insert
    bool iterative_insert(Node* root, long int value) {
        Node* previous = nullptr;
        while (root) {
            previous = root;
            if (value == root->value) {
                return false;;
            } else if (value < root->value) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        previous = new Node { value };
        if (previous->value < root->value) {
            root->left = previous;
        } else {
            root->right = previous;
        }
    }

    Node* recursive_insert(Node* root, long int value) {
        static Node* new_node;
        if (!root) {
            new_node = new Node { value };
            return new_node;
        }

        if (value < root->value) {
            root->left = recursive_insert(root->left, value);
        } else if (value > root->value) {
            root->right = recursive_insert(root->right, value);
        }

        return root;
    }

    // delete a value
    // like searching but updateing pointers
    // two cases leaf node and non-leaf nodes
    // link to child instead of parent if the node has a child
    bool iterative_delete(Node* root, long int value) {
        return true;
    }

    bool recursive_delete(Node* root, long int value) {

        return true;
    }

    // generate a binary tree from a given vector of numbers in pre-order
    // iterate through a given sequcne of numbers and then call insert()
    // insert takes n and search takes log n so n log n time
    bool recursive_generate() {
        return true;

    }

    bool iterative_generate() {

        return true;
    }

    void generate_from_pre_order() {
        return;
    }
};

int main() {
    BinarySearchTree bst = {};
    // modify this, I do not like this design pattern
    // just add a non root base case
    bst.root = bst.recursive_insert(bst.root, 10);

    cout << bst.root->value << endl;
    return 0;
}