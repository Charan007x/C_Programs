#include <stdio.h>
#include <stdlib.h>
struct node{
	int val;
	struct node* prev;
	struct node* next;
};
struct node* create(int val){
	struct node* newNode=(struct node*)malloc(sizeof(struct node));
	newNode->val=val;
	newNode->prev=NULL;
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
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newNode;
	newNode->prev=temp;
	return;
}
void insertAtBeginning(struct node** head,int val){
	if(*head==NULL){
		printf("List is Empty");
		exit(1);
	}
	struct node* newNode=create(val);
	newNode->next=*head;
	(*head)->prev=newNode;
	*head=newNode;
	return;
}
void insertAtMiddle(struct node** head,int val,int pos){
	if(*head==NULL){
		printf("List is Empty");
		exit(1);
	}
	if(pos<=0){
		printf("Invalid position");
		exit(1);
	}
	if(pos==1){
		insertAtBeginning(head,val);
		return;
	}
	int count=1;
	struct node* newNode=create(val);
	struct node* temp=*head;
	while(temp!=NULL&&count<pos-1){
		temp=temp->next;
		count++;
	}
	if(temp->next==NULL){
		insertAtEnd(head,val);
		return;
	}
	struct node* x=temp->next;
	x->prev=newNode;
	newNode->next=x;
	temp->next=newNode;
	newNode->prev=temp;
	return;
}
void display(struct node** head){
	if(*head==NULL){
		printf("List is Empty");
		return;
	}	
	struct node* temp=*head;
	while(temp!=NULL){
		printf("%d ",temp->val);
		temp=temp->next;
	}
	return;
}
void deleteAtBeginning(struct node** head){
	if(*head==NULL){
		printf("List is EMpty");
		return;
	}
	struct node* temp=*head;
	*head=(*head)->next;
	(*head)->prev=NULL;
	free(temp);
	return;
}
void deleteAtEnd(struct node** head){
    if(*head==NULL){
        printf("List is Empty\n");
        return;
    }
    struct node* temp=*head;
    if(temp->next==NULL){ // only one node
        *head=NULL;
        free(temp);
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    struct node* x=temp->prev;
    x->next=NULL;
    free(temp);
}

void deleteAtMiddle(struct node** head,int pos){
	if(*head==NULL){
		printf("List is Empty");
		return;
	}
	if(pos<=0){
		printf("Invalid Position");
		return;
	}
	if(pos==1){
		deleteAtBeginning(head);
		return;
	}
	struct node* temp=*head;
	int count=1;
	while(temp!=NULL&&count<pos-1){
		temp=temp->next;
		count++;
	}
	if(temp->next==NULL){
		deleteAtEnd(head);
		return;
	}
	struct node* y=temp->next;
    struct node* x=y->next;
    temp->next=x;
    x->prev=temp;
    free(y);
    return;
}
int main(){
	struct node* head=NULL;
	insertAtEnd(&head,10);
	insertAtEnd(&head,20);
	insertAtEnd(&head,30);
	display(&head);
	printf("\n");
	deleteAtMiddle(&head,3);
	display(&head);
}
