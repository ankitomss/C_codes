#include<stdio.h>
#include<stdlib.h>



struct node{
	int no;
	struct node * left;
	struct node * right;
};


void print_bst(struct node *  head);
void mirror_bst(struct node *  head);


void make_bst(struct node *  head, int value);
void make_bst(struct node *  head, int value){
	if (head == NULL) {
		head = (struct node *) malloc(sizeof(struct node));
		head->left=NULL;
		head->right=NULL;
		head->no=value;
	}
	else {
		int done=0;
		struct node * temp = head;
		do{	
			done=0;
			if(temp->no > value && temp->left == NULL) {
				temp->left = (struct node*) malloc(sizeof(struct node));
				temp->left->no = value;
				temp->left->left=NULL;
				temp->left->right=NULL;
				done=1;
			}		
		       	if(temp->no < value && temp->right ==NULL) {

				temp->right = (struct node*) malloc(sizeof(struct node));
				temp->right->no = value;
				
				temp->right->left=NULL;
				temp->right->right=NULL;
				done=1;
			}


		       	if(temp->no > value && temp->left !=NULL) temp=temp->left;
		       	if(temp->no < value && temp->right !=NULL) temp=temp->right;
		}while(!done);
	}
}

void print_bst(struct node * head){

	if(head==NULL) return;
	
	printf("node %d \n", head->no);
	struct node* temp=head;
	if(temp->left!=NULL) print_bst(temp->left);
	if(temp->right!=NULL) print_bst(temp->right);
}

void mirror_bst(struct node * head){
	if(head==NULL) return;
	struct node * temp = head;
	mirror_bst(temp->left);
	mirror_bst(temp->right);
	
	struct node * swap = temp->left;
	temp->left = temp->right;
	temp->right = swap;

}

int main(){

	struct node* head = (struct node*)malloc(sizeof(struct node));
	head->left=NULL;
	head->right=NULL;
	head->no=7;
	make_bst(head, 5);
	make_bst(head, 9);
	make_bst(head, 3);
	make_bst(head, 6);
	
	print_bst(head);

	mirror_bst(head);
	print_bst(head);
}
