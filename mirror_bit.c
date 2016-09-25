#include<stdio.h>

int mirror_bit(int x){
	int temp=0, high=1, low=~high;

	for(int i=0;i<32;i++){

		if(x&high){
			temp=temp|high;
			temp=temp<<1;
		}
		else{
			temp=temp&low;
			temp=temp<<1;
		}
		x=x>>1;
	}
	return temp;
}


int main()
{
	printf("mirror image is %d", mirror_bit(1073741824));
}
