#include<iostream>
#include<string>

using namespace std;

class Node{
private:
    string key;
    int value;
    Node* next;

public:
    Node(string key,int value){
        this->key=key;
        this->value=value;
        next=nullptr;
}
};

class HashTable{
private:
    static const int SIZE=7;
    Node* dataMap[SIZE];

};