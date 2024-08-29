#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void insert(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void printList() {
    if (head == NULL) return;
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    printList();
    return 0;
}
