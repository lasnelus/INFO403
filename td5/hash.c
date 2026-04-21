#include "hash.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


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
    bool is_free = table->person[index] == NULL || table->person[index] == REMOVED;
    while(!is_free)
    {
        index = (index+1) % table->size;
        is_free = table->person[index] == NULL || table->person[index] == REMOVED;
    }
    table->person[index] = person;
}


Person *find_person(Hashtable table, char *name)
{
    int index = hash(name, table.size);
    bool found = false;
    Person *person = NULL;
    while (!found && (table.person[index] != NULL))
    {
        Person *p = table.person[index];
        if(p != NULL && p != REMOVED && strcmp(p->name, name) ==0)
        {
            found = true;
            person = p;
        }
        index = (index+1) % table.size;
    }

    return person;
}

void remove_person(Hashtable *table, char *name)
{
    int index = hash(name, table->size);
    Person *person = find_person(*table, name);
    if(person != NULL)
    {
        free_person(person);
        table->person[index] = NULL;
    }
}

void free_person(Person *person)
{
    free(person->name);
    free(person->email);
    free(person);
}

void free_hashtable(Hashtable *table)
{
    for(int i=0; i<table->size; i++)
    {
        Person *person = table->person[i];
        if(person != NULL)
        {
            free_person(person);
        }
    }
    free(table->person);
}

