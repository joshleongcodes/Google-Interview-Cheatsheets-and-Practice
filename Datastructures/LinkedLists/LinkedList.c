#include <stdio.h>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    public:
        LinkedList(){ head = NULL; }
        ~LinkedList(){ }
        void addNode(int data){
            Node* newNode = new Node; // Allocating memory for a new Node item.
            newNode-> data = data, newNode->next = NULL; // Setting values for the new Node item.
            if(head) { // IF there is a head pointer, meaning if the LL had been initialized with another item.
                Node* c = head; // Pointing a current node pointer to the head.
                while(c->next) c=c->next; // Traversing the LL to find the end. * WHILE c->next because if you increment c to the next while there is c vs c->next it will give a SEG FAULT.
                c->next = newNode; // Once the loop ends, pointing the end node to newNode;
            } else { // If there isnt a head pointer, point the head to the new node.
                head = newNode; 
            }
            printf("Node with data, %i has been added. \n", data);
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
        void deleteNode(int data, bool deleteAll){
            if(deleteAll){
                printf("IMPLEMENT");
                // TODO: Implement
                // if(head) { //If there is a list.
                //     Node* temp = NULL; // Temp node to store the node before current.
                //     for(Node* c = head; c; c=c->next){ //Goal is to delete all nodes with the specified node 'data', so we are going to iterate over the entire list and delete all.
                //         if(c==head && ){ 
                //             if(c->data == data){
                                
                //             }  //If you are at the head, and the head's data is also equal to 'data'.
                //             if(c->next) head = c->next // If you are at the head, and there is more than one item. 
                //             else {  // If you are at the head, but that is the only item in the list.
                //                 temp = head;
                //                 head = NULL; 
                //             }
                //         } else {
                //              
                //         }
                //         delete tempNode;
                //         printf("Node(s) with value, %i, has been deleted. \n", data);
                //         temp=c;
                //     }
                // } else { //If there isnt a list.
                //     printf("There are no nodes in this list.");
                // }
            } else {
                if(head){
                    Node* c = head;
                    Node* temp = head;
                    while(c && c->data != data){
                        temp = c;
                        c=c->next;
                    };
                    if(c->data == data){
                        if(c==head){
                            if(head->next) head=head->next;
                            else head = NULL;
                        }
                        else if(c->next) temp->next = c->next;
                        else temp->next = NULL;
                        delete c;
                        printf("The node with data, %i, was deleted.\n", data);
                    } else {
                        printf("The node with data, %i, was not found.\n", data);
                    }
                } else {
                    printf("There are no nodes in this list.");
                }
            }
        }
        void deleteNodeAtIndex(int index){
            if(head) { 
                Node* c = head;
                Node* temp = head;
                int i = 0;
                while(c && i<index){
                    temp = c;
                    c=c->next;
                    i++;
                }
                if(i == index){
                    if(c == head){
                        if(c->next) head = head->next;
                        else head = NULL;
                    } else if (c->next == NULL) {
                        temp->next = NULL;
                    } else {
                        temp->next = c->next;
                    }
                    delete c;
                    printf("Node at index %i, has been deleted.\n", index);
                } else {
                    printf("Node at index %i, does not exist.\n", index);
                }
            } else {
                printf("There are no nodes in this list.\n");
            }
        }
    
    private:
        Node* head;
};

int main(int argvc, char* argv[]) {
    LinkedList LL;
    LL.addNode(1);
    LL.addNode(3);
    LL.addNode(6);
    LL.addNode(9);
    LL.printList();
    LL.deleteNodeAtIndex(3);
    LL.printList();

    return 0;
}