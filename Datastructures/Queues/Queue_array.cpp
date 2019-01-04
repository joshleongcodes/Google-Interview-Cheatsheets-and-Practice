#include <iostream>
using namespace std;

const int MAX_QUEUE_SIZE = 5;

struct QueueItem {
    int data; 
};

class QueueArray {
    public:
        QueueArray(){
            initalize();
            cout << "A queue with size {" << MAX_QUEUE_SIZE << "}, has been created." << endl;
        }
        ~QueueArray(){
            while(!isEmpty()) dequeue();
        }
        void initalize(){
            queueFront = 0;
            queueEnd = 0;
            for(int i = 0; i < MAX_QUEUE_SIZE; i++){
                queue[i] = NULL;
            }
        }
        void enqueue(int data){
            if(isEmpty()) {
                QueueItem* newQueueItem = new QueueItem;
                newQueueItem->data = data;
                queue[queueFront] = newQueueItem;
                cout << "Queued: " << data << endl;
            } else if(isFull()) {
                cout << "The queue is full, you cannot enqueue anything else untill you dequeue." << endl;
            } else {
                QueueItem* newQueueItem = new QueueItem;
                newQueueItem->data = data;
                queueEnd = (queueEnd + 1) % MAX_QUEUE_SIZE;
                queue[queueEnd] = newQueueItem;
                cout << "Queued: " << data << endl;
            }
        }
        void dequeue(){
            if(isEmpty()) {
                cout << "The queue is empty, nothing to dequeue." << endl;
            } else {
                cout << "Dequeued: " << queue[queueFront]->data << endl;
                delete queue[queueFront];
                queue[queueFront] = NULL;
                queueFront = (queueFront+1) % MAX_QUEUE_SIZE;
                if(!queue[queueFront]) queueEnd = queueFront;
            }
        } 
        bool isEmpty() {
            return(
                queueFront == queueEnd && 
                !queue[queueFront]
            );
        }
        bool isFull() {
            return((queueEnd+1)%MAX_QUEUE_SIZE == queueFront);
        } 
        int peek(){
            if(isEmpty()){
                cout << "Queue empty, cannot peek." << endl;
                return 0;
            }
	        else return queue[queueFront]->data;
        }
        void printQueue(){
            if(isEmpty()){
                cout << "Queue is empty, nothing to print." << endl;
            } else {
                for(
                    int i = queueFront, counter = 0; 
                    queue[i] && counter < MAX_QUEUE_SIZE; 
                    i=(i+1) % MAX_QUEUE_SIZE, counter++
                ){
                    cout << queue[i]->data;
                    if(i!=queueEnd) cout << "<-";
                }
                cout << endl;
            }
            
        }
    private:
        QueueItem* queue[MAX_QUEUE_SIZE];
        int queueFront;
        int queueEnd;

};

int main(int argc, char* argv[]) {
    QueueArray queueArray;
    queueArray.enqueue(1);
    queueArray.enqueue(2);
    queueArray.enqueue(3);
    queueArray.enqueue(4);
    queueArray.enqueue(5);
    queueArray.printQueue();
    return 0;
}