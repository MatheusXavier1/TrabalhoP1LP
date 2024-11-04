#ifndef SORTS_H
#define SORTS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data);
void quickSort(Node** inicioRef);
Node* particiona(Node* inicio, Node** novoInicio, Node** novoFim);
Node* insertionSort(Node* inicio);
void bubbleSort(Node* inicio);
Node* mergeSort(Node* inicio);
Node* merge(Node* left, Node* right);

#endif

Node* createNode(int data) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->data = data;
    novoNode->next = NULL;
    return novoNode;
}

Node* particiona(Node* inicio, Node** novoInicio, Node** novoFim) {
    Node* pivo = inicio;
    Node* prev = NULL;
    Node* curr = inicio;
    Node* fim = pivo;

    while (curr != pivo) {
        if (curr->data < pivo->data) {
            if (*novoInicio == NULL) {
                *novoInicio = curr;
            }
            prev = curr;
            curr = curr->next;
        } else {
            if (prev) {
                prev->next = curr->next;
            }
            Node* temp = curr->next;
            curr->next = NULL;
            fim->next = curr;
            fim = curr;
            curr = temp;
        }
    }

    if (*novoInicio == NULL) {
        *novoInicio = pivo;
    }

    *novoFim = fim;
    return pivo;
}

void quickSort(Node** inicioRef) {
    Node* inicio = *inicioRef;
    if (!inicio || !inicio->next) {
        return;
    }

    Node* novoInicio = NULL;
    Node* novoFim = NULL;
    Node* pivo = particiona(inicio, &novoInicio, &novoFim);

    if (novoInicio != pivo) {
        Node* temp = novoInicio;
        while (temp->next != pivo) {
            temp = temp->next;
        }
        temp->next = NULL;

        quickSort(&novoInicio);
        temp = novoInicio;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = pivo;
    }

    quickSort(&pivo->next);
    *inicioRef = novoInicio;
}

Node* insertionSort(Node* inicio) {
    if (!inicio || !inicio->next) {
        return inicio;
    }

    Node* sorted = NULL;

    while (inicio != NULL) {
        Node* current = inicio;
        inicio = inicio->next;

        if (!sorted || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    return sorted;
}

void bubbleSort(Node* inicio) {
    int swapped;
    Node* ptr1;
    Node* ultimo = NULL;

    if (inicio == NULL) return;

    do {
        swapped = 0;
        ptr1 = inicio;

        while (ptr1->next != ultimo) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ultimo = ptr1;
    } while (swapped);
}

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* merged = NULL;

    if (left->data <= right->data) {
        merged = left;
        merged->next = merge(left->next, right);
    } else {
        merged = right;
        merged->next = merge(left, right->next);
    }
    return merged;
}

Node* mergeSort(Node* inicio) {
    if (!inicio || !inicio->next) {
        return inicio;
    }

    Node* mid = inicio;
    Node* fast = inicio->next;

    while (fast && fast->next) {
        mid = mid->next;
        fast = fast->next->next;
    }

    Node* left = inicio;
    Node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}
