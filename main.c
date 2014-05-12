#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fill_with_numbers(int *nums, int modulo, int grenze)
{
  // Init randomizer
  srand(time(NULL));

  int i, j;

  for(i = 0; i < grenze; i++)
  {
    if(*(nums + i) >= 0) continue;

    while(1)
    {
      int tmp = rand() % modulo;
      int ok = 1;

      for(j = 0; j < i; j++)
      {
        if(*(nums + j) == tmp) ok = 0;
      }

      if(ok) {
        *(nums + i) = tmp;
        break;
      }
    }
  }
}

int main()
{
  int numbers[4] = {-1, -1, -1, -1};

  fill_with_numbers(numbers, 10, 4);

  printf("%i %i %i %i\n", numbers[0], numbers[1], numbers[2], numbers[3]);

  return 0;
}
