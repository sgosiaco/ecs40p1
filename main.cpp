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
  Flight *temp = 0;
  return *temp;
}
