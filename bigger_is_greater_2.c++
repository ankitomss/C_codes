#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int swapword_check(string word, char new_char, char old_char);

void print_lex(string word){
       
        for(int i=word.length()-1; i >=0 ; i--){            
            for(int j=i-1; j >=0 ; j--){
                   if(word[j]<word[i]) {
                       swap(word[j], word[i]);
                       sort(word.begin()+j+1, word.end());
                       cout << word <<"\n";
                       return;
                   }
                }
            
        }
    
        cout << "no answer\n";
}


    
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    vector<string> strings;
    cin >> N;
    string temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        strings.push_back(temp);
    }
    
    for(int i=0;i<N;i++){
        print_lex(strings[i]);
    }
        
    return 0;
}

