#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "10.h"



int main() {
    HashItem *table[MAX] = { 0 };

    char command, town[51];
    int population;
    while (1){
        printf("1. Add city\n");
        printf("2. Delete city\n");
        printf("3. Show list of cities\n");
        printf("4. Exit\n");
        printf("Choose operation: ");
        scanf("%d",&command);
        switch (command) {
            case 1:
                printf("\nEnter the name of city: ");
                scanf("%s", town);
                printf("\nEnter the population of city: ");
                scanf("%i", &population);
                addCity(table, town, population);
                break;
            case 2:
                printf("Enter the name of deleting city: ");
                scanf("%s", town);
                delCity(table, town);
                break;
            case 3: {
                printf("\nThe list cities:\n");
                displayHashTable(table);
                break;
            }
            case 4:
                sleep(1.5);
                exit(0);
            default:
                puts("Unknown command. Try again.");
                break;
        }
    }
    return 0;
}