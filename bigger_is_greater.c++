#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool swapword_check(string word, char new_char, char old_char);
bool print_lex(string word){
	string sort_word = word;
	sort(sort_word.begin(),sort_word.end());
	for(int i=word.length()-1; i >=0 ; i--){
		int next_char = sort_word.find(word[i])+1;

		while(next_char < word.length()){
			if(swapword_check(word, sort_word[next_char], word[i])==true) return true;
			next_char++;	
		}
	}
}

bool swapword_check(string word, char new_char, char old_char){
	string word_copy=word;
	int new_pos = word.find(new_char);
	int old_pos = word.find(old_char);
	swap(word_copy[new_pos],word_copy[old_pos]);
	if(word_copy.compare(word) > 0) {

		cout << word_copy;
		return true;
	}
	
}


int main() {


	string play = "hello my name is Ankit";
	string::iterator it;

/*	for(it=play.begin(); it!=play.end();it++)
		cout << *it;
*/
	int pos = play.find("Ankit");
//	cout << "here I am printing the position" << play[pos] << "\n";
//	swapword_check("Ankit", 'n', 'i');
//	print_lex("hefg");
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   

	string check = "aakit verma";
	swap(check[0], check[6]);
	//sort(check.begin()+3, check.end());
	cout << check;

	return 0;
}
