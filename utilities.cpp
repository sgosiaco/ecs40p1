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
  for(int i = 0; i < strlen(line); i++)
  {
    if(isalpha(line[i]))
    {
      num = -1;
      break;
    }//if
  }//for
  if(num > INT_MAX || num < INT_MIN)
  return -1;
  return num;
}//getNumber

int getNumber2()
{
  long num = 0;
  char c = getchar();
  while(isspace(c) != 0)
  {
    c = getchar();
  }//while
  while(true)
  {
    if(c > 47 && c < 58 && num != -1)
    {
      num = (num * 10) + c - '0';
      c = getchar();
    }//if
    else
    {
      num = -1;
    }
    if(c == EOF || c == '\n')
    {
      break;
    }//if
  }//while
  if(num < INT_MAX && num > INT_MIN)
  {
    return num;
  }
  return -1;
}//getNumber2

int getChoice()
{
  int in = 0;
  puts("\nECS Flight Reservation Menu");
  puts("0. Exit.");
  puts("1. Add Passenger.");
  do
  {
    printf("\nPlease enter your choice: ");
    in = getNumber();
    if (in == -1)
    {
      puts("Your choice is invalid.");
      puts("Please try again.");
    }//if
    else
    {
      if ((in < 0) || (in > 1))
      {
        printf("%d is not an available choice.\n", in);
        puts("Please try again.");
      }//if
    }//else
  } while ((in < 0) || (in > 1));
  if (in != -1) {
    if (in == 0) {
      puts("Goodbye.");
    }//if
  }//if
  return in;
}//getChoice
