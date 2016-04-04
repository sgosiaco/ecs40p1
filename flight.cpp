#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "flight.h"

void readFlight(Flight *in, FILE *fp)
{
  fscanf(fp, "%d", &(in->flightNum));
  fgets(in->origin, ORIGIN_MAX, fp);
  strtok(in->origin, "\n\r");
  fgets(in->destination, DEST_MAX, fp);
  strtok(in->destination, "\n\r");
  in->plane = (Plane *) malloc(sizeof(Plane));
  readPlane(in->plane, fp);
}

void addPassenger(Flight *in, int num)
{


}

void addPassenger(Flight *in)
{


}

void printFlightInfo(Flight *in)
{


}

void writeFlights(Flight *in, int num)
{


}

void writeFlight(Flight *in, FILE *fp)
{


}

void freeFlights(Flight *in, int num)
{


}

void freeFlight(Flight *in)
{


}
