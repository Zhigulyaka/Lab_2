#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996)
int main(int argc, char* argv[])
{
  int size = 0, i = 0;
  int* mas = 0;
  FILE* f;
  char line[10];
  if (argc < 2)
	{
	  printf("Error\n");
	  return 1;
	}
  f = fopen(argv[1], "r");
  Readfile(f, &size, &mas);
  Print(size, mas);
  srand(time(NULL));
  while (1)
  {
	printf("Vyberite: pusyrek, vstavkami, hoara ili exit(vvedite pervyu bukvu slova)=> ");
	scanf("%s", line);
	switch (line[0])
	{
	  case 'p':
		puzyrek(size, mas);
		Readfile(f, &size, &mas);
		break;
	  case 'v':
		vstavka(size, mas);
		Readfile(f, &size, &mas);
		break;
	  case 'h':
		timehoara(mas, 0, size - 1);
		Readfile(f, &size, &mas);
		break;
	  case 'e':
		printf("Quit");
		fclose(f);
		free(mas);
		return 0;
	  default:
		printf("nevernaya comanda\n");
	}
  }
  return 0;
}