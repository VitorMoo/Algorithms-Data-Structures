//implementing a stack from scratch using linked Lists
#include<iostream>
#include <climits>
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

class Stack{
private:
    Node* top;
    int height;

public:

    Stack(int value);

    void printStack();
    void getTop();
    void getHeight();
    
    void push(int value);
    int pop();

};
Stack::Stack(int value){
    Node* newNode=new Node(value);
    top=newNode;
    height=1;
}

void Stack::printStack(){
    Node* temp=top;
    while(temp!=nullptr){
        cout<<temp->value<<endl;
        temp=temp->next;
    }
}
void Stack::getTop(){
    if(top!=nullptr)
    cout<<"top:"<<top->value<<endl;
    else
        cout << "Stack is empty" << endl;
}
void Stack::getHeight(){
    cout<<"height: "<<height<<endl;
}
void Stack::push(int value){
    Node* newNode= new Node(value);
    newNode->next=top;
    top=newNode;
    height++;
}
int Stack::pop(){
    if(height==0) return INT_MIN;

    Node* temp=top;
    int poppedValue=top->value;
    top=top->next;
    delete temp;
    height--;

    return poppedValue;
}
int main(){
    
Stack* myStack=new Stack(0);

myStack->push(1);

myStack->printStack();
cout<<"after pop(): "<<endl;
myStack->pop();

myStack->printStack();
    

    return 0;
}