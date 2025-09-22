#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node* next;
};
struct node* create(int val){
	struct node* newNode=(struct node*)malloc(sizeof(struct node));
	newNode->val=val;
	newNode->next=NULL;
	return newNode;
}
void insertAtEnd(struct node** head,int val){
	struct node* newNode=create(val);
	if(*head==NULL){
		*head=newNode;
		return;
	}
	struct node* temp=*head;
	while(temp->next!=NULL) temp=temp->next;
	temp->next=newNode;
	return;
}
void insertAtBeginning(struct node** head,int val){
	struct node* newNode=create(val);
	if(*head==NULL){
		*head=newNode;
		newNode->val=val;
		newNode->next=NULL;
		return;
	}
	newNode->next=*head;
	*head=newNode;
	return;
}
void insertAtMiddle(struct node** head,int val,int pos){
	if(pos<=0){
		printf("Invalid Position");
		exit(1);
	}
	if(pos==1) {
	insertAtBeginning(head,val);
	return;}
	struct node* newNode=create(val);
	int count=1;
	struct node* temp=*head;
	while(temp!=NULL&&count<pos-1){
		temp=temp->next;
		count++;
	}
	newNode->next=temp->next;
	temp->next=newNode;
	return;	
}
void display(struct node** head){
	if(*head==NULL){
		printf("List is Empty");
		return;
	}
	struct node* temp =*head;
	while(temp!=NULL){
		printf("%d ",temp->val);
		temp=temp->next;
	}
}
void deleteAtEnd(struct node** head){
	if(*head==NULL){
		printf("List is Empty");
		exit(1);
	}
	if((*head)->next==NULL){
		free(*head);
		*head=NULL;
		return;
	}
	struct node* temp=*head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	free(temp->next);
	temp->next=NULL;
	return;
}
void deleteAtBeginning(struct node** head){
	if((*head)==NULL){
		printf("List is Empty");
		exit(1);
	}
	struct node* temp = *head;
	*head=(*head)->next;
	free(temp);
	return;
}
void deleteAtMiddle(struct node** head,int pos){
	if((*head==NULL)) return;
	if(pos<=0){
		printf("Invalid Position");
		exit(1);
	}
	if(pos==1){
	deleteAtBeginning(head);
	return;}
	int count=1;
	struct node* temp = *head;
	while(count<pos-1&&temp!=NULL){
		temp=temp->next;
		count++;
	}
	if(temp->next==NULL) {
		deleteAtEnd(head);
		return;
		}
	struct node* temp1=temp->next;
	temp->next=temp->next->next;n
	free(temp1);
	return;
}
int main(){
	struct node* head=NULL;
	insertAtBeginning(&head,10);
	insertAtBeginning(&head,20);
	insertAtBeginning(&head,30);
	deleteAtMiddle(&head,3);
	display(&head);
}
