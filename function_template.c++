#include<iostream>
using namespace std;

template <class T>
T sum(T a, T b) {

T result;
result = a + b;
return result;
}

template <class T, class U>
bool compare(T a, U b) {
	return (a==b);
}

int main(){

cout<< sum(2, 3);
cout<< sum(2.3, 3.5);
cout << compare(2, 2.0);
cout << compare(2, 2.3);
}
