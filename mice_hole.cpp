#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int mice(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n=A.size();
    vector<int> done (n,0);
    int _min=INT_MAX;
    int maxl=INT_MIN;
    int pos, dis;
    for(int i=0;i<n;i++){
        _min=INT_MAX;
        for(int j=0;j<n;j++){
            if(done[j]!=1){
                dis=abs(B[j]-A[i]);
		cout << "dis, hole, mice"<< dis<<B[j]<<A[i]<<"\n";
                if(dis<_min){
                    _min=dis;
                    pos=j;
                }else {
                    done[pos]=1;
                    maxl= max(_min,maxl);
		    cout<< "maxl is "<<maxl<<"\n";
                    break;
                }
            }
        }
    }
    
    return maxl;
}

int main(){

	vector<int> mics(8,0);
	vector<int> holes(8,0);
	mics[0]=-49;
	mics[1]=58;
	mics[2]=72;
	mics[3]=-78;
	mics[4]=9;
	mics[5]=65;
	mics[6]=-42;
	mics[7]=-3;
	holes[0]=30;

	holes[1]=-13;
	holes[2]=-70;
	holes[3]=58;
	holes[4]=-34;
	holes[5]=79;
	holes[6]=-36;
	holes[7]=27;
	mice(mics,holes);
}
