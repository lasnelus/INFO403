#include "hash.h"
#include <stdlib.h>
#include <string.h>

void init_hashtable(int size, Hashtable *table)
{
    table->size = size;
    table->person = malloc(size * sizeof(Person *));

    for(int i =0; i<size; i++)
    {
        table->person[i] = NULL;
    }
}

int hash(char *key, int size)
{
    int hash=0;
    for(int i=0; key[i]!= '\0'; i++)
    {
        hash += key[i];
    }
    return hash % size;
}

Person *create_person(char *name, int age, char *email)
{
    Person *person = (Person *)malloc(sizeof(Person));
    person->age = age;
    person->name = strdup(name);
    person->email = strdup(email);
    return person;
}


void add_person(Hashtable *table, char *name, int age, char *email)
{
    int index = hash(name, table->size);
    Person *person = create_person(name, age, email);
    table->person[index] = person;
}


Person *find_person(Hashtable table, char *name)
{
    int index = hash(name, table.size);
    return table.person[index];
}

void remove_person(Hashtable *table, char *name)
{
    Person *person = find_person(*table, name);
    free_person(person);
}

void free_person(Person *person)
{
    free(person->name);
    free(person->email);
}

void free_hashtable(Hashtable *table)
{
    free(table);
}

// bool placed = false;
//     while(!placed)
//     {
//         if (table.person[hash] = NULL)
//         {
//             placed = true;
//             table->person[hash] = person;
//         }else
//         {
//             hash = (hash + 1)%table.size;
//         }
//     }