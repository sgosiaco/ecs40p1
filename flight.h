#ifndef FLIGHT_H
#define FLIGHT_H

#include <stdio.h>
#include "plane.h"

#define ORIGIN_MAX 20
#define DEST_MAX 20

typedef struct
{
  int flightNum;
  char origin[ORIGIN_MAX];
  char destination[DEST_MAX];
  Plane *plane;
} Flight;

void readFlight(Flight *in, FILE *fp);
void addPassenger(Flight *in, int num);
void printFlightInfo(Flight *in);
void addPassenger(Flight *in);
void writeFlights(Flight *in, int num);
void writeFlight(Flight *in, FILE *fp);
void freeFlights(Flight *in, int num);
void freeFlight(Flight *in);

#endif
