#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
} *first = NULL;

void create(int a[], int size) {
	struct node *temp, *last;
	int i;
	first = (struct node*) malloc(sizeof(struct node));
	first->data = a[0];
	first->next = NULL;
	last = first;
	for (i = 1; i < size; i++) {
		temp = (struct node*) malloc(sizeof(struct node));
		temp->data = a[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
	last->next = first;
}

void print_list(struct node *p) {
	do {
		printf("%d,", p->data);
		p = p->next;
	}
	while (p != first);
}

void main() {
	int a[] = {1, 2, 3, 4, 5};
	create(a, 5);
	print_list(first);
}
