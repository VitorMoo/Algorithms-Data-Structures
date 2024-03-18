#include<iostream>
using namespace std;

/*LINKED LISTS
its a sequence of elements(nodes), HEAD is a pointer that points to the first node of the list.
each node has two components, the data and a pointer -> to the next node of the list.
|HEAD->| |1->| |2->| |3->| |4->| |->5| TAIL.

pros
inserts and delets at constant time O(1)
cons
random acess - linear time O(N)
*/
class Node{
private:

public:
    int value;
    Node* next;

    Node(int value){
        this->value=value;          //creating a node class
        next=nullptr;
    }
    //default destructor

};
class linkedLists
{

    
private:
    Node* head;
    Node* tail;                 //private data members
    int length;
    
public:
    linkedLists(int value);
    ~linkedLists();             //constructor and destructos


    void printList();
    void getHead();             //declaring functions
    void getTail();
    void getLength();

    void append(int value);
    void deleteLast();
    void preprend(int value);
    void deleteFirt();
    Node* getIndex(int index);
    bool set(int index, int value);
    bool insert(int index, int value);
    void deleteNode(int index);
};

linkedLists::linkedLists(int value)
{
    Node* newNode= new Node(value);//This means that newNode now points to the newly created Node object.
    head=newNode;                  //points to the same node that new node is pointing to
    tail=newNode;
    length=1;   
}
linkedLists::~linkedLists(){
    Node* temp=head;
    while(head!=nullptr){
        head=head->next;       
        delete temp;
        temp=head;

    }
}

void linkedLists:: printList(){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->value<<endl;    
        temp=temp->next;
    }
}

void linkedLists:: getHead(){
    cout<<"Head: "<<head->value<<endl;
}
void linkedLists::getTail(){
    cout<<"Tail: "<<tail->value<<endl;
}
void linkedLists::getLength(){
    cout<<"length: "<<length<<endl;
}

void linkedLists::append(int value){
    Node* newNode= new Node(value);
    if(head==nullptr){
    head=newNode;
    tail=newNode;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
    length++;
}

void linkedLists::deleteLast(){
    if(length==0) return;
    Node* pre=head;
    Node* temp=head;
    while(temp->next!=nullptr){
        pre=temp;
        temp=temp->next;
    }
    tail=pre;
    tail->next=nullptr;
    length--;
    if(length==0){
        head=nullptr;
        tail=nullptr;
    }
    delete temp;
}
void linkedLists::preprend(int value){
Node* newNode=new Node(value);
    if (length==0){
        head=newNode;
        tail=newNode;
    }else{
        newNode->next=head;
        head=newNode;
    }  
    length++;
}
void linkedLists::deleteFirt(){
    if(length==0) return;
    Node* temp=head;
    if(length==1){
        head=nullptr;
        tail=nullptr;
    }
    else{
        head=head->next;
    }
    delete temp;
    length--;
}
Node* linkedLists::getIndex(int index){
    if(index<0||index>=length){
        return nullptr;
    }
    Node* temp=head;
    for(int i = 0;i<index;i++){
        temp=temp->next;
    }
    return temp; 
}
bool linkedLists::set(int index, int value){
    Node* temp=getIndex(index);
    if(temp!=nullptr){
        temp->value=value;
        return true;
    }
    return false;
}
bool linkedLists::insert(int index,int value){
    if(index<0||index>length) return false;
    if(index==0){
        preprend(value);
        return true;
    }if(index==length){
        append(value);
        return true;
    }
    Node* newNode= new Node(value);
    Node* temp=getIndex(index-1);
    newNode->next=temp->next;
    temp->next=newNode;
    length++;
    return true;
}
void linkedLists::deleteNode(int index){
    if(index<0||index>=length) return;
    if(index==0){
        deleteFirst(index);
    }
    if (index==length-1) return deleteLast;
    Node* prev=getIndex(index-1);
    Node* temp= prev->next;

    prev->next=temp->next;
    delete temp;
    length--;
}

int main(){

linkedLists* myLinkedList = new linkedLists(0);


myLinkedList->append(2);
myLinkedList->printList();

myLinkedList->insert(1,1);
myLinkedList->printList();

delete myLinkedList;
    return 0;
}