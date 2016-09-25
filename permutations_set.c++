#include<iostream>
#include<vector>
#include<set>
using namespace std;


void check(set<int>st);
void _permute(set<int>  st, vector<int> arr, vector<vector<int> >& result, int i, int n){
    
    if(st.empty()) {
        result.push_back(arr);
	cout<<"I am getting hit";
        return;
    }
    
    
    for(set<int>::iterator it=st.begin(); it!=st.end();it++){
	    int val = *it;
        st.erase(val);	
	check(st);
        _permute(st, arr, result, i+1, n);
        st.insert(val);
	check(st);
    }

    check(st);
}

void check(set<int>st){
	cout<< "checking the set now\n";
	for(set<int>::iterator it=st.begin(); it!=st.end();it++){
        	cout << *it <<"\n";
    	}
}

vector<vector<int> > permute(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    set<int> st;
    vector<vector<int> >result;
    vector<int> arr;
    for(int i=0;i<A.size();i++)
        st.insert(A[i]);
    int i=0;
    _permute(st, arr, result, i, A.size());
    return result;
}

int main(){

	vector<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	permute(A);
}
