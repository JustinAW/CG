#ifndef HASH_H
#define HASH_H

typedef struct entry_t {
    float key;
    char *value;
    struct entry_t *next;
} entry_t;

typedef struct {
    entry_t **entries;
} ht_t;

ht_t *ht_create(void);

unsigned int hash(float);

entry_t *ht_pair(float, const char *);

void ht_set(ht_t *, float, const char *);

char *ht_get(ht_t *, float);

void ht_dump(ht_t *);

#endif
