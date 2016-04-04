/**
 * Main.cpp
 */
#include <stdio.h>
#include <stdlib.h>

#include "flight.h"
#include "plane.h"
#include "utilities.h"

Flight readFlights(int *in);
/*
 *  main routine
 */
int main(void)
{
  int numFlights;
  Flight *flights;
  *flights = readFlights(&numFlights);

  exit(EXIT_SUCCESS);
}

Flight readFlights(int *in)
{
  FILE *fp = fopen("reservations.txt", "r");
  fscanf(fp, "%d", in);
  Flight *temp = (Flight *)malloc(*in * sizeof(Flight));
  for(int i = 0; i < *in; i++)
  {
    readFlight(temp, fp);
  }//for loop
  fclose(fp);
  return *temp;
} //readFlights
