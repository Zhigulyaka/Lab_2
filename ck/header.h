#ifndef _HEADER_H_
#define _HEADER_H_
#include <stdio.h>

void Createmas(int size, int** m);
void Fullmas(int size, int* m, int maxa, int mina);
void Print(int size, int* m);
void PrintFile(FILE* f, int size, int* m);

#endif
