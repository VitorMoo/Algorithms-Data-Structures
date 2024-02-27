#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack <int> numbers;
    numbers.push(2);
    numbers.push(7); 
    numbers.push(23);
    numbers.push(3);

    cout << "size of stack:"<< numbers.size() <<"\n";
    cout << "first element:"<< numbers.top()<< "\n";

    numbers.pop();

    cout<< "new first element:"<< numbers.top()<<"\n";

    return 0;
}