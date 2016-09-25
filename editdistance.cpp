#include<iostream>
#include<vector>
#include<string>
using namespace std;


int minDistance(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m=A.size(), n=B.size();
    if(m==0) return n;
    if(n==0) return m;
    int dp[m+1][n+1]; 
    
	cout<< m << n;
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
		cout<< " i am in the loop\n";
            if(i==0) dp[i][j]=j;
            else if (j==0) dp[i][j]=i;
            else if(A[i]==B[j]) {cout<<"so you think I am equal";dp[i][j] = dp[i-1][j-1];}
            else {
                dp[i][j] = (1 + min(min(dp[i][j-1], dp[i-1][j]),dp[i-1][j-1]));
		cout << "i am here and m  and n are" << m << n;
		cout << "now the value is DP "<< dp[m][n];
            }
        }
    }
    return dp[m][n];
}

int main(){
	string A="A";
	string B="B";
	cout <<  minDistance(A,B);
}
