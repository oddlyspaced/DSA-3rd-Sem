// C program to delete an element in Array
#include<stdio.h>
void main() {
	int size;
	printf("Enter size of array:\n");
	scanf("%d", &size);
	int arr[size];
	
	printf("Enter values:\n");
	int i;
	for (i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
	
	printf("\n");
	// printing array
	for (i = 0; i < size; i++) {
		printf("%d\t", *(arr+i));
	}
	
	printf("\n");
	
	// deleting value
	int del_index;
	printf("Enter index to delete value at:\n");
	scanf("%d", &del_index);
	
	for (i = del_index; i < size-1; i++) {
		arr[i] = arr[i+1];
	}
	
	printf("\n");
	// printing array
	for (i = 0; i < size-1; i++) {
		printf("%d\t", *(arr+i));
	}
	
}