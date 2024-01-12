#include<iostream>
using namespace std;

/*void countdown(int i){
    if(i>=1){
        cout<<i<<endl;
        countdown(i-1);
    }
}

int main (){
    countdown(10);
    return 0;
}
*/

void diminui(int n){
    cout<<n<<endl;
    if(n==0){
        cout<<"fim"<<endl;
        return;
    }
    diminui(n-1);
}
int main(){

    diminui(10);
    
    return 0;
}