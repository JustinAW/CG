#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fl_hash.h"

int main (int argc, char **argv)
{
    ht_t *ht = ht_create();

    ht_set(ht, 0.01, "em");
    ht_set(ht, 0.02, "eden");
    ht_set(ht, 0.03, "pyro");
    ht_set(ht, 0.04, "alaska");
    ht_set(ht, 0.05, "arch");
    ht_set(ht, 0.06, "dave");
    ht_set(ht, 0.07, "gear");

    ht_dump(ht);

    return 0;
}
