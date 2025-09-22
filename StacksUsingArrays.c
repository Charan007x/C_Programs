#include <stdio.h>
#include<stdlib.h>
#define max 5
struct stack{
	int a[max];
	int top;
};
void initialise(struct stack *st){
	st->top=-1;
}
int isFull(struct stack *st){
	if(st->top==max-1) return 1;
	return 0;
}
int isEmpty(struct stack *st){
	if(st->top==-1) return 1;
	return 0;
}
void push(struct stack *st,int val){
	if(isFull(st)){
		printf("Stack is Full");
		exit(1);
	}
	st->top++;
	st->a[st->top]=val;
	return;
}
int pop(struct stack *st){
	if(isEmpty(st)){
		printf("Stack is Empty");
		exit(1);
	}
	int data=st->a[st->top];
	st->top--;
	return  data;
}
void display(struct stack *st){
	if(isEmpty(st)){
		printf("Stack is Empty");
		exit(1);
	}
	int i;
	for(i=st->top;i>=0;i--){
		printf("%d ",st->a[i]);
	}
}
int main(){
	struct stack st;
	initialise(&st);
	push(&st,10);
	push(&st,20);
	push(&st,30);
	display(&st);
	printf("\n %d\n",pop(&st));
	display(&st);
	
}
