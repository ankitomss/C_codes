#include<stdio.h>

struct memory{
	unsigned int address:4;
	unsigned int read_en:1;
	unsigned int write_en:1;
	unsigned int write_done:1;
	int data;
	int storage[16];
	int memwrite(int add, int value){
		if(write_en ==1) {
			storage[add] = value;
			write_done=1;
		}
	}
	
/*	int write_signal(int value) {
		write_en=value;
	}
	
	int read_signal(int value) {
		read_en=value;
	}

	int read(int add) {
		if(read_en == 1) {
			return storage[add];
		}
	}*/
	
};

int main(){

	struct memory cache;
	/*cache.write_signal(1);
	cache.write(0,0);
	cache.write(1,11);
	
	cache.write(2,22);
	cache.write(3,33);
	cache.write(4,44);
	cache.write_signal(0);

	cache.read_signal(1);
	 printf("reading %d \n",  cache.read(0));

	 printf("reading %d \n",  cache.read(1));
	 printf("reading %d \n",  cache.read(2));
	 printf("reading %d \n",  cache.read(3));
	 printf("reading %d \n",  cache.read(4));*/
	
}
