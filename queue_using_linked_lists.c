#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node *NODE;

NODE getnode() {
    NODE temp = (NODE) malloc(sizeof(NODE));
    if (temp == NULL) {
        printf("Node not created\n");
        return NULL;
    }
    else {
        return temp;
    }
}

NODE insert_rear(NODE first, int item) {
    NODE temp = getnode();
    temp->data = item;
    temp->next = NULL;
    if (first == NULL) {
        return temp;
    }
    NODE cur = first;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = temp;
    return first;
}

NODE delete_front(NODE first) {
    if (first == NULL) {
        printf("Queue Underflow\n");
        return NULL;
    }
    if (first->next == NULL) {
        printf("[%d] Deleted\n", first->data);
        free(first);
        return NULL;
    }
    printf("[%d] Deleted\n", first->data);
    first = first->next;
    return first;
}

void display(NODE first) {
    if (first == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    NODE cur = first;
    printf("Queue Elements are\n");
    while (cur != NULL) {
        printf("[%d]\t", cur->data);
        cur = cur->next;
    }
}

void main() {
    NODE first = NULL;
    int ch, item;
    while(1) {
        printf("Enter the choice:\n1.insertrear\n2.deletefront\n3.display\n4.exit\n");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
                printf("Enter item ");
                scanf("%d", &item);
                first = insert_rear(first, item);
                break;
            case 2:
                first=delete_front(first);
                break;
            case 3:
                display(first);
                break;
            case 4:
                exit(0);
            default:printf("Invalid choice!\n");
        }
    }
}