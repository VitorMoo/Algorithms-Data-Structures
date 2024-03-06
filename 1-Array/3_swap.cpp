#include<iostream>
#include<string>
#include<vector>

using namespace std;

    void reverseWord(string &word,int start,int end){
        for(int i =start,j=end;i<j;i++,j--){
            swap(word[i],word[j]);
        }
    }

    void reverseSentence(string &sentence){
    int start=0;

    reverseWord(sentence,0,sentence.size()-1);
    for (int i =start;i<sentence.size();i++){
        if(sentence[i] == ' '){
            reverseWord(sentence,start,i-1);
            start= i+1;
        }
    }
    reverseWord(sentence,start,sentence.size()-1);
    }

int main(){
string word1="vitor e alice";

reverseSentence(word1);
cout<<word1;
}