#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
  // Init randomizer
  srand(time(NULL));

  int numbers[4] = {-1, -1, -1, -1};
  int i, j;

  for(i = 0; i < 4; i++)
  {
    if(numbers[i] >= 0) continue;

    while(1)
    {
      int tmp = rand() % 10;
      int ok = 1;

      for(j = 0; j < i; j++)
      {
        if(numbers[j] == tmp) ok = 0;
      }

      if(ok) {
        numbers[i] = tmp;
        break;
      }
    }
  }

  printf("%i %i %i %i\n", numbers[0], numbers[1], numbers[2], numbers[3]);

  return 0;
}
