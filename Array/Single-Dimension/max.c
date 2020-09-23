// C program to find the max of an array
#include<stdio.h>
#include<stdlib.h>
void main() {
	int size;
	printf("Enter size of array:\n");
	scanf("%d", &size);
	int *p;
	p = (int*)malloc(size*sizeof(int));
	printf("Enter values:\n");
	int max;
	int i;
	for (i = 0; i < size; i++) {
		scanf("%d", &p[i]);
		if (i == 0) {
			max = p[i];
		}
		else {
			if (max < p[i]) {
				max = p[i];
			}
		}
	}
	
	printf("Largest: %d", max);
	free(p);
}