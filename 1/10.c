#include "10.h"

void DESC(struct Node* treenode) {
    if (treenode != NULL) {
        DESC(treenode->right);
        printf("%s - %d\n", treenode->arr, treenode->frequency);
        DESC(treenode->left);
    }
}

void ASC(struct Node* treenode) {
    if (treenode != NULL) {
        ASC(treenode->left);
        printf("%s - %d\n", treenode->arr, treenode->frequency);
        ASC(treenode->right);
    }
}

// создание новго узла с данными слова и частоты появления
struct Node* create(char* arr) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->arr = strdup(arr);
    newNode->frequency = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Node* Enter(struct Node* treenode, char* arr) {
    if (treenode == NULL) {
        return create(arr);
    }
    if (strcmp(arr, treenode->arr) == 0) {
        treenode->frequency++;
    }
    else if (strcmp(arr, treenode->arr) < 0) {
        treenode->left = Enter(treenode->left, arr);
    }
    else {
        treenode->right = Enter(treenode->right, arr);
    }
    return treenode;
}