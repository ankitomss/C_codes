#include<iostream>
#include<string>
using namespace std;
int atoi(string s);

int atoi(string s){
	if(s.empty()) 
		return -1;
	int sum = 0;
	for(int i=0; i<s.size(); i++){
		int x = s[i] - '0';
		sum = sum * 10 + x;
	}
	
	return sum;
}

int main(){
	string s = "73";
	cout << atoi(s) << "\n";
}