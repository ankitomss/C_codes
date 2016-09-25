#include<iostream>
#include<vector>
using namespace std;

int coinchange2(vector<int> &A, int B) {
   vector<vector<int> > cc (A.size(), vector<int>(B+1,0));
   for(int i=0;i<A.size();i++) {
       cc[i][0]=1;
   }
   
   cc[0][0]=1;
   
   for(int ele=0;ele<A.size();ele++){
        for(int sum=1;sum<=B;sum++){
            cc[ele][sum] = ((sum-A[ele]>=0)?cc[ele][sum-A[ele]]:0) +
                                ((ele-1>=0)?cc[ele-1][sum]:0);
        }
       
   }
   

   for(int i=0;i<A.size();i++){
	   for(int j=1;j<=B;j++){
		   cout << cc[i][j]<<" ";
	   }
	   cout << "\n";
   }
   return cc[A.size()-1][B];
}

int main(){
	vector<int> A;
	
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);

	int B=4;
	coinchange2(A,B);
}
