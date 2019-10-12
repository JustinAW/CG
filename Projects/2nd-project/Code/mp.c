#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
    

int main (int argc, char **argv)
{
    ht_t *ht = ht_create();

    ht_set(ht, 0.01, "Intake");
    ht_set(ht, 0.02, "Exhaust");
    ht_set(ht, 0.03, "Stator Housing");
    ht_set(ht, 0.04, "Chamber");
    ht_set(ht, 0.05, "Chamber");
    ht_set(ht, 0.06, "Chamber");
    ht_set(ht, 0.07, "Pinion");
    ht_set(ht, 0.08, "Rotor");
    ht_set(ht, 0.09, "Crown Gear");
    ht_set(ht, 0.10, "Eccentric Shafts");
    ht_set(ht, 0.11, "Spark Plug");
    ht_set(ht, 3.00, "Test");

    ht_dump(ht);

    return 0;
}
