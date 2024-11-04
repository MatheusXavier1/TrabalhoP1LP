#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* initList() {
    return NULL;
}

struct Node* removeDuplicates(struct Node* head) {
    if (head == NULL) return head;

    struct Node *atual = head;

    while (atual->next != NULL) {
        if (atual->data == atual->next->data) {
            struct Node *temp = atual->next;
            atual->next = temp->next;
            free(temp);
        } else {
            atual = atual->next;
        }
    }
    return head;
}

struct Node* createNode(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* atual = *head;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = newNode;
    }
}

void print(struct Node *head) {
    struct Node* atual = head;
    while (atual != NULL) {
        printf("%d, ", atual->data);
        atual = atual->next;
    }
}

int main() {
    struct Node* head = NULL;

    append(&head, 1);
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 3);

    printf("Lista original: \n");
    print(head);

    head = removeDuplicates(head);

    printf("Lista tratada: ");
    print(head);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
