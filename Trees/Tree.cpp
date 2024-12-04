#include<iostream>

using namespace std;

class Node{
    public:
    int value;
    Node* left;
    Node* right;

    Node(int value){
        this->value = value;
        left = nullptr;
        right =nullptr;
    }
}

class BinaryTree{
    public: Node* root;

    BinaryTree(){root=nullptr;}
    

}

int main(){

    return 0;
}