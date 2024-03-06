#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    
    vector <int> v;
    v.push_back(1);//O(1)

    //the pc sets an initial capacity
    //if the capacity is exhausted
        //create a new vector with double of the previous capacity

    //intial capacity = 10 
    // at the 11 insertion:
        //create a new vector with capacity 20 and copy the previous values 
        //if the copy is linear =, why is the insertion O(1)?

    // initial capacity = 1 
    //n = 33 -> i want to do 33 insertions
    //O(n) to insert 33 times
    int n =33;
    for (int i =0;int i < n; i++){
        v.push_back(i);
    }

    // complexity of the copies: O(n)
    //compexity of the insertions at the end : O(n)
    // final complexity = O(2n) = O(n), each one O(1)

    //insert the second: vector of size 2*1=2,copy 1 element
    // insert the third: vector of size 2*2 = 4, copy 2 elements
    // insert the 5: vector of size 4*2 = 8, copy 4 elements
    //insert the 9: vector of size 8*2 = 16, copy 8 elements
    //insert the 17: vector of size 16*2=32, copy 16 elements
    //insert the 33: vector of size 32*2=64, copy the 32 elements 

    //1+2+4+8+16+32
    //32+16+8+4+2+1
    //(n-1)+ (n-1)/2 + (n-1)/4 + (n-1)/8 + (n-1)/16 + (n-1)/32
    //n+ n/2 + n/4 + n/8 + n/16 + n/32 = 2n -> O(n) -> linear

return 0;
}