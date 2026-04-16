#include <stdlib.h>
#include "stack.h"

void stack_init(Stack *p)
{
  p->nb_elem = 0;
}

bool stack_empty(Stack *p)
{
  return !(p->nb_elem > 0);
}

coord stack_pop(Stack *p)
{
  p->nb_elem = p->nb_elem-1;
  return p->liste[p->nb_elem];
}

void stack_push(Stack *p, coord e)
{
  p->liste[p->nb_elem] = e;
  p->nb_elem = p->nb_elem + 1;
}
