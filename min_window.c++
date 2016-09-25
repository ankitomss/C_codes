#include<iostream>
#include<string>
#include<map>
using namespace std;

string minWindow(string S, string T) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    map<char, int> mp;
    int count=0;
    
    for(int i=0;i<T.size();i++){
        mp[T[i]]++;
        count++;
    }

    for(int i=0; i<T.size();i++)
	    cout << "char " << T[i] << "value "<< mp[T[i]] <<"\n";
    
    int l=0, r=0, min_len, left=0, right=0;
    int first = true;
    for(int r=0; r<S.size(); r++){
        if(mp.find(S[r]) != mp.end())
        {
            if(mp.at(S[r]) > 0) count--;
            mp.at(S[r])--;
            
            if(first){l=r; first=false;}
        }
        
        
    
        if(count==0) {
            min_len=r-l+1;
            left=l;
            right=r;
            count--;
	    cout << "I found the string at " << left << "and" << right <<"\n";
        }
        
        if(count<0 && mp.find(S[r])!=mp.end()){
//            mp.at(S[r])--;


            while(mp.find(S[l])==mp.end() || mp.at(S[l])<0){
                //cout << "char" << S[l] << mp.at(S[l]);
                if(mp.find(S[l])!=mp.end()){
		       	mp[S[l]]++;
			cout << "now I am incrementing " << S[l] << "count"<< mp[S[l]] <<"\n";
		}

                l++;
            }
                
            
            if(min_len > r-l+1) {
                min_len=r-l+1;
                left=l;
                right=r;
		cout << "min lenght is " << min_len << "\n";
            }
        }
    }
    
    if(left!=right);
        return S.substr(left,right-left+1);
    
    return "";
}


int main(){

	cout<< "final answer is " << minWindow("ADOBECODEBANC","ABC");

}
