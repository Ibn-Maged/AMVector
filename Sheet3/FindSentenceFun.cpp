#include "FindSentence.h"



string FindSentence::to_lower(string str){
    string s1="";
    for(int i=0 ; i<str.length(); i++){
       s1 = s1  + char(tolower(str[i]));
    }
    return s1;
}

void FindSentence::isInDictionary () {
    ifstream dictionary("dictionary.txt");
    string nextWord;
    dictionary.seekg(0, ios::beg);
    while (!dictionary.eof()) {
        dictionary >> nextWord;  
        Dic.insert(nextWord);
        

    }
}



bool FindSentence::inset(string n){
    return Dic.count(n);
}




bool FindSentence::Divide (string Sntnce, string rest){
    if (rest == "") {
        
        return true;
    }
    else {
        for (int i = 0; i < rest.length(); i++) {
            string SntnceNew = Sntnce + rest [i];
            string restNew  = rest.substr (0,i) + rest.substr (i+1);
            if(inset(to_lower(SntnceNew))){
                line.push_back(SntnceNew);
                return Divide("" , restNew);
            }
            else if (i== rest.length()-1){
                if(line.size()==0){
                    return true;
                }
                else{
                restNew = SntnceNew;
                SntnceNew = line[line.size()-1] ;
                line.pop_back();
                return Divide(SntnceNew , restNew);
                }

            }
            else{
               return Divide(SntnceNew , restNew);
            }
        }
    }

    return false;
    
}

bool FindSentence::unity( vector<string> V){
    if(V.size()==0){
        x++;
        string w="";
        for(int i=0 ; i<lineNew.size(); i++){
            if(stop==0)
            s<<lineNew[i]<<" ";
            w= w+lineNew[i]+" ";
    }
    if(stop==0)
    s<<"0"<<" ";
        Sentence.insert(w);
        lineNew.clear();
        if(G!=0)
        return true;
    }
    for(int j=x ; j<line.size()-1; j++){
        if(V.size()==0){
            V=line;
            for(int k=0; k<x; k++){
            lineNew.push_back(V[0]);
            V.erase(V.begin());
        }
        }
        
        
         if(j==line.size()-1)
            G=j;
        
        for(int i=0 ; i<V.size()-1; i++){
            string wordNew = V[i]+V[i+1];
            if(inset(to_lower(wordNew))){
                lineNew.push_back(wordNew);
                V.erase(V.begin()+i);
                V.erase(V.begin()+i);
                if(i==V.size()-1){
                lineNew.push_back(V[0]);
                V.erase(V.begin());
                }
                return unity(V);
            }
            else{
                lineNew.push_back(V[i]);
                V.erase(V.begin()+i);
                if(i==V.size()-1){
                lineNew.push_back(V[0]);
                V.erase(V.begin());
                }

                return unity(V);


            }
        }
       

    }
    
    x=0;
    return false;
}

void FindSentence::Run(string word){
    vector <string> finish;
    string temp ,temp2="";
    isInDictionary();
    //Divide ("", "IFIWOULDYOUIWILLGETTHEFULLMARK");
    //Divide ("", "weareabcdefgwe");
    Divide ("", word);

    for(int i=0 ; i<line.size(); i++){
        temp2 = temp2+ line[i]+" ";
    }
    Sentence.insert(temp2);
    if(line.size()!=0){
    unity(line); 
    stop=1;
    while(s>>temp){
        if(temp=="0"){
            unity(finish);
            finish.clear();
        }
        else{
        finish.push_back(temp);
        }
    }
    int count=1;
    for( auto& element: Sentence){

        cout<<"the "<<count<<" valid solution : ";
        cout<<element<<endl;
        count++;
    }
    }
    else{
        cout<<"There is no valid solution"<<endl;
    }
    

}
