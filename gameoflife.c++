#include<iostream>
//#include<stdlib>
#include<vector>
using namespace std;


class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
        vector<vector <int> > next_gen(board.size(), vector<int> (board[0].size(),0));
        vector<vector<int> >::iterator row_it=board.begin();
        vector<int>::iterator col_it;
       
		
	for(int row=0; row<board.size(); row++){
            for(int col=0; col<board[0].size();col++){
                int neighbhours = check_neighbour(board, row, col);
                if( neighbhours < 2 && board[row][col]==1) next_gen[row][col]=0;
                if((neighbhours == 2 || neighbhours == 3) && board[row][col]== 1) next_gen[row][col]=1;
                if(neighbhours > 3 && board[row][col]==1) next_gen[row][col]=0;
                if(neighbhours == 3 && board[row][col]==0) next_gen[row][col]=1;
                
            }
        }

	board=next_gen;

        
    }
    
int check_neighbour(vector<vector<int> >& board, int row, int col){
        int ysize = board[0].size();
        int xsize = board.size();
        
        int neigh=0;
        
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0 && j==0) continue;
                if(row+i<0 || row+i >= xsize) continue;
                if(col+j<0 || col+j >= ysize) continue;
                
                if(board[row+i][col+j] ==1) neigh++;
            }
        }
        
        return neigh;
    }
};

int main(){


	return 0;
}
