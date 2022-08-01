#include <iostream>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;

    Node(int v) : value { v }, left { nullptr }, right { nullptr } {}
    ~Node() {}
};

struct BinarySearchTree {
    Node* root;
    int node_count;

    BinarySearchTree() : root { nullptr }, node_count { 0 } {}
    ~BinarySearchTree() {}

    void recursive_in_order(Node* node) {
        if (!node) {
            return;
        }

        recursive_in_order(node->left);

        cout << node->value << endl;

        recursive_in_order(node->right);
    }

    void iterative_insert(int new_node_value) {
        // check if the root is null
        if (!this->root) {
            Node* new_node = new Node { new_node_value };
            this->root = new_node;
            this->node_count++;
            return;
        }

        // define pointers
        Node* current_node = this->root;
        Node* temporary_node = current_node;

        while (current_node) {
            // assign the previous node
            temporary_node = current_node;

            // check which sub-tree to traverse down
            if (new_node_value < current_node->value) {
                current_node = current_node->left;
            } else if (new_node_value > current_node->value) {
                current_node = current_node->right;
            } else {
                // if they are equal
                return;
            }
        }

        Node* new_node = new Node { new_node_value };
        if (new_node_value < temporary_node->value) {
            temporary_node->left = new_node;
        } else {
            temporary_node->right = new_node;
        }
    }
};

int main() {
    BinarySearchTree bst = {};
    bst.iterative_insert(10);
    bst.iterative_insert(100);
    bst.iterative_insert(1000);
    bst.iterative_insert(10000);
    bst.recursive_in_order(bst.root);

    return 0;
}