#include <iostream>
using namespace std;

class ArrayDoubling{
    public:
        ArrayDoubling(){
            listElements = 0;
            listSize = 10;
            list = new int[listSize];
        }
        ArrayDoubling(int size){
            listElements = 0;
            listSize = size;
            list = new int[listSize];
        }
        ~ArrayDoubling() {}
        void push(int num){
            if(listElements==listSize){
                listSize *= 2;
                int* tempList = new int[listSize];
                for(int i = 0; i < listSize/2; i++){
                    tempList[i] = list[i];
                }
                list = tempList;
                delete[] tempList;
            }
            list[listElements] = num;
            listElements++;
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
        int* list = NULL;
};

int main(int argc, char* argv[]){
    ArrayDoubling arrayDoubling(2);
    arrayDoubling.push(1);
    arrayDoubling.push(2);
    arrayDoubling.push(3);
    arrayDoubling.push(4);
    arrayDoubling.push(5);
    arrayDoubling.printList();
}