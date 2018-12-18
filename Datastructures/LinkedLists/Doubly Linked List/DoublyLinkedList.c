#include <stdio.h>

struct Node { // Each node in our DLL is going to be a struct object of 'Node' type;
    int data; //Data to be held by each node/
    Node* next; //Node pointer to the next node in the linkedlist.
    Node* prev; //Node pointer to the previous node in the linkedlist.
    Node(int data, Node* prev, Node* next) { //Constructor
		this->data = data;
		this->prev = prev;
		this->next = next;
	}
};

class DLL { //Linkedlist class
    public:
        DLL() { 
             // init' head and tail as null since there are no nodes in the linkedlist to start with.
            head = NULL;
            tail = NULL;
        }
        void addNodeAtTail(int data) {
            if(tail) {
                Node* newNode = new Node(data, tail, NULL);
                tail->next = newNode;
                tail = newNode;
            } else {
                Node* newNode = new Node(data, NULL, NULL);
                head = newNode;
                tail = newNode;
            }
            printf("Node with data %i has been added to the tail.\n", data);
        }
        void addNodeAtHead(int data) {
            if(head){
                Node* newNode = new Node(data, NULL, head);
                head->prev = newNode;
                head = newNode;
            } else {
                Node* newNode = new Node(data, NULL, NULL);
                head = newNode;
                tail = newNode;
            }
            printf("Node with data %i has been added to the head.\n", data);
        }
        void deleteNode(int data){
            if(head) {
                Node* c = head;
                while(c && c->data != data) c=c->next;
                if(c->data == data) {
                    if(c==head){
                        if(c->next){
                            head = c->next;
                            c->next->prev = NULL;
                        }
                        else head = NULL;
                    } else if(c==tail) {
                        c->next = NULL;
                        c->prev->next = NULL;
                        tail = c->prev;
                    } else {
                        c->prev->next = c->next;
                        c->next->prev = c->prev;
                    }
                    delete c;
                    printf("The node with data %i, was deleted.\n", data);
                } else {
                    printf("The node with data %i, was not found.\n", data);
                }
            } else {
                printf("There are no nodes in this list. \n");
            }
        }
        void printList(){
            if(head) { // IF there is a head pointer, meaning if the LL had been initialized with another item.
                for(Node* c = head; c; c=c->next){ //Node* c points to the head pointer, while there is a current node, go to the next;
                    printf("%i", c->data); 
                    if(c->next) printf("->");
                }
            } else { // If there isnt a head pointer, point the head to the new node.
                printf("There are no nodes in this list.");
            }
            printf("\n");
        }
    private:
    Node* head;
    Node* tail;
};

int main(int argc, char* argv[]){
    DLL dll;
    dll.addNodeAtHead(1);
    dll.addNodeAtTail(2);
    dll.addNodeAtTail(3);
    dll.printList();
    dll.deleteNode(3);
    dll.printList();

}