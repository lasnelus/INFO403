#include "annuaire.h"
#include <string.h>

int hash(char *name, char *first_name) {
    int hash = 0;
    for (int i = 0; i < strlen(name); i++) {
       hash += name[i];
    }
    for (int i = 0; i < strlen(first_name); i++) {
        hash += first_name[i];
    }
    return hash % SIZE;
}
