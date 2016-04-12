#ifndef PLANE_H
#define PLANE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilities.h"

#define NAME_M 80

typedef struct
{
  int rows;
  int width;
  int reserved;
  char ***passengers;
} Plane;

int addPassenger(Plane *in);
int getRow(Plane *in);
void freePlane(Plane *in);
void readPlane(Plane *in, FILE *fp);
void writePlane(Plane *in, FILE *fp);
void showGrid(Plane *in);

#endif
