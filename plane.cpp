#include <stdio.h>
#include <stdlib.h>

#include "plane.h"

void addPassenger(Plane *in)
{


}

void freePlane(Plane *in)
{


}

void readPlane(Plane *in, FILE *fp)
{
  fscanf(fp, "%d %d %d", &(in->rows), &(in->width), &(in->reserved));

}

void writePlane(Plane *in, FILE *fp)
{


}

void showGrid(Plane *in)
{


}
