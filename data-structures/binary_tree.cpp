#include <iostream>
#include <vector>

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

    // insert a new node in to the tree
    bool insert(Node* node, size_t new_node_value) {
        // base case
        if (!node && !this->root) {
            // allocate memory in the heap for the new node
            Node* new_node = new Node { new_node_value };

            // set the root to the new node
            this->root = new_node;

            // return true to signify that the operation succeeded
            return true;
        }

        // check if the left child is null for the current node
        if (!node->left) {
            // allocate memory in the heap for the new node
            Node* new_node = new Node { new_node_value };

            // set the root to the new node
            node->left = new_node;

            // return true to signify that the operation succeeded
            return true;
        } else if (!node->right) {
            // allocate memory in the heap for the new node
            Node* new_node = new Node { new_node_value };

            // set the root to the new node
            node->right = new_node;

            // return true to signify that the operation succeeded
            return true;
        } 

        // traverse down the left and right sub-trees
        return insert(node->left, new_node_value);
        return insert(node->right, new_node_value);
    }


    // return the values of the nodes in pre-order
    void recursive_pre_order(Node* node) {
        if (node) {
            // print out the value of the current node
            std::cout << node->value << std::endl;

            // traverse down the left and right sub-trees
            recursive_pre_order(node->left);
            recursive_pre_order(node->right);
        }
        return;
    }

    void recursive_in_order(Node* node) {
        // create a static vector object
        if (node) {
            // traverse down the left sub-tree
            recursive_in_order(node->left);

            // print out the value of the current node
            std::cout << node->value << std::endl;

            // traverse down the right sub-tree
            recursive_in_order(node->right);
        }
        return;
    }

    void recursive_post_order(Node* node) {
        // base case
        if (node) {
            // traverse down the left sub-tree
            recursive_post_order(node->left);

            // traverse down the right sub-tree
            recursive_post_order(node->right);

            // print out the value of the current node
            std::cout << node->value << std::endl;
        }
        return;
    }
};

int main() {
    // create an instance of a binary tree
    BinaryTree bt = {};

    // insert some nodes
    bt.insert(bt.root, 1);
    bt.insert(bt.root, 2);
    bt.insert(bt.root, 3);
    bt.insert(bt.root, 4);
    bt.insert(bt.root, 5);

    // test out the implemented binary tree traversals
    std::cout << "pre-order" << std::endl;
    bt.recursive_pre_order(bt.root);

    std::cout << "in-order" << std::endl;
    bt.recursive_in_order(bt.root);

    std::cout << "post-order" << std::endl;
    bt.recursive_post_order(bt.root);

    return 0;
}