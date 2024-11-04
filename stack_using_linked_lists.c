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

NODE insert_front(NODE first, int item) {
    NODE temp = getnode();
    temp->data = item;
    temp->next = NULL;
    if (first == NULL) {
        return temp;
    }
    temp->next = first;
    return temp;
}

NODE delete_front(NODE first) {
    if (first == NULL) {
        printf("Stack Underflow\n");
        return NULL;
    }
    if (first->next == NULL) {
        printf("[%d] Popped\n", first->data);
        free(first);
        return NULL;
    }
    printf("[%d] Popped\n", first->data);
    first = first->next;
    return first;
}

void display(NODE first) {
    if (first == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    NODE cur = first;
    printf("Stack Elements are\n");
    while (cur != NULL) {
        printf("[%d]\n", cur->data);
        cur = cur->next;
    }
}

void main(){
    NODE first = NULL;
    int ch, item;
    while(1) {
        printf("Enter the choice:\n1.insertfront\n2.deletefront\n3.display\n4.exit\n");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
                printf("Enter item ");
                scanf("%d", &item);
                first = insert_front(first, item);
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