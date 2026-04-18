#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void stack_init(Stack *p)
{
  p->top = NULL;
  p->nb_elem = 0;
}

bool stack_empty(Stack *p)
{
  return p->top == NULL;
}

coord stack_peek(Stack *p)
{
  if (stack_empty(p))
  {
    printf("stack_peek : pile vide\n");
    exit(EXIT_FAILURE);
  }

  return p->top->val;
}

coord stack_pop(Stack *p)
{
  if (stack_empty(p))
  {
    printf("stack_pop : pile vide\n");
    exit(EXIT_FAILURE);
  }

  StackNode *node = p->top;
  coord valeur = node->val;
  p->top = node->suiv;
  free(node);
  p->nb_elem -= 1;
  return valeur;
}

void stack_push(Stack *p, coord e)
{
  StackNode *node = malloc(sizeof *node);
  if (node == NULL)
  {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  node->val = e;
  node->suiv = p->top;
  p->top = node;
  p->nb_elem += 1;
}

void free_stack(Stack *p)
{
  while (!stack_empty(p))
    stack_pop(p);

  p->top = NULL;
  p->nb_elem = 0;
}
