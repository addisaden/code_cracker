#include <time.h>
#include <stdlib.h>
#include "randomizer.h"

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
