#include<stdio.h>
#include<stdlib.h>

struct node{
int no;
struct node *next;
};

void insert(struct node * head, int no);
void printlist(struct node * head);

void reverse(struct node ** head) {
	
	if(head == NULL) return;
	struct node *pre, *cur, *fut;
	pre=*head;
	cur=*head;
	fut=(*head)->next;
	while(cur!=NULL) {
		
		pre=cur;
		if(NULL!=cur) cur=fut;
		if(NULL!=fut) fut=fut->next;

		if(NULL!=cur) cur->next=pre;
	}
	(*head)->next=NULL;
	*head=pre;
	//printlist(head);
	free(pre);
	free(cur);
	free(fut);
}

int main(){
	printf("want to create list");
	int answer, no;
	struct node * head = (struct node*)malloc(sizeof(struct node));
	head->next=NULL;	
/*	while(answer){
		scanf("%d",&answer);
		printf("enter no");
		
		scanf("%d",&no);
		insert(head, no);
	}*/

		insert(head, 7);
		insert(head, 6);
		insert(head, 5);
		insert(head, 4);
		insert(head, 3);
		insert(head, 2);
	printlist(head);
	reverse(&head);
	printlist(head);

}

void insert(struct node * head, int no){
	if (head == NULL)
	{	head = (struct node*)malloc(sizeof(struct node));
		head->no = no;
		return;
	}
	struct node * temp = head;
	while(temp->next!=NULL) temp=temp->next;
	temp->next = (struct node*) malloc(sizeof(struct node));
	temp->next->no = no;
	temp->next->next=NULL;
}

void printlist(struct node * head){
	struct node * temp=head;
	while(temp->next!=NULL){
	printf("%d",temp->no);
	temp=temp->next;
	}
}







