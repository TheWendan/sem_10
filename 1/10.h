#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    char* arr;
    int frequency;
    struct Node* left;
    struct Node* right;
};



void DESC(struct Node* treenode);
void ASC(struct Node* treenode);
struct Node* Enter(struct Node* treenode, char* arr);
struct Node* create(char* arr);