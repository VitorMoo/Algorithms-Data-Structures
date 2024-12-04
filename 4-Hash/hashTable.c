#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

#define TABLE_SIZE 10

Node* hashTable[TABLE_SIZE];

// Função hash
int hash(int x) {
    return x % TABLE_SIZE;
}

void insert(int x) {
    int index = hash(x);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

int search(int x) {
    int index = hash(x);
    Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->data == x) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void display() {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        Node* temp = hashTable[i];
        printf("Índice %d:", i);
        while (temp != NULL) {
            printf(" %d ->", temp->data);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

void delete(int x) {
    int index = hash(x);
    Node* temp = hashTable[index];
    Node* prev = NULL;

    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Número %d não encontrado na tabela hash.\n", x);
        return;
    }

    if (prev == NULL) {
        hashTable[index] = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Número %d removido da tabela hash.\n", x);
}

int main() {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    insert(12);
    insert(22);
    insert(32);
    insert(42);
    insert(15);
    insert(25);
    insert(35);
    insert(45);
    insert(9);
    insert(19);
    insert(29);

    printf("Tabela Hash:\n");
    display();

    int num = 22;
    if (search(num)) {
        printf("Número %d encontrado na tabela hash.\n", num);
    } else {
        printf("Número %d não encontrado na tabela hash.\n", num);
    }

    delete(22);

    printf("\nTabela Hash após remoção:\n");
    display();

    if (search(num)) {
        printf("Número %d encontrado na tabela hash.\n", num);
    } else {
        printf("Número %d não encontrado na tabela hash.\n", num);
    }

    return 0;
}
