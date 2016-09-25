#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> a){
	for(int i=0;i<a.size();i++)
		cout<<a[i] <<" ";
}

vector<int> order(vector<int> &heights, vector<int> &infronts) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> result (heights.size(),-1);
    vector<int> h=heights;
    sort(h.begin(), h.end());
    vector<int> in=infronts;
    
    for(int i=0; i<h.size();i++){
        for(int j=0;j<h.size();j++) {
            if(heights[j]==h[i]) {
                in[i]=infronts[j];
                break;
            }
        }
    }
	cout<<"height is";
    print(heights);cout<<"\n";
    cout<<"h is "; print(h);cout<<"\n";
	print(infronts);cout<<"\n";
    print(in);cout<<"\n";	
    for(int i=0; i<h.size();i++){
        int space=in[i];
        int j=0;
        while(space) {
            if(result[j]==-1) {space--;}
            j++;
        }
       if(space==0){
	       while(result[j]!=-1) j++;
	       result[j]=h[i];
       }
        
    }
    print(result);
    return result;
    
}

int main(){
	vector<int> height (8,0);
	height[0]=86;
	height[1]=92;
	height[2]=49;
	height[3]=21;
	height[4]=62;
	height[5]=27;
	height[6]=90;
	height[7]=59;

	vector<int> in(8,0);
	in[0]=2;
	in[1]=0;
	in[2]=0;
	in[3]=2;
	in[4]=0;
	in[5]=2;
	in[6]=1;
	in[7]=3;
	order(height,in);


}
