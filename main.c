#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"
#include "stack.h"

int main(int argc, char **argv) {

  screen s;
  zbuffer zb;
  struct matrix * edges;
  struct matrix * polygons;
  struct stack * csystems;

  edges = new_matrix(4, 4);
  polygons = new_matrix(4, 4);
  csystems = new_stack();

  /* print_matrix(make_rotX(M_PI/4)); */
  /* printf("\n"); */
  /* print_matrix(make_rotY(M_PI/4)); */
  /* printf("\n"); */
  /* print_matrix(make_rotZ(M_PI/4)); */
  /* printf("\n"); */

  /*
    add_polygon(polygons,
	      0.0,344.0,0.0,
	      0.0,-2.0,0.0,
	      0.0,8.0,0.0);

  scanline_convert(polygons, 0, s, zb);
  */

  if ( argc == 2 )
    parse_file( argv[1], csystems, edges, polygons, s, zb );
  else
    parse_file( "stdin", csystems, edges, polygons, s, zb );

  free_matrix( edges );
  free_matrix( polygons );
  free_stack(csystems);
}
