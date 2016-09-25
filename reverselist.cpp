#include<iostream>
using namespace std;
struct ListNode{
	int val;
	struct ListNode * next;
};

ListNode * reverse(ListNode * head);

ListNode * reverse(ListNode * head){
	if (head == NULL){
		return head;
	}
	
	ListNode * dummy;
	dummy->val = 0;
	dummy->next =  head;
	ListNode * first, *second, *third;
	first = dummy; second = dummy->next; third = (dummy->next->next) ? dummy->next->next : NULL;
	
	while(second){
		second->next = first;
		first = second; second = third; third = (third->next) ? third->next: NULL;
	}
	dummy->next->next = NULL;
	return first;
}

int main(){
	ListNode * head, * second; 
	head = (struct ListNode*) malloc(sizeof(struct ListNode));
	second = (struct ListNode*) malloc(sizeof(struct ListNode));
	head->val = 1;
	second->val = 2;
	head->next = second; second->next = NULL;
	cout << head->next->val;
//	ListNode* third = reverse(head);
//	cout << third->val;
	return 0;
}
