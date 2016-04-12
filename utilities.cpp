#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

#include "utilities.h"

int getNumber()
{
  char buf[1024];
  char *line;
  long num = 0;
  fgets(buf, 1024, stdin);

  if(buf[strlen(buf) - 1] == '\n')
    buf[strlen(buf) - 1] = '\0';
  num = strtol(buf, &line, 10);

  for(int i = 0; i < (int)strlen(line); i++)
  {
    if(isalpha(line[i]))
    {
      num = ERR;
      break;
    }//if
  }//for

  if(num > INT_MAX || num < INT_MIN || num < 0)
    return ERR;
  return num;
}//getNumber

int getChoice()
{
  int in = 0;
  printf("\nECS Flight Reservation Menu\n");
  printf("0. Exit.\n");
  printf("1. Add Passenger.\n");

  do
  {
    printf("\nPlease enter your choice: ");
    in = getNumber();

    if (in == ERR)
    {
      printf("Your choice is invalid.\nPlease try again.\n");
    }//if
    else//not 0 or 1
    {
      if ((in < 0) || (in > 1))
      {
        printf("%d is not an available choice.\n", in);
        printf("Please try again.\n");
      }//if
    }//else
  } while ((in < 0) || (in > 1));

  if (in != ERR)
  {
    if (in == 0)
    {
      printf("Goodbye.\n");
    } //if
  } //if

  return in;
} //getChoice
