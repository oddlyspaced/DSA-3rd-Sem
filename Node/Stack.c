#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *prev;
} *head = NULL;

void push(int data) {
    if (head == NULL) {
        head = (struct node*) malloc(sizeof(struct node));
        head->data = data;
        head->prev = NULL;
    }
    else {
        struct node *temp = (struct node*) malloc(sizeof(struct node));
        temp->data = data;
        temp->prev = head;
        head = temp;
    }
}

int pop() {
    if (head == NULL) {
        printf("\nStack is Empty!");
        return -999;
    }
    else {
        int d = head->data;
        head = head->prev;
        return d;
    }
}

void print_list() {
    struct node *p = head;
    while (p != NULL) {
        printf("\t%d", p->data);
        p = p->prev;
    }
}

void main() {
    push(1);
    push(2);
    print_list();
}