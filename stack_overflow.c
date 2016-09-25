#include<stdio.h>
void fun(){
	fun();
}
int main(){
	while(1){
		fun();
	}
	return 0;
}
