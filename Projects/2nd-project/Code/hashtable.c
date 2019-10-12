/****************************************************
 *                  hashtable.c                     *
 ****************************************************
 *  Author:     Justin Weigle                       *
 *  Created:    10 Oct 2019                         *
 *  Edited:     11 Oct 2019                         *
 ****************************************************
 * Gives hash functionality using floating point    *
 * numbers for keys so that back buffer picking     *
 * can be accomplished in opengl                    *
 ****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>

// Define the number of entries the hash table can hold
// 301 allows for rgb values from 0.00 to 3.00
#define TABLE_SIZE 301

typedef struct entry_t {
    GLfloat key;
    char *value;
    struct entry_t *next;
} entry_t;

typedef struct {
    entry_t **entries;
} ht_t;


/****************************************************
 *                  ht_create                       *
 ****************************************************
 * Generates a hash table using entry_t and ht_t    *
 * structs                                          *
 * - returns: pointer to hash table                   *
 ****************************************************/
ht_t *ht_create(void)
{
    // allocate the table
    ht_t *hashtable = malloc(sizeof(ht_t) + 1);

    // allocate entries
    hashtable->entries = malloc(sizeof(entry_t*) * TABLE_SIZE);

    int i = 0;
    for (; i < TABLE_SIZE; i++)
    {
        hashtable->entries[i] = NULL;
    }

    return hashtable;
}


/****************************************************
 *                      hash                        *
 ****************************************************
 * "Hashes" a key to ensure all keys are uniquely   *
 * indexed                                          *
 * - returns: hashed value index                    *
 ****************************************************/
unsigned int hash (float key)
{
    // "hashing" can be very simple as there
    // will be all unique key values since
    // back buffer will have all unique colors
    // 0.00 can be used as background color
    // so it can always return NULL
    unsigned int value = key * 100;
    return value;
}


/****************************************************
 *                      ht_pair                     *
 ****************************************************
 * Allocates and creates a key value pair for the   *
 * hash table                                       *
 * - returns: pointer to entry_t struct of pair     *
 ****************************************************/
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


/****************************************************
 *                      ht_set                      *
 ****************************************************
 * Sets the value at a key as the provided key      *
 * value pair using ht_pair. If there is already a  *
 * value at a key, update that value to the new one *
 ****************************************************/
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


/****************************************************
 *                      ht_get                      *
 ****************************************************
 * Gets the value from the hash table at the given  *
 * key                                              *
 * - returns: char * to value                       *
 ****************************************************/
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


/****************************************************
 *                  ht_dump                         *
 ****************************************************
 * Helper function to display all the key value     *
 * pairs in the given hash table                    *
 ****************************************************/
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
            printf("%.2f = %s", entry->key, entry->value);

            if (entry->next == NULL)
            {
                break;
            }

            entry = entry->next;
        }
        printf("\n");
    }
}
