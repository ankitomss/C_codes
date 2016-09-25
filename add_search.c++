#include<iostream>
#include<string>
#include<vector>
using namespace std;

class WordDictionary {
public:
    vector<string> dictionary;
    // Adds a word into the data structure.
    void addWord(string word) {
           dictionary.push_back(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
	    
            vector<string>::iterator it;
            for(it=dictionary.begin(); it!=dictionary.end(); it++) {
                if(check_string(*it, word)==1)return true;
            }   
            return false;
    }

    int check_string(string word, string search){

	    if(word.length()!=search.length()) 
		    return 0;
	    else {
		    for(int i=0; i<word.length();i++){
			    if(search[i]=='.') continue;
			    if(search[i]!=word[i]) return 0;
		    }
		    return 1;
	    }
    }
};

int main(){
	WordDictionary dict;
	dict.addWord("bad");
	dict.addWord("mad");
	dict.addWord("dad");
	cout <<	dict.search("bad");	
}
