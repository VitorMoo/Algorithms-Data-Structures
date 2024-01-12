#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
//static array
    int array[5]={1,2,3,4,5};
    cout<<array[1];//output:2
    array[3]=9;//array = {1,2,3,9,5},cant insert or remove.

// dynamic array

    int n =5;
    vector<int>v(n);//={0,0,0,0,0}
    v.push_back(8);// insertion at the end -> O(1)
    v[1]=7;//O(1)
    v.pop_back();// remotion at the end -> O(1)

//strings

    string word ="Vitor";
    cout<<word[1];//output:i

    string base ="eu odeio gatos";
    base.replace(3,5,"amo");
    //base= "eu amo gatos"
    //O(n) time and O(n) space where n is the new lenght

    string name="joao";

    name.replace(0,4,"Jeca");
    //O(n) time and O(1) space where n is the lenght of the "jeca"


    if(base.find("amo") != string::npos){
        cout << "A substring 'amo' foi encontrada em: " << base.find("amo") << endl;
    }
    else
    {
        cout << "A substring 'amo' não foi encontrada." << endl;
    }//find is O(n) time

    string verb = base.substr(3,3);
    //verb= "amo"

    string word_to_find="amo";

    int position=base.find("amo");
    verb=base.substr(position,word_to_find.size());












//Access at an index -> O(1)
//Search an element-> O(n)
//insertion at the end -> O(1) 
//insertion at another positions -> O(n)
//Remotion at the end -> O(1)
//Remotion at anothes positions -> O(n)
return 0;
}