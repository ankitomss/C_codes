#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int> >A, int m ,int n);
void print(vector<vector<int> >A, int m ,int n){
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A[i].size();j++)
				cout<< A[i][j]<< " ";
		cout<<"\n";
	}
}

int minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()==0) return 0;
    int m=A.size();
    int n=A[m-1].size();
    cout << "m and n are "<<m << " "<<n;
    vector<vector<int > > dp(m, vector<int>(n,0) );
    dp[0][0]=A[0][0];
    int lcol=A[0].size()-1;
    for(int i=1;i<m;i++){
        for(int j=0;j<A[i].size();j++){
            if(i==0 && j==0) dp[i][j]=A[i][j];
            else if(j==0) {
                dp[i][j]=A[i][j] + min(dp[i-1][j],((j>=lcol)?INT_MAX:dp[i-1][j+1]));
            }else{
                dp[i][j]=A[i][j] + min(min(dp[i-1][j-1], ((j>lcol)?INT_MAX:dp[i-1][j])), ((j>=lcol)?INT_MAX:dp[i-1][j+1]));                
            }
        }
        lcol=A[i].size()-1;
    }
    
    int _min=A[m-1][0];
    for(int i=0;i<n;i++)
       _min=min(_min, dp[m-1][i]);
        
        
    print(A, m, n);
    print(dp, m, n);

    return _min;

}    

int main(){
	vector<vector<int> >A;
	vector<int> row;
	row.push_back(2);
	A.push_back(row);
	row.clear();
	row.push_back(6);
	row.push_back(6);
	A.push_back(row);
	row.clear();
	row.push_back(7);
	row.push_back(8);
	row.push_back(4);
	A.push_back(row);
cout<<"actual result is "	<<minimumTotal(A);

}
