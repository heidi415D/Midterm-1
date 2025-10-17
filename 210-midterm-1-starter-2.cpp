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
    // delete node w a specific value
    void delete_val(int value) {
        if (!head) return; // if list empty, nothing to delete

        Node* temp = head; //start from head and search
        
        while (temp && temp->data != value)
            temp = temp->next; //move forward

        if (!temp) return;  // if value not found, exit
        // relinnk the nodes to skip the deleted one
        if (temp->prev)
            temp->prev->next = temp->next; // connect next nodes next to temps next
        else
            head = temp->next; //if first node is deleted move head forward

        if (temp->next)
            temp->next->prev = temp->prev; //connect next nodes prev to temps prev
        else
            tail = temp->prev;  // if deleting last node move tail backwards

        delete temp; // free memory for removed node
    }
    // delete node by position number
    void delete_pos(int pos) {
        if (!head) { // check if list empty
            cout << "List is empty." << endl;
            return;
        }
    
        if (pos == 1) { // delete first node
            pop_front(); 
            return;
        }
    
        Node* temp = head;
        // move to the node at position
        for (int i = 1; i < pos; i++){
            if (!temp) { // if we run off the end of the lsit
                cout << "Position doesn't exist." << endl; // error message
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) { // this is a safeguard in case the pos is too big
            cout << "Position doesn't exist." << endl;
            return;
        }
     
        if (!temp->next) { // if its the last node
            pop_back();
            return;
        }
    
        Node* tempPrev = temp->prev; // connect previous and next nodes around the deleted one
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp; // remove the target node from memory
    }
    // add node to end of list
    void push_back(int v) {
        Node* newNode = new Node(v); // allocate new node
        if (!tail) // if list empty set both head and tail
            head = tail = newNode;
        else { // attach after tail
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode; // update tail pointer
        }
    }
    // add node to front of list
    void push_front(int v) {
        Node* newNode = new Node(v); /
        if (!head) 
            head = tail = newNode; // empty list - both head and tail pointer
        else { 
            newNode->next = head; // connect new node to current head
            head->prev = newNode; // link current head back to the new node
            head = newNode; // update head pointer
        }
    }
    // remove first node
    void pop_front() {

        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) { // if there is more than one node
            head = head->next; // move head forward
            head->prev = nullptr; // remove back link
        }
        else
            head = tail = nullptr; // if only one node list is empty
        delete temp; // free removed node
    }
    // remove last node
    void pop_back() {
        if (!tail) { 
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) { // if more than one node
            tail = tail->prev; // move tail backward
            tail->next = nullptr; // cut connection to old node (not sure about this one)
        }
        else
            head = tail = nullptr; // list becomes empty
        delete temp; // free memory
    }
    // this is the destructor - called automatically when object goes out of scope
    // deleters every node to abvoid memory leak
    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    } 
    //print all ndoes from head to tail
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
    // print all node in reverse from tail to head
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
// main for testing
int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    
    return 0;
}
 int main(
    cout << "not letting me commit unless i add something??"
 ) 