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

coord stack_pop(Stack *p)
{
  if (stack_empty(p))
  {
    fprintf(stderr, "stack_pop on empty stack\n");
    exit(EXIT_FAILURE);
  }

  StackNode *node = p->top;
  coord value = node->value;
  p->top = node->next;
  free(node);
  p->nb_elem -= 1;
  return value;
}

void stack_push(Stack *p, coord e)
{
  StackNode *node = malloc(sizeof *node);
  if (node == NULL)
  {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  node->value = e;
  node->next = p->top;
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
