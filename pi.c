#import <pthread.h>
#import <stdlib.h>
#import <stdio.h>

struct data {
	int start;
	int end; //this should be the start of the next thread
	int sum; //result
};

void pi_calc(data * p){
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
	/* code */
	//create threads
	//join threads
	//collect results
	//return the overall result
	return 0;
}