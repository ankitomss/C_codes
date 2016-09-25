#include<iostream>
using namespace std;

void writeMemoryLocation(void * ptr, int val){
	memcpy(ptr, &val, sizeof(val));
}

int main(){
	int *ptr = (int*)malloc(sizeof(int));
	cout << ptr << " "<< *ptr << " ";
	writeMemoryLocation((void*) ptr, 123);
	cout << *ptr;
	return 0;
}