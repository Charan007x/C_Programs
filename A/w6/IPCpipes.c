#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	int fd[2];
	char msg[50]="Hello from parent";
	char buffer[50];
	pipe(fd);
	if(fork()==0){
		read(fd[0],buffer,sizeof(buffer));
		printf("Message from parent %s\n",buffer);
	}else{
		write(fd[1],msg,sizeof(msg));
	}
	return 0;
}

// in wsl
// gcc w6a.c -o w6a -> for compiling
// ./w6a -> To run the program
