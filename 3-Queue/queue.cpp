/*A Queue is a linear collection of elements that are maintained in sequence and can be modified by the
addition of elements at one end of the sequence(enqueue operation), the removal of elements from the other
end(dequeue);
FIFO= first in,first out;

IMPLEMENTATION:
For addition and deletion operations:
Arrays offer O(1) time complexity for adding elements at the end if there is available space, but O(n) if resizing is needed.
Deletion from the beginning is O(n) due to shifting.
Linked lists provide O(1) time complexity for adding or removing elements at both ends.
Overall, if efficient addition and deletion are crucial, especially at the beginning or end of the structure, linked lists generally outperform arrays.
 However, arrays may still be preferable for random access or memory locality needs.
*/
#include<iostream>
#include<climits>


using namespace std;

class Node{
public:
    int value;
    Node* next;

    Node(int value){
        this->value=value;
        next=nullptr;
    }
};

class Queue{
    private:
        Node* First;
        Node* Last;
        int lenght;
    public:

        Queue(int value);

        void PrintQueue();

        void getFirst();
        void getLast();
        void getLenght();

        void enqueue(int value);
        int dequeued();
    };

Queue::Queue(int value){
    Node* newNode= new Node(value);
    First=newNode;
    Last=newNode;
    lenght=1;
}

void Queue:: PrintQueue(){
    Node* temp= First;
    while(temp!=nullptr){
        cout<<temp->value<<endl;
        temp=temp->next;
    }
}

void Queue::getFirst(){
    cout<<"First: "<<First->value<<endl;
}
void Queue::getLast(){
    cout<<"Last: "<<Last->value<<endl;
}
void Queue:: getLenght(){
    cout<<"Lenght: "<<lenght<<endl;
}

void Queue:: enqueue(int value){
    Node* newNode= new Node(value);
    if(lenght==0){
        First=newNode;
        Last=newNode;
    }else{
        Last->next=newNode;
        Last=newNode;
    }
    lenght++;
}

int Queue::dequeued(){
    if(lenght==0) return INT_MIN;

    Node* temp=First;
    int dequeuedValue=First->value;
    if(lenght==1){
        First=nullptr;
        Last=nullptr;
    }else{
        First=First->next;
        delete temp;
    }
    lenght--;
    return dequeuedValue;
}

int main(){

    Queue* myQueue=new Queue(7);
    myQueue->enqueue(6);
    myQueue->enqueue(1);

    myQueue->getFirst();
    myQueue->getLast();
    myQueue->getLenght();
    myQueue->PrintQueue();

    myQueue->dequeued();

    myQueue->getFirst();
    myQueue->getLast();
    myQueue->getLenght();

    myQueue->PrintQueue();




    return 0;
}


