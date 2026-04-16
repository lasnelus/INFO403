#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "maze.h"
#include "coord.h"
#include "stack.h"




bool solve_rec(maze *m, coord c, Stack *p)
{
  // À ce moment-ci, si la pile est non-vide, les coordonnées stack_pop
  // sur le dessus de p indiquent la case précédente.
  // Il ne faut surtout pas aller dans cette direction.
  // Le seul cas où la pile est vide est lorsqu'on est à
  // l'entrée du labyrinthe.
  // On ajoute la case actuelle sur la pile.

    coord prev;
    bool hasPrev = !stack_empty(p);

    if (hasPrev)
    {
      prev = stack_peek(p);
    }
    stack_push(p, c);

    if (is_target(m, c))
    {
      return true;
    }
    neighboors neig = list_neighboors(m, c);
    coord temp;

    // Si il y a une porte pour aller dans cette direction
    // ET que ce n'est pas la case précédente :

    if (neig.north)
    {
      //- Calculer les coordonnées de la case dans cette direction
      // et effectuer un appel récursif sur cette case.
      // - Si l'appel récursif a retourné vrai
      // alors retourner vrai (on a trouvé la sortie!).
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

    // Si on a testé toutes les directions et qu'aucune n'a mené à la sortie,
    // alors on dépile les coordonnées de la case actuelle et on retourne faux.
    stack_pop(p);
    return false;
}


void solve(maze *m, Stack *p)
{
    coord c;
    bool r;

    stack_init(p);

    c.x = m->origin->x;
    c.y = m->origin->y;

    r = solve_rec(m, c, p);
    if (r)
    {
        while (!stack_empty(p))
        {
            coord current = stack_pop(p);
            set_tag(m, current, "o");
        }
    }
    else
    {
        printf("Impossible d'atteindre la sortie !!!\n");
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
  Stack p;
  solve(&m, &p);
  free_stack(&p);
  print_maze(&m);
  free_maze(&m);

  return 0;
}


