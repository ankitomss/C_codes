#include<iostream>
#include<string>
using namespace std;
class ABC{
    public:
    void create(int N, int K, string & result, string cur_string, string abc, int j, int & done, int bigger_a, int num_c){
       	

	    
        if(N==0 && K==0){
            result=cur_string;
            done=1;
            return;
        }

	if(N==0) return;

        for(int i=0;i<3;i++){
            if(!done)create(N-1,(i==1)?K-num_c:((i==2)?K:K-bigger_a),result, abc[i]+cur_string,abc, i, done, (i==0)?bigger_a:bigger_a+1, (i==2)?num_c+1:num_c);
        }
    }
    
    string createString(int N, int K){
        string result="", abc="ABC";
        int done=0, j=-1;
        string cur_string="";
        int bigger_a=0,num_c=0;
        create(N,K,result,cur_string,abc,j,done, bigger_a, num_c);
    	return result;    
    }
    
};


int main(){
	ABC o;
	int m,n;
	cin >> m >> n;
	cout<<o.createString(m,n);
	return 0;

}
