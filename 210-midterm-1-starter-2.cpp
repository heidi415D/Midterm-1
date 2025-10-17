// Heidi Pico | Midterm 1

#include <iostream>
using namespace std;

// these are constants that might be used somewhere else in the program
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;
// DoublyLinkedList class that holds ndoes linked both prev and next
class DoublyLinkedList {
private: 
    // A node is like a box in our linked list structure
    // each node holds an int and two pointers, prev and next
    struct Node {
        int data; // this is the actual number stored in this node
        Node* prev; // pointer to the previous node in the list
        Node* next; // pointer to the next node in the list
        // this is the node constructor, initialize data and pointer vslues
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; // store the provided value in this node
            prev = p; // set the previous pointer - the default is null here and below
            next = n; // set the next pointer
        }
    };

    Node* head; // pointer to the first node
    Node* tail; // pointer to the last node

public: 
    DoublyLinkedList() { head = nullptr; tail = nullptr; } // create and empty listwith both head & tail = nullptr

    void insert_after(int value, int position) { // function to insert a new node after a given position in the list
        if (position < 0) { // check if the position is valid aka non-negative
            cout << "Position must be >= 0." << endl; // print error message
            return; // exit the function early
        }

        Node* newNode = new Node(value); // dynamically allocate a new node w given value
       // if list empty, this becomes only node
        if (!head) { 
            head = tail = newNode; // 
            return;
        }
        //otherwise find the node at the wanted position
        Node* temp = head; 
        for (int i = 0; i < position && temp; ++i)  // move temp pointer forward until position reached
            temp = temp->next;
        // this is for if we went past the end aka position does not exist 
        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode; // this is to avoid memory leak
            return;
        }
        //link newnode correctley bewteen nodes
        newNode->next = temp->next; // connect new nodes next to temps next
        newNode->prev = temp; // connect new nodes prev to temp
        if (temp->next) // if temp is not the tail, fix the next nodes prev
            temp->next->prev = newNode; 
            else // if we inserted at the new, newnode bceomes new tail
                tail = newNode; 
        temp->next = newNode; // link temps next to newnode
    }
    // delete node 
    void delete_val(int value) {
        if (!head) return; // 

        Node* temp = head;
        
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; 

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next; 

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; 

        delete temp;
    }

    void delete_pos(int pos) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
    
        if (pos == 1) {
            pop_front();
            return;
        }
    
        Node* temp = head;
    
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
    
        if (!temp->next) {
            pop_back();
            return;
        }
    
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(int v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    
    return 0;
}