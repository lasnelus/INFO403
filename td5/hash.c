#include "hash.h"
#include <stdlib.h>

void init_hashtable(int size, Hashtable *table)
{
    table->size = size;
    table->person = malloc(size * sizeof(Person *));
} 