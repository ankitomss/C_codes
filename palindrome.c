#include <stdio.h>


int palindrome(char * string, int start, int end);
int main(){

int answer = palindrome("abba",0,3);

printf("answer = %d", palindrome("abc",0,2));

}

int palindrome(char * string, int start, int end) {

if(start == end || end == start + 1)
return 1;

if(string[start] == string[end]){
	return palindrome(string, start+1, end-1);
}else
return 0;

}
