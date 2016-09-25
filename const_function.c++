#include<iostream>

using namespace std;

class A{
	public:
	void nonConst(){}
	void const_function() const {}
};

int main(){

	A test;
	test.nonConst();
	test.const_function();

	const A obj_const = A();
	obj_const.const_function();
//	obj_const.nonConst();
}
