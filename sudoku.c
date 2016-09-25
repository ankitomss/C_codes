#include<stdio.h>

int matrix[9][9] = 
{{8,0,1,0,0,2,0,3,0},
{0,0,7,3,8,0,0,6,0},
{0,3,0,9,0,0,0,0,0},

{0,0,3,2,0,0,0,7,0},
{0,4,0,5,0,8,0,9,0},
{0,8,0,0,0,7,3,0,0},

{0,0,0,8,0,6,0,4,0},
{0,6,0,0,5,3,7,0,0},
{0,1,0,7,0,0,8,0,6},};

int print_matrix(){
	for(int i =0;i<9;i++) {
		for(int j=0;j<9;j++) {
			printf(" %d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("******************\n");
}

int is_safe(int x, int y, int data) {
	
	for(int i=0;i<9;i++){
		if(matrix[x][i] == data)
			return 0;
	}


	for(int i=0;i<9;i++){
		if(matrix[i][y] == data) 
			return 0;
	}

	int x_mul = x/3;
	int y_mul = y/3;

	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++){
			if(matrix[x_mul*3 + i][y_mul*3 +j] == data)
				return 0;
		}
	}

	return 1;

}

int fill_place(int x, int y)
{

	while(matrix[x][y]!=0){
		y=y+1;
		if(y>8) {
			x=x+1;
			y=0;
		}
		if(x>8){
			print_matrix();
			return 1;
		}
	}


	if(y > 8)
	{
		x = x+1;
		y = 0;
	}

	if(x > 8) {
		print_matrix();
		return 1;
	}

	//printf("now x is %d\n", x);

			for(int i=0;i<9;i++){
				if(is_safe(x,y,i+1)) {
					matrix[x][y] = i+1;
					if(fill_place(x,y+1)==1) { 
						return 1;
					}
					else{
						matrix[x][y] = 0;
					}
				
				}
			}

			return 0;

}


int main()
{
	print_matrix();
	fill_place(0,0);
//	printf("is this safe %d \n", is_safe(0,1,5) );
	print_matrix();

}
