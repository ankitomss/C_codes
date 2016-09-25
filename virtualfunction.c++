#include<iostream>
using namespace std;

class polygon{
protected:
 	int length, width, height;
public:
	void set_values(int a, int b){
		length =a;
		width=b;
	}
	virtual int area()=0;
};

class rectangle:public polygon
{
	public:
		int area(){ return length*width;} 
};

class triangle:public polygon
{
        public:
                int area(){ return length*width/2;}
};

int main(){
	rectangle rect;
	polygon *poly =&rect;
	poly->set_values(4,3);
	cout<< "rectangle area is "<< poly->area();
	
}
