#include<iostream>
#include<stdexcept>
#include<string>

using namespace std;

const int MAX = 10;

class Car {
private:
    int topo;
    string pilha[MAX];
    string carsName;
    string carsBrand;
    string carsColor;
    
public:
    //public data members:
    Car();                                                      //Copy constructor
    Car(string carsName, string carsBrand, string carsColor);   //Parameter constructor
    ~Car();                                                     //Destructor    

    //accesors and functions:
    string getName() const;       
    string getBrand() const;      
    string getColor() const;      

    void Push(const string& element);       
    string pop();                           
    void displayInfo();  
    bool empty();
    bool full();

};

Car::Car() {
}                                                                           //Copy constructor

Car::Car(string carsName, string carsBrand, string carsColor)
    : carsName(carsName), carsBrand(carsBrand), carsColor(carsColor) {      //Parameter constructor
        topo=-1;
}

Car::~Car() {
}

string Car::getName() const {
    return carsName;
}

string Car::getBrand() const {
    return carsBrand;
}

string Car::getColor() const {
    return carsColor;
}
bool Car::empty(){
    return topo==-1;
}

bool Car::full(){
    return topo==MAX-1;
}

void Car::Push(const string& element){
      if (!full()) { 
            topo++; 
            pilha[topo] = element; 
        } else {
            throw overflow_error("full stack"); 
        }
    }

string Car::pop(){
    if (!empty()) { 
            string element = pilha[topo]; 
            topo--; 
            return element; 
        } else {
            throw underflow_error("Empty Stack!"); 
        }
}

void Car::displayInfo() {
    cout << "\nCar Information:" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Brand: " << getBrand() << endl;
    cout << "Color: " << getColor() << endl;
    cout << "Car Types in the Stack:" << endl;
    for (int i = 0; i <= topo; ++i) {
        cout << pilha[i] << endl;
    }
}

int main(){

    return 0;
}
