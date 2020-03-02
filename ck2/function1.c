#include "header1.h"
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#pragma warning(disable : 4996)  
#define SWAP(A, B) { A = A + B; B = A - B; A = A - B; }
void Print(int size, int* mas)
{
  int i = 0;
  printf("N = %d\n", size);
  for (i = 0; i < size; i++)
    printf("m[%d] = %d\n", i, mas[i]);
}
void Readfile(FILE* f, int* size, int** mas)
{
  int i = 0, j=0;
  rewind(f); //перемотка файла в начало
  fscanf(f, "%d\n", size);
  *mas = (int*)malloc(*size * sizeof(int));
  for (i = 0; i < *size; i++)
	fscanf(f, "m[%d] = %d\n", &j, &((*mas)[i]));
}
void puzyrek(int size, int* mas)
{
  clock_t start, stop;
  start = clock();
  int s = 0, i = 0, j = 0;
  for (i = 0; i < size; i++)
	  for (j = 0; j < i; j++)
	  {
	    s = mas[i];
	    if (mas[i] > mas[j])
		  {
		    mas[i] = mas[j];
		    mas[j] = s;
		  }
	  }
  stop = clock();
  printf("Sortirovka proshla za %.6lf secund\n", (double)(stop - start) / CLOCKS_PER_SEC);
  free(mas);
}
void vstavka(int size, int* mas)
{
  clock_t start, stop;
  start = clock();
  int i = 0, j = 0;
  int t = 0;
  for (i = 1; i < size; i++)
  {
	j = i - 1;
	t = mas[i];
	while ((j >= 0) && (mas[j] < t))
	{
	  mas[j + 1] = mas[j];
	  j--;
	}
  mas[j + 1] = t;
  }
  stop = clock();
  printf("Sortirovka proshla za %.6lf secund\n", (double)(stop - start) / CLOCKS_PER_SEC);
  free(mas);
}
void timehoara(int* mas, int first, int last)
{
  int size = 0;
  clock_t start, stop;
  start = clock();
  size = last+1;
  hoara( mas, first, last);
  stop = clock();
  printf("Sortirovka proshla za %.6lf secund\n", (double)(stop - start) / CLOCKS_PER_SEC);
  free(mas);
}
void hoara( int* mash, int first, int last)
{
  int i = 0, j = 0;
  int tmp=0, x = 0;
  i = first;
  j = last;
  x = mash[(first + last) / 2];
  do 
  {
	while (mash[i] < x)
	  i++;
	while (mash[j] > x)
	  j--;
	if (i <= j)
	{
	  if (i < j)
	  {
		tmp = mash[i];
		mash[i] = mash[j];
		mash[j] = tmp;
	  }
	i++;
	j--;
	}
  } 
  while (i <= j);
  if (i < last)
	hoara(mash, i, last);
  if (first < j)
	hoara(mash, first, j);
}
