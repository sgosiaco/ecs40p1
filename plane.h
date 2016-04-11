#ifndef PLANE_H
#define PLANE_H

#include <stdio.h>

typedef struct
{
  int rows;
  int width;
  int reserved;
  char ***passengers; // 2-dimensional
} Plane;

int addPassenger(Plane *in);
void freePlane(Plane *in);
void readPlane(Plane *in, FILE *fp);
void writePlane(Plane *in, FILE *fp);
void showGrid(Plane *in);

#endif
