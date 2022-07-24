#include <iostream>
#include <limits>

// genericize the value data member later on
// add exceptions -> to see how it works
struct Node {
    size_t value;
    Node* previous;
    Node* next;

    // constructor
    Node(size_t new_node_value) : value { new_node_value }, previous { nullptr }, next { nullptr } {}

    // destructor
    ~Node() {}
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;
    size_t node_count;

    // constructor
    DoublyLinkedList() : head { nullptr }, tail { nullptr }, node_count { 0 } {}

    // destructor
    ~DoublyLinkedList() {}

    // determine if the doubly linked list is empty
    bool is_empty() {
        if (this->node_count == 0 && !this->head && !this->tail) {
            return true;
        }
        return false;
    }

    // get the value at the head
    size_t get_head() {
        if (this->is_empty()) {
            return std::numeric_limits<int>::min();
        }
        return this->head->value;
    }

    // get the value at the tail
    size_t get_tail() {
        if (this->is_empty()) {
            return std::numeric_limits<int>::min();
        }
        return this->tail->value;
    }

    // get the number of nodes in the doubly linked list
    size_t get_node_count() {
        return this->node_count;
    }

    // add a new node to the front of the list
    bool prepend(size_t new_node_value) {
        Node* new_node = new Node { new_node_value };
        if (this->is_empty()) {
            this->head = new_node;
            this->tail = new_node;
            this->node_count++;
            return true;
        }

        if (this->head == this->tail) { 
            new_node->next = this->head;
            this->head->previous = new_node;
            this->head = new_node;
            this->tail = this->head->next;
            this->node_count++;
            return true;
        }

        new_node->next = this->head;
        this->head->previous = new_node;
        this->head = new_node;
        this->node_count++;
        return true;
    }

    // remove the node at the head and return its value
    size_t pop_front() {
        if (this->is_empty()) {
            return std::numeric_limits<int>::max();
        }

        Node* popped_front_node = this->head;
        size_t popped_front_node_value = popped_front_node->value;

        // for one node
        if (this->head == this->tail) {
            this->head = nullptr;
            this->tail = nullptr;
            delete popped_front_node;
            this->node_count--;
            return popped_front_node_value;
        }

        // for two nodes
        if (this->node_count == 2) {
            // set the head to the node that is next to it
            this->head = this->head->next;

            // set the previous pointer to null
            this->head->previous = nullptr;

            // decrement node count
            this->node_count--;

            // set the tail to the head
            this->tail = this->head;
            
            // deallocate the memory
            delete popped_front_node;

            // return the value of the popped node
            return popped_front_node_value;
        }

        // for more than two nodes
        this->head = this->head->next;
        this->head->previous = nullptr;
        this->node_count--;
        delete popped_front_node;
        return popped_front_node_value;
    }

    // add a new node to the end of the doubly linked list
    bool append(size_t new_node_value) {
        // allocate memory in the heap
        Node* new_node = new Node { new_node_value };

        // if there is zero nodes
        if (this->is_empty()) {
            this->head = new_node;
            this->tail = new_node;
            this->node_count++;
            return true;
        }

        // if there is one node -> set the head and tail pointers
        if (this->tail == this->head) {
            // set the previous pointer for the new node
            new_node->previous = this->head;

            // set the head's next pointer to the new node
            this->head->next = new_node;

            // set the tail to the new node
            this->tail = new_node;

            this->tail->previous = this->head;

            // increment the node count
            this->node_count++;

            return true;
        }

        // general -> if there is more than 1
        this->tail->next = new_node;
        new_node->previous = this->tail;
        this->tail = new_node;
        this->node_count++;
        return true;
    }

