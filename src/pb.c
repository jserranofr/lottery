#include <stdio.h>
#include <stdlib.h>
int
calculate_result (int white_balls[5], int power_ball)
{
  for (int i = 0; i < 5; i++)
    {
      if ((white_balls[i] < 1) || (white_balls[i] > 59))
	{
	  return -1;
	}
    }
  if ((power_ball < 1) || (power_ball > 39))
    {
      return -1;
    }
  return 0;

}

int
main (int argc, char **argv)
{
  if (argc != 7)
    {
      fprintf (stderr, "Usage: %s power_ball (5 white balls)\n", argv[0]);
      return -1;
    }
  int power_ball = atoi (argv[6]);
  int white_balls[5];
  for (int i = 0; i < 5; i++)
    {
      white_balls[i] = atoi (argv[1 + i]);
    }
  int result = calculate_result (white_balls, power_ball);
  printf ("%d percent chance of winning\n", result);
  return 0;
}
