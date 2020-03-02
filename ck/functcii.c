#include "header.h"
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996)
void Createmas(int size, int** m)
{
  if (size > 0)
	*m = (int*)malloc(size * sizeof(int));
}
void Fullmas(int size, int* m, int maxa, int mina)
{
  int i = 0;
  for (i = 0; i < size; i++)
  {
	m[i] = rand() % (maxa - mina) + mina;
  }
}
void Print(int size, int* m)
{
  int i = 0;
  printf("N = %d\n", size);
  for (i = 0; i < size; i++)
	printf("m[%d] = %d\n", i, m[i]);
}
void PrintFile(FILE* f, int size, int* m)
{
  int i = 0;
  fprintf(f, "%d\n", size);
  for (i = 0; i < size; i++)
	fprintf(f, "m[%d] = %d\n", i, m[i]);
}