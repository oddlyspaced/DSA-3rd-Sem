#include<stdio.h>
#include<stdlib.h>
struct node {
    char data;
    struct node *prev;
} *head = NULL;

void push(char data) {
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

char pop() {
    if (head == NULL) {
        printf("\nStack is empty!");
        exit(1);
        return '\0';
    }
    else {
        char data = head->data;
        head = head->prev;
        return data;
    }
}

char peek() {
    if (head == NULL) {
        printf("\nStack is empty!");
        return '\0';
    }
    else {
        char data = head->data;
        return data;
    }
}


void print_list(struct node *p) {
    while (p != NULL) {
        printf("%c", p->data);
        p = p->prev;
    }
    printf("\n");
}

int is_operator(char c) {
    char op[] = {'^', '+', '-', '*', '/', '%', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int i;
    for (i = 0; i < 6; i++) {
        if (op[i] == c) {
            return 1;
        }
    }
    return 0;
}

int check_priority(char c) {
    char op[] = {'+', '-', '*', '/', '%', '^', '('};
    int prior[] = {1, 1, 2, 2, 2, 3, 99};
    int index;
    for (index = 0; index < 7; index++) {
        if (op[index] == c) {
            return prior[index];
        }
    }
    return -1;
}

void pop_until_bracket() {
    while (1) {
        if (peek() == '(') {
            break;
        }
        else {
            printf("%c", pop());
        }
    }
}

// checks if stack has a higher order operator than the current one
int check_operator(char current) {
    char in_stack = peek();
    int pr_stack = check_priority(in_stack);
    int pr_current = check_priority(current);
    
    if (pr_stack == 99) {
        push(current);
    }
    else if (pr_current > pr_stack) {
        push(current);
    }
    else if (pr_current == pr_stack) {
        printf("%c", pop());
        push(current);
    }
    else if (pr_current < pr_stack) {
        pop_until_bracket();
        push(current);
    }
}

void parse_infix() {
    char exp[] = {'(', 'x', '^', 'y', '/', '(', '5', '*', 'z', ')', '+', '1', ')'};
    int i;
    for (i = 0; i < 13; i++) {
        char c = exp[i];
        if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            pop_until_bracket();
        }
        else {
            if (is_operator(c) == 1) {
                check_operator(c);
            }
            else {
                printf("%c", c);
            }
        }
    }
}

void main() {
    parse_infix();
}