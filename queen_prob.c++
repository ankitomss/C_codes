#include<iostream>
#include<string.h>
using namespace std;

void print_chess(int **chess);
int safe(int ** chess, int x, int y);
int place_queen(int queen, int ** chess){

	if(queen>8) return 0;
/*	cout<<"want to place queen\n";
	int answer;
	cin>>answer;

	if(answer==0)
	{
		print_chess(chess);
		return 0;
	}
	else {
		cout << "now your chess looks like\n";
		print_chess(chess);
	}*/

	for(int i=0; i <8; i++) {
			//print_chess(chess);
			if(safe(chess, queen-1, i)){

				chess[queen-1][i]=1;
				place_queen(queen+1, chess);
		
				if(queen==8) {
                                        cout<<"I am done finding places\n";
                                        print_chess(chess);
                                }	

				chess[queen-1][i]=0;
				if(queen==8) break;
			}
	
	}
}

int safe(int ** chess, int x, int y) {

        for(int i=0; i<8;i++) {
                if(chess[x][i]==1 || chess[i][y]==1)
		return 0;   
        }

        int a=x;
        int b=y;
        while(a<8 && b<8){
                if(chess[a][b]==1) 
			return 0;
                a++;
                b++;
        }


         a=x;
        b=y;
        while(a>=0 && b>=0){
                if(chess[a][b]==1)
			return 0;
                a--;
                b--;
        }

        a=x;
        b=y;

        while(a>=0 && b<8){
                if(chess[a][b] ==1) return 0;
                a--;
                b++;
        }

        a=x;
        b=y;
        while(a<8 && b>=0){
                if(chess[a][b]==1) return 0;
                a++;
                b--;

        }

	return 1;


}

void print_chess(int **chess){
for(int i=0;i<8;i++){
	for(int j=0;j<8;j++){
		cout<< chess[i][j];
	}
	cout<<"\n";
}

cout<<"\n***************************\n";
}


int main()
{

int **chess;
chess = new int*[8];
for(int i=0;i<8;i++) chess[i] = new int[8];
	for(int i=0;i<8;i++) {
		
		for(int j=0;j<8;j++){

			chess[i][j]=0;

		}

	}

	print_chess(chess);

	
	print_chess(chess);
	place_queen(1, chess);

}

