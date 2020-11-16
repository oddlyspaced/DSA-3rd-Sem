#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

void create(int arr[], int size) {
    struct node *temp, *last;
    head = (struct node*) malloc(sizeof(struct node));
    head->data = arr[0];
    head->next = NULL;
    last = head;

    int i;
    for (i = 1; i < size; i++) {
        temp = (struct node*) malloc(sizeof(struct node));
        temp->next = NULL;
        temp->data = arr[i];

        last->next = temp;
        last = temp;
    }
}

void print_list(struct node *p) {
    while (p != NULL) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

void insert_at(struct node *p, int pos, int val) {
    if (pos == 0) {
        struct node *temp = (struct node*) malloc(sizeof(struct node));
        temp->next = head;
        temp->data = val;
        head = temp;
    }
    else {
        int i;
        for (i = 0; i < pos - 1 ; i++) {
            p = p->next;
        }
        struct node *temp = (struct node*) malloc(sizeof(struct node));
        temp->next = p->next;
        temp->data = val;
        p->next = temp;
    }
}

void delete_at(struct node *p, int pos) {
    if (pos == 0) {
        head = head->next;
    }
    else {
        int i;
        for (i = 0; i < pos - 1; i++) {
            p = p->next;
        }
        p->next = p->next->next;
    }
}

void search(struct node *p, int val) {
    while (p != NULL) {
        if (p->data == val) {
            printf("Value found!");
            return;
        }
        p = p->next;
    }
    printf("Value not found!");
}

void main() {
    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    print_list(head);
    //insert_at(head, 4, 10);
    //print_list(head);
    //delete_at(head, 4);
    //print_list(head);
    search(head, 0);
}