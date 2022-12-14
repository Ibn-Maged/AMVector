#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cctype>

using namespace std;


void tolower(string& word){
    for (int i=0 ; i<word.length() ; i++){
        word[i]=tolower(word[i]);
    }

}


int main(){
    ifstream file;
    string word , fileName;
    unordered_map<string , int> table;

    cout<<"enter the file name with .txt"<<endl;
    cin>>fileName;
    file.open(fileName);
    while(file>>word){
        for(int i=0 ; i<word.length() ; i++){
            if( (!isalnum(word[i]) or ispunct(word[i]) or isdigit(word[i])) and word[i]!=95 ){
                word.erase(word.begin()+i);
                i--;
            }

        }
        tolower(word);
        if(table.count(word)){
            int value = table[word];
            value++;
            table[word]=value;
        }
        else{
            table[word]=1;
        }
    }

    for(auto x : table){
        cout<<x.first<<" : "<<x.second<<endl;
    }
    
}