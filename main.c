#include <stdio.h>
#include <stdlib.h>

#define M 9 // Tamanho da tabela hash

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

int hashFunction(int key) {
    return (2 * key + 5) % M;
}

void insert(Node* hashTable[], int key) {
    int index = hashFunction(key);
    Node* newNode = createNode(key);

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node* currNode = hashTable[index];
        while (currNode->next != NULL) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
}

void displayTable(Node* hashTable[]) {
    for (int i = 0; i < M; i++) {
        printf("Slot %d: ", i);
        Node* currNode = hashTable[i];
        while (currNode != NULL) {
            printf("%d ", currNode->key);
            currNode = currNode->next;
        }
        printf("\n");
    }
}

int main() {
    Node* hashTable[M];
    for (int i = 0; i < M; i++) {
        hashTable[i] = NULL;
    }

    int keys[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; i++) {
        insert(hashTable, keys[i]);
    }

    displayTable(hashTable);

    return 0;
}
