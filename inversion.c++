#include<iostream>
#include<vector>
#include<string>
using namespace std;

class node{
    public:
    int val;
    node * left;
    node * right;
    node(int x){
        val=x;
        left =NULL;
        right=NULL;
    }
};

class Tree{
  private:
    node* root;
  public:
    Tree(){
        root=NULL;
	cout<<"initializing tree\n";
    }
    
    int insert(int x){
        int count=0;
        if(root ==NULL) {
            root = new node(x);
	    cout<<"root is NULL\n";
        }else{
            node * temp =root;
            node* pre;
            while (temp!=NULL){
                cout<<"its not null\n";
                pre=temp;
                if(temp->val > x) {
			cout << "node compared is " << temp->val<<"\n";
			temp=temp->left;
		}
		else if(temp->val < x) {
		    cout << "node compare is " << temp->val <<"\n";
                    temp=temp->right;
                    count++;
                }
            }
            
            if(pre->val > x) pre->left=new node(x);
            if(pre->val < x) pre->right=new node(x);
        }
        return count;
        
    }
};


int countInversions(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    Tree *t=new Tree();
    
    int count=0;
    for(int i=A.size()-1; i>=0; i--)
        count+=t->insert(A[i]);
    
    return count;
}


int main(){
	vector<int> A;
	A.push_back(12);
	A.push_back(14);
	
	A.push_back(16);
	
	A.push_back(11);
	
	A.push_back(9);
	A.push_back(6);
	
	
	cout << "Answer is " << countInversions(A);
	return 0;
}
