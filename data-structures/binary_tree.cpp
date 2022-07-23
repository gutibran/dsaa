#include <iostream>
#include <vector>
#include <limits>

struct Node {
    size_t value;
    Node* left;
    Node* right;

    // constructor
    Node(size_t in_value) : value { in_value }, left { nullptr }, right { nullptr } {}

    // destructor
    ~Node() {}
};

struct BinaryTree {
    Node* root;
    size_t nodes;
    size_t height;
    size_t levels;

    // constructor
    BinaryTree() : root { nullptr }, nodes { 0 }, height { 0 }, levels{ 0 } {};

    // destructor
    ~BinaryTree() {}

    // node, left, right
    void recursive_pre_order(Node* node) {
        // base case
        if (!node) {
            return;
        }
        
        // print out the current node's value
        std::cout << node->value << std::endl;

        // traverse down the left sub tree
        recursive_pre_order(node->left);

        // traverse down the right sub tree
        recursive_in_order(node->right);
    }

    void recursive_pre_order_insertion(Node* node, size_t new_node_value) {
        // base case
        if (!this->root) {
            // allocate memory in the heap
            Node* new_node = new Node { new_node_value };

            // set the root to the new node
            this->root = new_node;

            // break out of the recursive call
            return;
        } else if (!node->left) {
            // allocate memory in the heap
            Node* new_node = new Node { new_node_value };

            // set the root to the new node
            node->left = new_node;

            // break out of the recursive call
            return;
        } else if (!node->right) {
            // allocate memory in the heap
            Node* new_node = new Node { new_node_value };

            // set the root to the new node
            node->right = new_node;

            // break out of the recursive call
            return;
        }

        recursive_pre_order_insertion(node->left, new_node_value);
        recursive_pre_order_insertion(node->right, new_node_value);


    }

    void iterative_pre_order(Node* node) {
        return;
    }

    void iterative_pre_order_insertion(Node* node, size_t new_node_value) {
        return;
    }

    // left, node, right
    void recursive_in_order(Node* node) {
        // base case
        if (!node) {
            return;
        }

        // traverse down the left sub tree
        recursive_in_order(node->left);

        // print out the value of the current node
        std::cout << node->value << std::endl;

        // traverse down the right sub tree
        recursive_in_order(node->right);
    }

    void iterative_in_order(Node* node) {
        return;
    }

    void iterative_in_order_insertion(Node* node) {
        return;
    }

    void recursive_in_order_insertion(Node* node, size_t new_node_value) {
        // check if the root is null
        if (!this->root) {
            // create a new node object in the heap
            Node* new_node = new Node { new_node_value };

            // set the root to the new node
            this->root = new_node;

            // break out of the recursive function call
            return;
        } else if (!node) {
            return;
        }

        // traverse down the left sub tree
        recursive_in_order_insertion(node->left, new_node_value);


        // check if the left or right is null which we returned from
        if (!node->left) {
            // create a new node object in the heap
            Node* new_node = new Node { new_node_value };

            // set the left child to the new node
            node->left = new_node;

            // break out of the recursive function call
            return;
        } else if (!node->right) {
            // create a new node object in the heap
            Node* new_node = new Node { new_node_value };

            // set the right child to the new node
            node->right = new_node;

            // break out of the recursive function call
            return;
        }    

        // traverse down the right sub tree
        recursive_in_order_insertion(node->right, new_node_value);
    }
};

int main() {
    // create an instance of a binary tree
    BinaryTree bt = {};
    BinaryTree salo = {};

    bt.recursive_in_order_insertion(bt.root, 100);
    bt.recursive_in_order_insertion(bt.root, 200);
    bt.recursive_in_order_insertion(bt.root, 300);

    salo.recursive_pre_order_insertion(salo.root, 100);
    salo.recursive_pre_order_insertion(salo.root, 200);
    salo.recursive_pre_order_insertion(salo.root, 300);

    std::cout << "salo tree" << std::endl;
    salo.recursive_pre_order(salo.root);

    std::cout << "b tree" << std::endl;
    bt.recursive_pre_order(bt.root);

    return 0;
}