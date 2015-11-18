#include <pthread.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int numThreads;
int numPrimes = 0;
int number;

bool isPrime(int thingNumber){ //thingNumber because i wanted a different name than number

	for (int c=2; c<thingNumber; c++){
		if (thingNumber%c==0||thingNumber==0||thingNumber==1) return false;
	}
	return true;
}

void *threadTask(void *param){
	

	int primes [number];
	int threadID =(int) param;
	int range = (number/numThreads)*(threadID+1); //max value
	int count = (number/numThreads)*threadID; //starting value
	
	for (count;count<range;count++){
		if (isPrime(count)) printf("Thread %d has found a prime number: %d \n",threadID,count); //output primes
	}

}

int main(int argc, char *argv[]){

	numThreads = atoi(argv[1]);
	number = atoi(argv[2]);

	pthread_t tid[numThreads];

	if (argc != 3){
		printf("To use: %s <number of thread> <integer number>",argv[0]);
		return -1;
	}

	if (atoi(argv[1])<0||atoi(argv[2])<0){
		cout<<"Integer agruments must be positive";
		return -1;
	}

	for(int id=0; id<numThreads; id++){
		pthread_create(&tid[id],NULL,threadTask,(void*)id);
	}
	
	for (int id = 0; id<numThreads; id++) pthread_join(tid[id],NULL);

	return 0;
}
