#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "maze.h"
#include "coord.h"
#include "stack.h"




bool solve_rec(maze *m, coord c, Stack *p)
{
    coord prev;
    bool hasPrev = !stack_empty(p);

    if (hasPrev)
    {
      prev = p->liste[p->nb_elem - 1];
    }
    stack_push(p, c);

    if (is_target(m, c))
    {
      return true;
    }
    neighboors neig = list_neighboors(m, c);
    coord temp;

    if (neig.north)
    {
        temp.x = c.x;
        temp.y = c.y - 1;
        if (!hasPrev || !equal(temp, prev))
            if (solve_rec(m, temp, p))
                return true;
    }
    if (neig.east)
    {
        temp.x = c.x + 1;
        temp.y = c.y;
        if (!hasPrev || !equal(temp, prev))
            if (solve_rec(m, temp, p))
                return true;
    }
    if (neig.south)
    {
        temp.x = c.x;
        temp.y = c.y + 1;
        if (!hasPrev || !equal(temp, prev))
            if (solve_rec(m, temp, p))
                return true;
    }
    if (neig.west)
    {
        temp.x = c.x - 1;
        temp.y = c.y;
        if (!hasPrev || !equal(temp, prev))
            if (solve_rec(m, temp, p))
                return true;
    }

    stack_pop(p);
    return false;
}


void solve(maze *m)
{
    Stack p;
    coord c;
    bool r;

    stack_init(&p);

    c.x = m->origin->x;
    c.y = m->origin->y;

    r = solve_rec(m, c, &p);
    if (r)
    {
        for (int i = 0; i < p.nb_elem; i++)
            set_tag(m, p.liste[i], "o");
    }
    else
    {
        printf("Impossible d'atteindre la sortie !!!");
    }
}

void usage(const char *name)
{
  fprintf(stderr, "Usage : %s w h\n", name);
  fprintf(stderr, "Affiche un labyrinthe de dimension w x h\n");
  fprintf(stderr, "Options :\n");
  fprintf(stderr, " w : largeur du labyrinthe\n");
  fprintf(stderr, " h : hauteur du labyrinthe\n");
}

void mark_neighboors(maze *m, coord c)
{
  coord temp;
  neighboors neig = list_neighboors(m, c);
  set_tag(m, c, "x");
  if(neig.north){
    temp.x = c.x;
    temp.y = c.y-1;
    set_tag(m, temp, "o");
  }
  if(neig.east){
    temp.x = c.x+1;
    temp.y = c.y;
    set_tag(m, temp, "o");
  }
  if(neig.south){
    temp.x = c.x ;
    temp.y = c.y+1;
    set_tag(m, temp, "o");
  }
  if(neig.west){
    temp.x = c.x-1;
    temp.y = c.y;
    set_tag(m, temp, "o");
  }
}



int main(int argc, char **argv)
{
  maze m;
  int w = (argc > 1 ? atoi(argv[1]) : 10);
  int h = (argc > 2 ? atoi(argv[2]) : 10);

  if (w < 0 || h < 0 || w * h < 2)
  {
    usage(argv[0]);
    exit(EXIT_FAILURE);
  }

  init_maze(&m, w, h);
  print_maze(&m);
  solve(&m);
  print_maze(&m);
  free_maze(&m);

  return 0;
}


