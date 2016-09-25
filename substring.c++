#include <string.h>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

int findSubString(string s, string matchs){
	map<char, int> count;
	for(int i=0; i< matchs.length(); i++)
		count[matchs[i]]=0;
	
	map<char, int>::iterator it;

	for(int start=0, end=0;end<s.length(); end++){
		it=count.find(s[end]);
		if(it != s.end()){
			
		}
		else {
			start++;
		}
	}
}

int main()
{
}
