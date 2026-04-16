#ifndef __PILE_H__
#define __PILE_H__

#include <stdio.h>
#include <stdbool.h>
#include "coord.h"

#define PILEMAX 100

typedef struct _stack
{
  coord liste[PILEMAX];
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

coord stack_pop(Stack *stack);

void stack_push(Stack *stack, coord e);

#endif
