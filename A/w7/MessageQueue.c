#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
struct m{
	long t;
	char txt[50];
};
int main(){
	struct m m1={1,"HELLO"
	};
	int id=msgget(1234,0666|IPC_CREAT);
	msgsnd(id,&m1,sizeof(m1.txt),0);
	msgrcv(id,&m1,sizeof(m1.txt),0,1);
	printf("%s",m1.txt);
}
