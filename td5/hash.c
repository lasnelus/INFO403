void main (void)
{

}

void init_hashtable(int size, hashtable *table)
{
    table->size = size;
    table->person = malloc(size * sizeof(Person *));
} 