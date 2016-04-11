#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "plane.h"
#include "utilities.h"

int addPassenger(Plane *in)
{
  char name[80];
  int row = 0;
  int col = 0;
  if (in->reserved == (in->rows) * (in->width))
    return 1;
  else {
    printf("Please enter the name of the passenger: ");
    fgets(name, 80, stdin);
    strtok(name, "\n\r");
    showGrid(in);
    do {
      do {
        do {
          printf("\nPlease enter the row of the seat you wish to reserve: ");
          row = getNumber();
          if ((row <= 0) || (in->rows < row)) {
            printf("There is no row #%d on this flight.\nPlease try again.\n", row);
          }
        } while (row <= 0);
        if (in->rows >= row)
          break;
        else
          continue;
      } while (true);
      printf("Please enter the seat letter you wish to reserve: ");
      col = getchar() - 'A';
      if (*(in->passengers)[row][col] == 0x0)
        break;
      printf("That seat is already occupied.\nPlease try again.\n");
    } while (true);
    (in->passengers)[row][col] = (char *) malloc(strlen(name) + 1);
    strcpy((in->passengers)[row][col], name);
    in->reserved++;
    return 0;
  }
}

void freePlane(Plane *in)
{
  for (int i = 0; i < in->rows; i++) {
    for (int j = 0; j < in->width; j++) {
      if ((in->passengers)[i][j] != 0x0) {
        free((in->passengers)[i][j]);
      }
    }
    free((in->passengers)[i]);
  }
  free(in->passengers);
}//freePlane

void readPlane(Plane *in, FILE *fp)
{
  fscanf(fp, "%d %d %d", &(in->rows), &(in->width), &(in->reserved));
  (in->passengers) = (char ***) malloc(in->rows * sizeof(char **));

  for(int i = 0; i < in->rows; i++)
  {
    (in->passengers)[i] = (char **)malloc(in->width * sizeof(char *));

    for(int k = 0; k < in->width; k++)
    {
      (in->passengers)[i][k] = 0;
    }
  }//for
  int res = 0;
  char name[80];
  int row = 0;
  char col = '0';
  do {
    if (in->reserved <= res) {
      break;
    }
    fscanf(fp, "%d%c ", &row, &col);
    fgets(name, 80, fp);
    strtok(name, "\r\n");
    (in->passengers)[row-1][col-'A'] = (char *)malloc(strlen(name) + 1);
    strcpy((in->passengers)[row-1][col-'A'], name);
    res++;
  } while (true);
}//readPlane

void writePlane(Plane *in, FILE *fp)
{
  fprintf(fp, "%d %d %d\n", in->rows, in->width, in->reserved);
  int row = 0;
  do {
    if (in->rows <= row) {
      break;
    }
    for (int i = 0; i < in->width; i++)
    {
      if ((in->passengers)[row][i] != 0x0) {
        fprintf(fp, "%d%c %s\n", row + 1, i + 'A', (in->passengers)[row][i]);
      }
    }
    row++;
  } while (true);
}//writePlane

void showGrid(Plane *in)
{
  printf("ROW# ");

  for(int i = 0; i < in->width; i++)
  {
    putchar(i + 'A');
  }//for

  putchar('\n');

  for(int k = 0; k < in->rows; k++)
  {
    printf("%2d   ", k + 1);

    for(int j = 0; j < in->width; j++)
    {
      if((in->passengers)[k][j] != 0)
        putchar('X');
      else
        putchar('-');
    }//for
    putchar('\n');
  }//for
  printf("\nX = reserved.\n");
}//showGrid
