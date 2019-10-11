#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct entry_t {
    char *key;
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

unsigned int hash (const char* key)
{
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    for (; i < key_len; i++)
    {
        value = value * 37 + key[i];
    }

    value = value % TABLE_SIZE;

    return value;
}

entry_t *ht_pair(const char *key, const char *value)
{
    // allocate entry
    entry_t *entry = malloc(sizeof(entry) * 1);
    entry->key = malloc(strlen(key) + 1);
    entry->value = malloc(strlen(value) + 1);

    // copy key and value in place
    strcpy(entry->key, key);
    strcpy(entry->value, value);

    // next starts out NULL but may be set later on
    entry->next = NULL;

    return entry;
}

void ht_set(ht_t *hashtable, const char *key, const char *value)
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
        if (strcmp(entry->key, key) == 0)
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

char *ht_get(ht_t *hashtable, const char *key)
{
    unsigned int slot = hash(key);

    entry_t *entry = hashtable->entries[slot];

    if (entry == NULL)
    {
        return NULL;
    }

    while (entry != NULL)
    {
        if (strcmp(entry->key, key) == 0)
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
            printf("%s = %s", entry->key, entry->value);

            if (entry->next == NULL)
            {
                break;
            }

            entry = entry->next;
        }

        printf("\n");
    }
}

int main (int argc, char** argv)
{
    ht_t *ht = ht_create();
    

    ht_set(ht, "name1", "em");
    ht_set(ht, "name2", "eden");
    ht_set(ht, "name3", "pyro");
    ht_set(ht, "name4", "alaska");
    ht_set(ht, "name5", "arch");
    ht_set(ht, "name6", "dave");
    ht_set(ht, "name7", "gear");

    ht_dump(ht);

    return 0;
}
