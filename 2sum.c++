#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;


vector<int> twoSum(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    map<int, vector<int> > mp;
    vector<int> result;
    for(int i=0; i<A.size();i++) {
        
        //vector<int> temp = 
//        mp[A[i]];
        /*temp.push_back(i);*/
        //mp[A[i]] = temp;
        mp[A[i]].push_back(i);
    }
    
    int min_index2=INT_MAX;
    
    for(int i=0; i <A.size();i++) {
        
        if(mp.find(B-A[i]) != mp.end()) {
            result.push_back(i);
            result.push_back(mp[B-A[i]][0]);
        }
        
        if(min_index2 > mp[B-A[i]][0]) {
            min_index2 = mp[B-A[i]][0];
            result.clear();
            result.push_back(i);
            result.push_back(mp[B-A[i]][0]);
        }
    }
    
    return result;
}


int main(){
	vector <int> A (3);
	A[0]=10;
	A[1]=12;
	A[2]=-1;
	twoSum(A, 10);
	map<int, vector<int> > mp;
	mp[A[0]].push_back(1);
	mp[A[0]].push_back(2);
	cout << mp[A[0]][0] << " and " << mp[A[0]][1];
}
