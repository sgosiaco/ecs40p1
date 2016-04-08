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
  in->passengers = (char ***) malloc((in->rows * sizeof(char *)) + (in->width *  sizeof(char )));
  *(in->passengers) = (char **) malloc(in->rows * sizeof(char *));
  for(int i = 0; i < in->rows; i++)
  {
    *(in->passengers)[i] = (char *)malloc(in->width * sizeof(char));
  }
}

void writePlane(Plane *in, FILE *fp)
{


}

void showGrid(Plane *in)
{
  printf("ROW# ");
  for(int i = 0; i < in->width; i++)
  {
    putchar(i+'A');
  }
  putchar('\n');
  for(int k = 0; k < in->rows; k++)
  {
    printf("%2d   ", k+1);
    for(int j = 0; j < in->width; j++)
    {

    }
  }
}
