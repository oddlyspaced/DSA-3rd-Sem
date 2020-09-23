// C program to insert a value at a given index in an array
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
	
	int ins_index, ins_value;
	printf("Enter value to insert:\n");
	scanf("%d", &ins_value);
	
	printf("Enter index for value to insert:\n");
	scanf("%d", &ins_index);
	
	for (i = size; i >= ins_index; i--) {
		arr[i+1] = arr[i];
	}
	arr[ins_index] = ins_value;
	
	printf("\n");
	// printing array
	for (i = 0; i < size+1; i++) {
		printf("%d\t", arr[i]);
	}
}

