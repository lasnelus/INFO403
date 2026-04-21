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

int hash(char *key, int size);

Person *create_person(char *name, int age, char *email);

void add_person(Hashtable *table, char *name, int age, char *email);

Person *find_person(Hashtable table, char *name);

void remove_person(Hashtable *table, Person person);

void free_hashtable(Hashtable *table);