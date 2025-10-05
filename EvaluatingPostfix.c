#include <stdio.h>
#include <stdlib.h>
#define max 100
struct stack{
	float a[max];
	int top;
};
void create(struct stack *st){
	st->top=-1;
}
void push(struct stack *st,float val){
	st->top++;
	st->a[st->top]=val;
}
float pop(struct stack *st){
	return st->a[st->top--];
}
int main(){
	struct stack st;
	create(&st);
	char s[100];
	scanf("%s",s);
	int i;
	for(i=0;s[i]!='\0';i++){
		char ch=s[i];
		if(ch>='0'&&ch<='9'){
			push(&st,ch-'0');
		}
		else{
			float val2=pop(&st);
			float val1=pop(&st);
			switch (ch){
				case '+': push(&st,val1+val2);break;
				case '-': push(&st,val1-val2);break;
				case '*': push(&st,val1*val2);break;
				case '/': push(&st,val1/val2);break;
				default:
					printf("Invalid Operator");
					break;
			}
		}
	}
	printf("%f",pop(&st));
}