    // remove the last node in the doubly linked list
    size_t pop_back() {
        // if there is zero nodes
        if (this->is_empty()) {
            return std::numeric_limits<int>::max();
        }

        Node* popped_back_node = this->tail;
        size_t popped_back_node_value = popped_back_node->value;

        // for only one node
        if (this->tail == this->head) {
            this->tail = nullptr;
            this->head = nullptr;
            delete popped_back_node;
            this->node_count--;
            return popped_back_node_value;
        }

        // for two nodes
        if (this->node_count == 2) {
            // set the tail to the head
            this->tail = this->head;

            // set the next pointer of the tail to null
            this->tail->next = nullptr;

            // decrement node count
            this->node_count--;

            // deallocate the memory
            delete popped_back_node;

            // return the value of the popped node
            return popped_back_node_value;
        }


        // general
        // set the tail to the node before it
        this->tail = this->tail->previous;

        // set the new tail's next pointer to null
        this->tail->next = nullptr;

        // decrement the node count
        this->node_count--;

        // deallocate the memory
        delete popped_back_node;

        // return the value of popped node
        return popped_back_node_value;
    }

    // print out the nodes in the doubly linked list
    bool print_nodes() {
        if (this->is_empty()) {
            std::cout << "empty" << std::endl;
            return true;
        }

        Node* current_node = this->head;
        while (current_node) {
            std::cout << current_node->value << std::endl;
            current_node = current_node->next;
        }
        return true;
    }

    // print out the nodes backwards in the doubly linked list
    bool print_nodes_backwards() {
        if (this->is_empty()) {
            std::cout << "empty" << std::endl;
            return true;
        }

        Node* current_node = this->tail;
        while (current_node) {
            std::cout << current_node->value << std::endl;
            current_node = current_node->previous;
        }
        return true;
    }

    // remove all the nodes in the doubly linked list
    bool clear() {
        if (this->is_empty()) {
            return true;
        }

        while (this->node_count > 0) {
            this->pop_back();
        }
        return true;
    }
};

int main() {
    // create an instance of the doubly linked list
    DoublyLinkedList dll = {};

    // add some nodes
    dll.prepend(3);
    dll.prepend(2);
    dll.prepend(1);

    // see what the head and tail nodes are
    dll.print_nodes();
    std::cout << "h -> " << dll.get_head() << std::endl;
    std::cout << "t -> " << dll.get_tail() << std::endl;

    // remove all the nodes
    dll.pop_front();
    dll.print_nodes();
    std::cout << "h -> " << dll.get_head() << std::endl;
    std::cout << "t -> " << dll.get_tail() << std::endl;

    dll.pop_front();
    dll.print_nodes();
    std::cout << "h -> " << dll.get_head() << std::endl;
    std::cout << "t -> " << dll.get_tail() << std::endl;

    dll.pop_front();
    dll.print_nodes();
    std::cout << "h -> " << dll.get_head() << std::endl;
    std::cout << "t -> " << dll.get_tail() << std::endl;

    std::cout << "testing out append()" << std::endl;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.append(4);
    dll.append(5);

    dll.print_nodes();
    std::cout << "h -> " << dll.get_head() << std::endl;
    std::cout << "t -> " << dll.get_tail() << std::endl;

    dll.print_nodes_backwards();
    std::cout << "removing the last node" << std::endl;

    dll.pop_back();
    dll.print_nodes();
    std::cout << "h -> " << dll.get_head() << std::endl;
    std::cout << "t -> " << dll.get_tail() << std::endl;

    dll.pop_back();
    dll.print_nodes();
    std::cout << "h -> " << dll.get_head() << std::endl;
    std::cout << "t -> " << dll.get_tail() << std::endl;

    dll.pop_back();
    dll.print_nodes();
    std::cout << "h -> " << dll.get_head() << std::endl;
    std::cout << "t -> " << dll.get_tail() << std::endl;

    dll.pop_back();
    dll.print_nodes();
    std::cout << "h -> " << dll.get_head() << std::endl;
    std::cout << "t -> " << dll.get_tail() << std::endl;

    dll.pop_back();
    dll.print_nodes();
    std::cout << "h -> " << dll.get_head() << std::endl;
    std::cout << "t -> " << dll.get_tail() << std::endl;

    // add nodes 
    std::cout << "adding nodes again" << std::endl;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.append(4);
    dll.append(5);
    dll.print_nodes();

    // test out clear()
    std::cout << "clearing out nodes" << std::endl;
    dll.clear();

    dll.print_nodes();

    return 0;
}
