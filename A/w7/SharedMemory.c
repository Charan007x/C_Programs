#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main(){
	int id=shmget(1234,1024,0666|IPC_CREAT);
	char *p=shmat(id,NULL,0);
	sprintf(p,"Hello world");
	printf("%s",p);
	return 0;
}
