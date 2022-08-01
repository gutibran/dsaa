#include <iostream>

using namespace std;

struct Node {
    long int value;
    Node* left;
    Node* right;

    Node(long int in_value) : value { in_value }, left { nullptr }, right { nullptr } {}

    ~Node() {}
};

struct BinarySearchTree {
    Node* root;
    size_t node_count;

    // constructor
    BinarySearchTree() : root { nullptr }, node_count { 0 } {}

    // destructor
    ~BinarySearchTree() {}

    // check if the tree is empty
    bool is_empty() {
        if (!this->root) {
            return true;
        }
        return false;
    }

    // insert into a binary search tree
    Node* recursive_insert(Node* root, long int value) {
        // check if the root of the tree is absent
        if (this->is_empty()) {
            Node* new_node = new Node { value }; 
            this->root = new_node;
            return new_node;
        }

        // base case for the recursive part of the function
        if (!root) {
            Node* new_node = new Node { value }; 
            return new_node;
        }

        // determine which sub-tree to traverse down
        if (value < root->value) {
            root->left = recursive_insert(root->left, value);
        } else if (value > root->value) {
            root->right = recursive_insert(root->right, value);
        }

        return root;
    }

    void iterative_insert(Node* root, long int value) {
        Node* rooted = nullptr;
        Node* previous = nullptr;
        while (root) {

            rooted = root;

            if (value == root->value) {
                return;
            } else if (value < root->value) {
                root = root->left;
            } else {
                root = root->right;
            }
        }

        previous = new Node { value };

        if (previous->value < rooted->value) {
            rooted->left = previous;
        } else {
            rooted->right = previous;
        }
    }

    bool recursive_search(Node* root, long int value) {
        // base case
        if (!root) {
            return false;
        }

        // traverse
        if (root->value == value) {
            return true;
        }

        if (value < root->value) {
            return recursive_search(root->left, value);
        } else {
            return recursive_search(root->right, value);
        }
    }

    bool iterative_search(Node* root, long int value) {
        while (root) {
            if (root->value == value) {
                return true;
            }

            if (value < root->value) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return false;
    }

    // inorder successor and predecessor -> search for one of these
    // runtiume depends on height -> logn

    bool iterative_delete(Node* root, long int value) {
        return true;
    }

    // find succesor -> helper for delteeing - node after the node to be delted - right of root and left most
    // find predecessor -> helper for deleteing - node before the node to be deleted - left of root and right modst
    // use either one
    // find hight of sub tree -> helper for deleteing -> logn -> for modificatoins too
    // generalize the cases

    // generate bst from preordered array numbers (preorder + inorder) || post order + inorder
    // just pre and post
    // need stack
    // crteate a root node and point to it
    // iterate through the numbers and compare it to the root
    // then ponit to new node and push it to the staCK  
    // if right child dont push address

    // drawbacks -> height can get tall depending on the sorting of the numbers -> avl trees solve this -> linear
    // bt -> log n

    // recursive hoe
    Node* recursive_delete(Node* root, long int value) {
        // hold onto the deleted node
        Node* deleted_node;

        // base case
        if (!root) {
            return nullptr;
        }

        if (!root->left && !root->right) {
            if (root == rooted) {
                root = nullptr;
            }
            // deallocate the memory and return null
            delete root;
            return nullptr;
        }

        if (value < root->value) {
            root->left = recursive_delete(root->left, value);
        } else if (value > root->value) {
            root->right = recursive_delete(root->right, value);
        } else {
            if (this->get_height(root->left) > this->get_height(root->right)) {

            } else {

            }
        }
    }
};

int main() {
    BinarySearchTree bst = {};
    bst.recursive_insert(bst.root, 10);
    bst.iterative_insert(bst.root, 11);

    cout << bst.root->value << endl;
    cout << bst.root->right->value << endl;

    cout << bst.iterative_search(bst.root, 11) << endl;
    cout << bst.iterative_search(bst.root, 10) << endl;
    cout << bst.iterative_search(bst.root, 100) << endl;

    return 0;
}
