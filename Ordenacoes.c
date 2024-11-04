#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"

void append(Node** headRef, int newData) {
    Node* newNode = createNode(newData);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    Node* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(",");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    append(&head, 4);
    append(&head, 2);
    append(&head, 5);
    append(&head, 3);
    append(&head, 1);

    printf("Lista original: ");
    display(head);

    bubbleSort(head);
    printf("Lista apos Bubble Sort: ");
    display(head);

    head = NULL;
    append(&head, 4);
    append(&head, 2);
    append(&head, 5);
    append(&head, 3);
    append(&head, 1);
    
    head = insertionSort(head);
    printf("Lista apos Insertion Sort: ");
    display(head);

    head = NULL;
    append(&head, 4);
    append(&head, 2);
    append(&head, 5);
    append(&head, 3);
    append(&head, 1);

    head = mergeSort(head);
    printf("Lista apos Merge Sort: ");
    display(head);

    head = NULL;
    append(&head, 4);
    append(&head, 2);
    append(&head, 5);
    append(&head, 3);
    append(&head, 1);

    quickSort(&head);
    printf("Lista apos Quick Sort: ");
    display(head);

    return 0;
}
