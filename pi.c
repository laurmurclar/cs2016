#import <pthread.h>
#import <stdlib.h>
#import <stdio.h>

#define		NTHREADS	4;
#define 	NDENOM		4000;
struct data {
	int start;
	int end; //this should be the start of the next thread
	int sum; //result
};

void pi_thread(data * p){
	int sign = 1;
	double sum = 0;
	for (int i = p->start; i < p->end; i+=2){
		sum += sign/i;
		sign = -sign;
	}
	p->sum = sum;
}
int main(int argc, char const *argv[])
{
	pthread_t	thread[NTHREADS];
	data 		info[NTHREADS];
	int denoms_per_thread = NTHREADS/NDENOM;
	int rc =0;
	int start = 1;
	for(int i = 0; i < NTHREADS; i++){
		//pass the data into the threads data space
		info[i]->start = start;
		info[i]->end = start+denoms_per_thread-1;
		start = start+denoms_per_thread-1;
		//create thread
		rc = pthread_create(&thread[i], NULL, pi_thread, &info[i]);
		checkResults("pthread_create()\n", rc);
	}
	//join threads
	printf("Wait for the threads to complete\n");
	for (i=0; i <NTHREADS; i++) {
		rc = pthread_join(thread[i], NULL);
		checkResults("pthread_join()\n", rc);
	}
	//collect results
	int result = 0;
	for (int i = 0; i < NTHREADS; i++){
		result += info[i]->sum; 
	}
	//return the overall result
	result *= 4;
	printf("Result: %f\n", result);
	return 0;
}