#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "flight.h"

void readFlight(Flight *in, FILE *fp)
{
  fscanf(fp, "%d", &(in->flightNum));
  fgets(in->origin, AIRPORT_MAX, fp);
  strtok(in->origin, "\n\r");
  fgets(in->destination, AIRPORT_MAX, fp);
  strtok(in->destination, "\n\r");
  in->plane = (Plane *) malloc(sizeof(Plane));
  readPlane(in->plane, fp);
}

void addPassenger(Flight *in, int num)
{


}

void addPassenger(Flight *in)
{
  addPassenger(in->plane);
}

void printFlightInfo(Flight *in)
{
  printf("%-4d %-20s %s\n", in->flightNum, in->origin, in->destination);
}

void writeFlights(Flight *in, int num)
{
  FILE *fp = fopen("reservations2.txt", "w");
  fprintf(fp,"%d", num);
  for(int i = 0; i < num; i++)
  {
    writeFlight(in+i, fp);
  }
  fclose(fp);
}

void writeFlight(Flight *in, FILE *fp)
{
  fprintf(fp, "%d\n%s\n%s\n", in->flightNum, in->origin, in->destination);
  writePlane(in->plane, fp);
}

void freeFlights(Flight *in, int num)
{
  for(int i = 0; i < num; i++)
  {
    freeFlight(in+i);
  }
  free(in);
}

void freeFlight(Flight *in)
{


}
