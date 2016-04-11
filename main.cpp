#include <stdio.h>
#include <stdlib.h>

#include "flight.h"
#include "plane.h"
#include "utilities.h"

Flight readFlights(int *in);

int main(void)
{
  int numFlights;
  Flight *flights;
  *flights = readFlights(&numFlights);
  while(getChoice() != 0)
  {
    addPassenger(flights, numFlights);
  }//while
  writeFlights(flights, numFlights);
  exit(EXIT_SUCCESS);
}//main

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
