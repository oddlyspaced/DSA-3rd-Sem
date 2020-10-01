/* Author: Shreeyans Bahadkar */

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};
struct Node *head, *ptr, *new_node;

void create() 
{
    int node_data;
    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->next = NULL;
    printf("Enter data: ");
    scanf("%d", &node_data);
    new_node->data = node_data;
    if(head == NULL) {
        head = new_node;
        ptr = head;
    }
    else {
        ptr->next = new_node;
        ptr = ptr->next;
    }
}

void traverse() 
{
    struct Node* temp;
    if(head == NULL)
        printf("Linked List is empty.\n");
    else {
        temp = head;
        while (temp != NULL)
        {
            printf("Data: %d\tCurrent Address: %p\tNext Address: %p\n", temp->data, temp, temp->next);
            temp = temp->next;
        }
        
    }
    
}

void insertByLoc() 
{
    struct Node* temp;
    int count = 1;
    int node_data, loc;
    if(head == NULL) {
        printf("Linked List is Empty.");
    }

    else
    {
        new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node->next = NULL;
        printf("Enter data: ");
        scanf("%d", &node_data);
        new_node->data = node_data;
        temp = head;
        printf("Enter the location: ");
        scanf("%d", &loc);

        if (loc == 1)
        {
            new_node->next = head;
            head = new_node;
        }
        
        else
        {
            while(count < loc - 1)
            {
                temp = temp->next;
                count++;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

void insertByData() 
{
    struct Node *temp, *prev;
    int value, node_data;
    if (head == NULL)
    {
        printf("Linked List is empty.");
        return;
    }
    
    printf("Enter value before which you want to insert new node: ");
    scanf("%d", &value);
    printf("Enter data: ");
    scanf("%d", &node_data);
    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = node_data;
    temp = head;

    while(temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Value could not be found");
        return;
    }

    if(temp->data == head->data) {
        new_node->next = temp;
        head = new_node;
        return;
    }

    new_node->next = temp;
    prev->next = new_node;

}

void deleteByLoc() 
{
    struct Node *temp, *prev;
    int loc;
    int count = 1;

    if(head == NULL)
        printf("Linked List is Empty.");
    else {
        printf("Enter location for deletion: ");
        scanf("%d", &loc);
        temp = head;
        if (loc == 1)
        {
            head = head->next;
            free(temp);
        }

        else
        {
            while(count < loc) {
                prev = temp;
                temp = temp->next;
                count++;
            }
            if(temp == NULL)
            {
                printf("Location not found.");
                return;
            }
            if(temp->next == NULL)
            {
                prev->next = temp->next;
                ptr = prev;
                free(temp);
                return;
            }

            prev->next = temp->next;
            free(temp);
        }
        
    }
}

void deleteByData()
{
    struct Node *temp, *prev;
    int value;
    temp = head;
    printf("Enter the value to be deleted: ");
    scanf("%d", &value);

    if(head == NULL)
    {
        printf("Linked List is empty.");
        return;
    }
    else
    {
        while(temp->data != value)
        {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL)
        {
            printf("Value not found.");
            return;
        }  

        if(head->data == value)
        {
            head = head->next;
            free(temp);
            return;
        }
        if(temp->next == NULL)
            {
                prev->next = temp->next;
                ptr = prev;
                free(temp);
                return;
            }

        prev->next = temp->next;
        free(temp);
    } 
}

int main() 
{
    char choice, ins_choice, del_choice;
    while (1) {
    
        printf("-----------------------------\n1. Create\n2. Traverse\n3. Insert\n4. Delete\n-----------------------------\n");
        scanf(" %c", &choice);
        system("cls");
        switch(choice)
        {
        case '1':
            create();
            break;
        
        case '2':
            traverse();
            break;

        case '3':
            system("cls");
            printf("-----------------------------\n1. Insert by Location\n2. Insert by Value\n-----------------------------\n");
            scanf(" %c", &ins_choice);
            switch(ins_choice)
            {
                case '1':
                    insertByLoc();
                    break;
                case '2':
                    insertByData();
                    break;
                default:
                    printf("Invalid Input");
                    exit(0);
                    break;
            }
            break;

        case '4':
            system("cls");
            printf("-----------------------------\n1. Delete by Location\n2. Delete by Value\n-----------------------------\n");
            scanf(" %c", &del_choice);
            switch(del_choice)
            {
                case '1':
                    deleteByLoc();
                    break;
                case '2':
                    deleteByData();
                    break;
                default:
                    printf("Invalid Input");
                    exit(0);
                    break;
            }
            break;

        default:
            printf("Invalid Input");
            exit(0);
            break;
        }
    }
    return(0);
}
