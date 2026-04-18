#ifndef __PILE_H__
#define __PILE_H__

#include <stdio.h>
#include <stdbool.h>
#include "coord.h"

typedef struct _stack_node
{
  coord val;
  struct _stack_node *suiv;
} StackNode;

typedef struct _stack
{
  StackNode *top;
  int nb_elem;
} Stack;

/**
 * Configuration :
 *
 *   0                     n           PILEMAX-1
 *   |                     |             |
 *   V                     V             V
 *  ---------------------------------------
 *  |*|*|*|*|*|*|*|*|*|*|*| | | | | | | | |
 *  ---------------------------------------
 *
 */

void stack_init(Stack *stack);

bool stack_empty(Stack *stack);

coord stack_peek(Stack *stack);

coord stack_pop(Stack *stack);

void stack_push(Stack *stack, coord e);

void free_stack(Stack *stack);

#endif
