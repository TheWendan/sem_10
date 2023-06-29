#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "10.h"


int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./a.exe <name> -o asc/desc\n");
        return 1;
    }
    char* name = argv[1];
    char* sorting = "asc";  
    if (argc > 2) {
        if (strcmp(argv[2], "-o") == 0) {
            if (argc > 3) {
                sorting = argv[3];
            } else {
                printf("Usage: ./a. <name> -o asc/desc\n");
                return 1;}
        } else {
            printf("Usage: ./a <name> -o asc/desc\n");
            return 1;}
    }
    FILE* file = fopen(name, "r");
    if (file == NULL) {
        printf("Error: %s\n", name);
        return 1;
    }
    char arr[100];
    struct Node* treenode = NULL;
    while (fscanf(file, "%s", arr) == 1) {
        treenode = Enter(treenode, arr);
    }
    fclose(file);
    if (strcmp(sorting, "asc") == 0) {
        ASC(treenode);
    } else if (strcmp(sorting, "desc") == 0) {
        DESC(treenode);} 
    else {
        printf("Error sort: %s\n", sorting);
    }
    return 0;
}