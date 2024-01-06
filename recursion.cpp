#include<iostream>
using namespace std;

void regressiva(int i){
    if(i>=1){
        cout<<i<<endl;
        regressiva(i-1);
    }
}
int main (){

regressiva(10);

return 0;
}