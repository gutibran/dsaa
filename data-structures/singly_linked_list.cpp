#include <iostream>
#include <limits>

struct Node {
    size_t value;
    Node* next;

    // constructor 
    Node(size_t in_value) : value { in_value }, next { nullptr } {}

    // destructor
    ~Node() {}
};

struct SinglyLinkedList {
    Node* head;
    size_t node_count;

    // constructor
    SinglyLinkedList() : head { nullptr }, node_count { 0 } {}

    // determine if the linked list is empty
    bool is_empty() {
        if (!this->head && this->node_count == 0) {
            return true;
        }
        return false;
    }

    // get the value of the head node
    size_t get_head() {
        if (!this->is_empty()) {
            return this->head->value;
        }
        return std::numeric_limits<int>::min();
    }

    // return the number of nodes in the list
    size_t get_node_count() {
        return this->node_count;
    }

    // add a new node to the front of the list
    bool prepend(size_t new_node_value) {
        // allocate memory in heap for the new node
        Node* new_node = new Node { new_node_value };
    
        // check if the head is null
        if (!this->head) {
            this->head = new_node;
            this->node_count++;
            return true;
        }

        // swap the pointers to the head
        new_node->next = this->head;
        this->head = new_node;
        this->node_count++;
        return true;
    }

    // remove the node at the front of the list and return its value
    size_t pop_front() {
        // check if the head node is empty
        if (this->is_empty()) {
            return std::numeric_limits<int>::min();
        }

        // swap the pointers and deallocate the head nodes memory
        Node* old_head = this->head;
        size_t old_head_value = old_head->value;

        // check if this is only 1 element left
        if (this->node_count == 1) {
            this->head = nullptr;
            this->node_count--;
            return old_head_value;
        }

        delete old_head;
        this->head = this->head->next;
        this->node_count--;
        return old_head_value;
    }

    // add a new node to the end of the list
    bool append(size_t new_node_value) {
        // allocate memory in the heap for the node
        Node* new_node = new Node { new_node_value };

        // check if the head node is empty
        if (this->is_empty()) {
            this->head = new_node;
            this->node_count++;
            return true;
        }

        // iterate to the end of the list
        Node* current_node = this->head;
        while (current_node->next) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
        this->node_count++;
        return true;
    }

    // remove the node at the end of the list
    size_t pop_back() {
        // check if the head node is empty
        if (this->is_empty()) {
            return std::numeric_limits<int>::min();
        } else if (this->node_count == 1) {
            Node* old_head = this->head;
            size_t old_head_value = old_head->value;
            delete old_head;
            this->head = nullptr;
            this->node_count--;
            return old_head_value;
        } 

        // iterate to the end of the list and swap the pointers
        size_t old_tail_value;
        Node* current_node = this->head;
        while (current_node) {
            // check if the next node is tail
            if (!current_node->next->next) {
                Node* old_tail = current_node->next;
                old_tail_value = old_tail->value;
                current_node->next = nullptr;
                delete old_tail;
                this->node_count--;
                break;
            }
            current_node = current_node->next;
        }
        return old_tail_value;
    }

    // clear out all the nodes and deallocate their memory respectively
    bool clear() {
        if (this->is_empty()) {
            return true;
        }

        Node* current_node = this->head;
        while (current_node) {
            this->pop_front();
            current_node = this->head;
        }
        return true;
    }

    // print out the values of the nodes to the console
    void print_nodes() {
        if (this->is_empty()) {
            std::cout << "" << std::endl;
            return;
        }

        Node* current_node = this->head;
        while (current_node) {
            std::cout << current_node->value << std::endl;
            current_node = current_node->next;
        }
        return;
    }
};

int main() {
    // create an instance of the sll
    SinglyLinkedList sll = {};

    sll.append(1);
    sll.pop_front();
    sll.prepend(0);
    sll.pop_back();

    sll.append(1);
    sll.append(2);
    sll.append(3);
    sll.print_nodes();
    sll.clear();
    sll.print_nodes();


    return 0;
}