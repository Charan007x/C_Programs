#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 5

int buffer[SIZE];
int in=0,out=0;

sem_t empty,full,mutex;

void* producer(void* arg){
	int item=1;
	for(int i=0;i<SIZE;i++){
		sem_wait(&empty);
		sem_wait(&mutex);
		
		buffer[in]=item;
		printf("Produced %d \n",item);
		item++;
		in=(in+1)%SIZE;
		sem_post(&mutex);
		sem_post(&full);
	}
}

void * consumer(void * arg){
	for(int i=0;i<SIZE;i++){
		sem_wait(&full);
		sem_wait(&mutex);
		int item=buffer[out];
		printf("Consumed %d \n",item);
		out=(out+1)%SIZE;
		sem_post(&mutex);
		sem_post(&empty);
	}
}

int main(){
	pthread_t p,c;
	sem_init(&empty,0,SIZE);
	sem_init(&full,0,0);
	sem_init(&mutex,0,1);
	
	pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);
}
