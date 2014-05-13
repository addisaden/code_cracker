#include <stdio.h>
#include "randomizer.h"

int guess_numbers(int *nums, int range, int length)
{
  int guessed[length];
  char correct[length];
  int i, j;

  printf("%i numbers to guess (0 - %i):\n", length, range - 1);

  // guessing
  for(i = 0; i < length; i++)
  {
    scanf("%i", guessed + i);
  }

  // check the guessing
  for(i = 0; i < length; i++)
  {
    correct[i] = '\0';

    if(guessed[i] >= range || guessed[i] < 0)
    {
      correct[i] = '?';
      continue;
    }

    else if(guessed[i] == nums[i])
    {
      correct[i] = 'X';
      continue;
    }

    for(j = 0; j < length; j++)
    {
      if(guessed[i] == nums[j])
      {
        correct[i] = '+';
        break;
      }
    }

    if(correct[i] == '\0')
      correct[i] = ' ';
  }

  // check for winning
  for(i = 0; i < length; i++)
  {
    if(correct[i] != 'X') break;
    if(i == length - 1) return 1;
  }

  // print corrector
  for(i = 0; i < length; i++)
    printf("%c ", correct[i]);

  printf("   X :correct   + : move this   ? : not in range\n");

  return 0;
}



int main()
{
  puts("C O D E - C R A C K E R");
  puts("");
  puts("There is a Code of 4 numbers. You should find it out.");
  puts("-- have fun and follow (@addisaden)");
  puts("");

  int numbers[4] = {-1, -1, -1, -1};

  fill_with_numbers(numbers, 10, 4);

  int solved = 0;
  int counter = 0;

  while(!(solved = guess_numbers(numbers, 10, 4)))
  {
    if(counter >= 10)
      break;
    counter++;
  }

  if(solved)
    printf("You cracked the code in %i steps. Congratulation.\n", counter+1);
  else
    puts("You lost. Maybe you crack it the next time.");

  printf("CODE :: %i %i %i %i\n", numbers[0], numbers[1], numbers[2], numbers[3]);

  return 0;
}
