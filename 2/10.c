#include "10.h"

// хэш функция
unsigned int Hash(const char *key) {
    unsigned int sum = 0;

    for (int i = 0; key[i]; i++) {
        sum += (unsigned char)key[i] * (i + 1);
    }
    return sum % MAX;
}

HashItem * getItem(HashItem *table[], const char *key) {
    HashItem **link = &table[Hash(key)];

    while (*link) {
        HashItem *tmp = *link;
        if (strcmp(tmp->key, key) == 0) {
            return tmp;
        } else {
            link = &(*link)->next;
        }
    }
    return NULL;
}

// функция добавления города
void addCity(HashItem *table[], const char *key, const int value) {
    HashItem *item = getItem(table, key);

    if (item == NULL) {
        unsigned int code = Hash(key);
        HashItem *item = malloc(sizeof(*item));

        if (item != NULL) {
            item->key = strdup(key);
            item->value = value;
            item->next = table[code];
            table[code] = item;
        }
    } else {
        item->value = value;
    }
}


// удаление города 
void delCity(HashItem *table[], const char *key) {
    HashItem **link = &table[Hash(key)];

    while (*link) {
        HashItem *tmp = *link;
        if (strcmp(tmp->key, key) == 0) {
            *link = tmp->next;  
            Clear(tmp);
            break;
        } else {
            link = &(*link)->next;
        }
    }
}

// печать хэш таблицы
void displayHashTable(HashItem *table[]) {
    for (int i = 0; i < MAX; i++) {
        for (HashItem *tmp = table[i]; tmp; tmp = tmp->next) {
            printf("%s %d\n", tmp->key, tmp->value);
        }
    }
    puts("");
}

void Clear(HashItem *item) {
    free(item->key);
    free(item);
}