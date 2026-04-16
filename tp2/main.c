#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "maze.h"
#include "coord.h"
#include "stack.h"


void solve(maze *m)
{
  (void)m; // Supprimez cette ligne !
  // Exo 3
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
    temp.x = c.x -1;
    temp.y = c.y;
    set_tag(m, temp, "o");
  }
  if(neig.east){
    temp.x = c.x;
    temp.y = c.y+1;
    set_tag(m, temp, "o");
  }
  if(neig.south){
    temp.x = c.x +1;
    temp.y = c.y;
    set_tag(m, temp, "o");
  }
  if(neig.west){
    temp.x = c.x;
    temp.y = c.y-1;
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
  coord c;
  c.x = 1;
  c.y = 3;

  init_maze(&m, w, h);
  mark_neighboors(&m, c);
  print_maze(&m);
  free_maze(&m);

  return 0;
}


