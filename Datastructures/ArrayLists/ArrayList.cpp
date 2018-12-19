#include <iostream>
using namespace std;

class ArrayList{
    public:
        ArrayList(){ // See line 13, function overload to allow the user to specify an inital size of the ArrayList.
            listElements = 0; // Counter to store the number of elements in the ArrayList.
            listSize = 10; //Default size of the ArrayList;
            list = (int*) malloc(listSize*sizeof(int)); //Setting our (int) pointer List to the ArrayList equal to the newly allocated memory.
            // TODO: Add error handling is malloc fails.
        }
        ArrayList(int size){ 
            listElements = 0;
            listSize = size;
            list = (int*) malloc(listSize*sizeof(int));
        }

        ~ArrayList(){
            free(list); // Descontructor: on program end free the memory associated with the ArrayList to prevent memeory leaks.
        }

        bool push(int num){ // Mimics the native array function of JS, automatically allocating memeory.
            if(listSize == listElements){ // If the size of elements added is equal to the size. Would normaly 
                int* tempList = allocateMemory(); // 
                if(!tempList) return false;
                // READ: Apparently, I dont need to set the list pointer to the temp?
            }
            list[listElements] = num; //Putting the new element at the next available spot.
            listElements++; //Incrementing the # of elements in the list.
            return true;
        }

        void printList(){
            cout << "-----Current ArrayList-----" << endl;
            for(int i = 0; i<listElements; i++){
                cout << "ArrayList[" << i << "] = " << list[i] << endl;
            }
        }

    private:
        int listSize;
        int listElements;
        int* list;
        int* allocateMemory(){
            listSize *= 2;
            return (int*) realloc(list, listSize*sizeof(int));
            // TODO: Add error handling is realloc fails.
        }

};
int main(int argc, char* argv[]) {
    ArrayList arrayList(2);
    arrayList.push(1);
    arrayList.push(2);
    arrayList.push(3);
    arrayList.push(4);
    arrayList.push(5);
    arrayList.push(6);
    arrayList.printList();
    return 0;
}