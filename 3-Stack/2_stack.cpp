#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> pilha;
    char continuar;

    do {
        int element;
        cout << "What element do you want to insert?" << endl;
        cin >> element;

        pilha.push(element);

        cout << "Do you want to continue? (y/n)" << endl;
        cin >> continuar;

        cout << "size of stack:"<< pilha.size() <<"\n";
        cout << "first element:"<< pilha.top()<< "\n";

    } while (continuar == 'y' || continuar == 'Y');

    return 0;
}
