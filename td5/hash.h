typedef struct
{
    char *name;
    int age;
    char *email;
} Person;


typedef struct
{
    Person **person;
    int size;
} Hashtable;


void init_hashtable(int size, Hashtable *table);

void add_person(Hashtable *table, Person person);

void find_person(Hashtable table, Person person);

void remove_person(Hashtable *table, Person person);

void free_hashtable(Hashtable *table);