#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUCKY_NUMBER 7

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
  int balls[6];
  int count_balls = 0;
  int favorite = 0;
  for (int i = 1; i < argc; i++)
    {
      const char *arg = argv[i];
      if ('-' == arg[0])
	{
	  if (0 == strcmp (arg, "-favorite"))
	    {
	      favorite = 1;
	    }
	  else
	    {
	      goto usage_error;
	    }
	}
      else
	{
	  char *endptr = NULL;
	  long val = strtol (arg, &endptr, 10);
	  if (*endptr)
	    {
	      goto usage_error;
	    }
	  balls[count_balls++] = (int) val;
	}
    }
  if (6 != count_balls)

    {
      goto usage_error;
    }
  int power_ball = balls[5];
  int result = calculate_result (balls, power_ball);
  if (result < 0)
    {
      goto usage_error;
    }
  if (LUCKY_NUMBER == power_ball)
    {
      result = result * 2;
    }
  if (favorite)
    {
      result = result * 2;
    }
  printf ("%d percent chance of winning\n", result);
  return 0;
usage_error:
  fprintf (stderr, "Usage: %s [-favorite] (5 white balls) power_ball\n",
	   argv[0]);
  return -1;
}

// Comentario de prueba para modificar fichero y poder hacer merge.
