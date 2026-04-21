typedef struct
{
    char *name;
    int age;
    char *email;
} Person;


typedef struct
{
    Person** personne;
    int size;
} Hashtable;


Hashtable init_hashtable(int size);

void add_person(Hashtable *table, Person personne);

void find_person(Hashtable table, Person personne);

void remove_person(Hashtable *table, Person personne);

void free_hashtable(Hashtable *table);