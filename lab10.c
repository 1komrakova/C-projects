#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUMBER(A, B) ({\
	int max = (A)[0];\
	int i;\
	for(i = 1; i < (B); i++){\
	if ((A)[i] > max){\
		max = (A)[i];\
	}\
	}\
	max;\
})

int main(){
	char input[1000];
	int count = 0;
	int numbers[1000];
	printf("enter: ");
	fgets(input, sizeof(input), stdin);
	
	char *a = strtok(input, " \n");
	int i = 0;
	while (a != NULL){
		numbers[count] = atoi(a);
		count++;
		a = strtok(NULL, " \n");
	}
	
	int max_number = MAX_NUMBER(numbers, count);
	printf("max number = %d\n", max_number);
	return 0;
}
