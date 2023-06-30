#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 100  // задаем размер хэш таблицы



// структура хэш элемента 
typedef struct HashItem {
    char *key;
    int value;
    struct HashItem *next;
} HashItem;

unsigned int Hash(const char *key);
HashItem * getItem(HashItem *table[], const char *key);
void addCity(HashItem *table[], const char *key, const int value);
void delCity(HashItem *table[], const char *key);
void displayHashTable(HashItem *table[]);
void Clear(HashItem *item);