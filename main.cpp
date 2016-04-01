/*
 * WORDS -
 *
 * Usage: words
 *
 * Inputs: String from stdin
 * Output: Each word on it's own line prefaced by the line number and a tab
 *         Ex: 1 The
 *
 * Exit Code: EXIT_SUCCESS (0) because all goes well
 *
 * Written for ECS 030, Fall 2015
 *
 * Sean Gosiaco, Oct. 26, 2015
 * original program written
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "flight.h"
#include "plane.h"
#include "utilities.h"

typedef struct
{
  int rows;
  int width;
  int reserved;
  char ***passengers; // 2-dimensional
} Plane;

typedef struct
{
  int flightNum;
  char origin[20];
  char destination[20];
  Plane *plane;
} Flight;

/*
 *  main routine
 */
int main(void)
{
  int numFlights;
  Flight *flights;

  exit(EXIT_SUCCESS);
}
