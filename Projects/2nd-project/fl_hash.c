#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct entry_t {
    float key;
    char *value;
    struct entry_t *next;
} entry_t;

typedef struct {
    entry_t **entries;
} ht_t;

ht_t *ht_create(void)
{
    // allocate the table
    ht_t *hashtable = malloc(sizeof(ht_t) * 1);

    // allocate entries
    hashtable->entries = malloc(sizeof(entry_t*) * TABLE_SIZE);

    int i = 0;
    for (; i < TABLE_SIZE; i++)
    {
        hashtable->entries[i] = NULL;
    }

    return hashtable;
}

unsigned int hash (float key)
{
    // "hashing" can be very simple as there
    // will not be anywhere near 100 unique
    // colors for picking in this project
    unsigned int value = key * 100;
    return value;
}

entry_t *ht_pair(float key, const char *value)
{
    // allocate entry
    entry_t *entry = malloc(sizeof(entry) + 1);
    entry->value = malloc(strlen(value) + 1);

    entry->key = key;
    strcpy(entry->value, value);

    // next starts out NULL but may be set later on
    entry->next = NULL;

    return entry;
}

void ht_set(ht_t *hashtable, float key, const char *value)
{
    unsigned int slot = hash(key);

    // try to look up an entry
    entry_t *entry = hashtable->entries[slot];

    // no entry means the slot is empty, insert
    if (entry == NULL)
    {
        hashtable->entries[slot] = ht_pair(key, value);
        return;
    }

    entry_t *prev;

    // walk through each entry until the end or a matching key is found
    while (entry != NULL)
    {
        // check key
        if (entry->key == key)
        {
            free(entry->value);
            entry->value = malloc(strlen(value) + 1);
            strcpy(entry->value, value);
            return;
        }

        // go to next
        prev = entry;
        entry = prev->next;
    }

    // end reached without a key match, add new
    prev->next = ht_pair(key, value);
}

char *ht_get(ht_t *hashtable, float key)
{
    unsigned int slot = hash(key);

    entry_t *entry = hashtable->entries[slot];

    if (entry == NULL)
    {
        return NULL;
    }

    while (entry != NULL)
    {
        if (entry->key == key)
        {
            return entry->value;
        }
        
        entry = entry->next;
    }

    return NULL;
}

void ht_dump(ht_t *hashtable)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        entry_t *entry = hashtable->entries[i];

        if (entry == NULL)
        {
            continue;
        }

        printf("slot[%4d]: ", i);

        for(;;)
        {
            printf("%f = %s", entry->key, entry->value);

            if (entry->next == NULL)
            {
                break;
            }

            entry = entry->next;
        }

        printf("\n");
    }
}
/*
int main (int argc, char** argv)
{
    ht_t *ht = ht_create();
    

    ht_set(ht, 0.01, "em");
    ht_set(ht, 0.02, "eden");
    ht_set(ht, 0.03, "pyro");
    ht_set(ht, 0.04, "alaska");
    ht_set(ht, 0.05, "arch");
    ht_set(ht, 0.06, "dave");
    ht_set(ht, 0.07, "gear");

//    ht_dump(ht);
    char * out = ht_get(ht, 0.05);
    printf("My OS: %s\n", out);

    return 0;
}
*/
