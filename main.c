#include <stdio.h>
#include "randomizer.h"

int main()
{
  int numbers[4] = {-1, -1, -1, -1};

  fill_with_numbers(numbers, 10, 4);

  printf("%i %i %i %i\n", numbers[0], numbers[1], numbers[2], numbers[3]);

  return 0;
}
