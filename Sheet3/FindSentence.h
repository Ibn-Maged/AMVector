#include <iostream>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <vector>
#include <set>
using namespace std;



class FindSentence{

    vector <string> line;
    vector <string> lineNew;
    set <string> Sentence;
    stringstream s;
    set<string> Dic;
    int G=0;
    int x=0;
    int stop=0;

    public:
        FindSentence(){};
        string to_lower(string str);
        void isInDictionary ();
        bool inset(string n);
        bool Divide (string Sntnce, string rest);
        bool unity( vector<string> V);
        void Run(string word);



};