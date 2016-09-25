#include<iostream>
#include<string>

using namespace std;

typedef struct node{
	int val;
	struct node * next;
} ListNode;

struct node* insert(struct node* head, int x){
	struct node * temp = head;
	if(temp == NULL){
		temp = (struct node*) malloc(sizeof(struct node));
		temp->val = x;
		temp->next = NULL;
		return temp;
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
	}
//	cout << "here is this" << temp->val;
	temp->next = (struct node*) malloc(sizeof(struct node));
	temp->next->val = x;
	temp->next->next = NULL;
	return head;
}

struct node* insert2(struct node * head, int no){
	if (head == NULL)
	{	head = (struct node*)malloc(sizeof(struct node));
		head->val = no;
		head->next = NULL;
		return head;
	}
	struct node * temp = head;
	while(temp->next!=NULL) temp=temp->next;
	temp->next = (struct node*) malloc(sizeof(struct node));
	temp->next->val = no;
	temp->next->next=NULL;
	return head;
}

void printlist(struct node * head){
	struct node* temp = head;
	while(temp != NULL){
		cout << temp->val << " "; 
		temp = temp->next;
	}
}

struct chk{
	int val;
	struct chk *next;
};
void check(struct chk *x, int data){
	x->next = (struct chk*) malloc(sizeof(struct chk));
	x->next->val = data;
	x->next->next = NULL;
}

struct node * reverse(struct node* root){
	if(!root) return root;
	
	struct node *ll, *cc, *ff;
	ll = root; cc = root->next; ff = (root->next)?root->next->next: NULL;
	
	while (cc){
		cc->next = ll;
		ll = cc; cc = ff; ff = (ff)? ff->next: NULL;
	}
	
	root->next = NULL;
	return ll;
}

bool detectCC(ListNode * root){
	if(!root) return false;
	ListNode *ss, *ff;
	ss = root; ff = root;
	
	while(ff && ff->next && ff->next->next){
		ss = ss->next;
		ff = ff->next->next;
		if(ss == ff) return true;
	}
	
	return false;
}


int main(){
	struct node * head = NULL;
	
	head = insert( head, 4);
	head = insert( head, 2);
	head = insert( head, 1);
	printlist(head);
	head = reverse(head);
	cout << "printing reverse";
	printlist(head);
	cout << detectCC(head);
	head->next->next->next = head->next;
	cout << detectCC(head);
//	check(x, 666);
//	cout << x->val << x->next->val;
	
	return 0;
}