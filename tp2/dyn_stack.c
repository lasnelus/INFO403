#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void stack_init(Stack *p)
{
  p->nb_elem = 0;
  p->capacity = 2;
  p->liste = malloc(p->capacity * sizeof(coord));
  if (p->liste == NULL)
  {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
}

bool stack_empty(Stack *p)
{
  return p->nb_elem == 0;
}

coord stack_pop(Stack *p)
{
  p->nb_elem -= 1;
  return p->liste[p->nb_elem];
}

void stack_push(Stack *p, coord e)
{
  if (p->nb_elem >= p->capacity)
  {
    int new_capacity = p->capacity * 2;
    coord *new_list = realloc(p->liste, new_capacity * sizeof(coord));
    if (new_list == NULL)
    {
      perror("realloc");
      exit(EXIT_FAILURE);
    }
    p->liste = new_list;
    p->capacity = new_capacity;
  }

  p->liste[p->nb_elem] = e;
  p->nb_elem += 1;
}

void free_stack(Stack *p)
{
  free(p->liste);
  p->liste = NULL;
  p->nb_elem = 0;
  p->capacity = 0;
}
