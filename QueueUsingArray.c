#include <stdio.h>
#include<stdlib.h>
#define max 6
struct queue{
	int a[max];
	int front;
	int rear;
};
void initialise(struct queue *q){
	q->front=-1;
	q->rear=-1;
}
int isEmpty(struct queue *q){
	if(q->rear==-1) return 1;
	return 0;
}
int isFull(struct queue *q){
	if(q->rear==max-1) return 1;
	return 0;
}
void enqueue(struct queue *q, int val){
	if(isFull(q)){
		printf("Queue is Full");
		exit(1);
	}
	if(isEmpty(q)){
		q->front++;
	}
	q->rear++;
	q->a[q->rear]=val;
}
int dequeue(struct queue *q){
	if(isEmpty(q)){
		printf("Queue is Empty");
		exit(1);
	}
	int data=q->a[q->front];
	q->front++;
	return data;
}
void display(struct queue *q){
	if(isEmpty(q)){
		printf("Queue is Empty");
		exit(1);
	}
	int i;
	for(i=q->front;i<=q->rear;i++){
		printf("%d ",q->a[i]);
	}
	return;
}
int main(){
	struct queue q;
	initialise(&q);
	enqueue(&q,10);
	enqueue(&q,20);
	enqueue(&q,30);	
	display(&q);
	dequeue(&q);
	printf("\n");
	display(&q);
}
