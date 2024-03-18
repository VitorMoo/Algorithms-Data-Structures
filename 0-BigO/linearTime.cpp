#include<iostream>

using namespace std;
/*

O(n): Linear Time
Directly proportional to the data set size.
Example: Looping through an array.

*/

void printItems(int n){
    for(int i =0;i<n;i++){
        cout<<i<<endl;
    }
}

int main(){

printItems(10);

    return 0;
}