#include <stdio.h>
#include <stdlib.h>

/**
*This program implements an N*N array with 0 as elements 
* whose distance from the main diagonal is strictly more 
* than M and an asterisk for every entry that is not a 0.
**/
int main (int argc, char *argv[]) {
  int N = atoi (argv[1]);
  int M = atoi (argv[2]);

/**
*Filter out inputs that are not within the constraints.
**/
  if (M < 0 || M > 5 || N >= 10 || N <= 1) {
    printf ("Invalid input");
    exit (0);
  }

  int pattern[N][N];

/**
*Initialize array elements to 0 and diagonal elements to asterisk.
* Use for loop to get M lines of asterisks in array and print the array.
**/
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      pattern[i][j] = '0';
      if (i == j) {
        pattern[i][j] = '*';
      }
      else {
        for (int asterisk = 0; asterisk <= M; asterisk++) {
          if (i == j + asterisk || i == j - asterisk)
	    pattern[i][j] = '*';
	  }
	}
       printf ("%c ", pattern[i][j]);
     }
    printf ("\n");
  }

  return 0;
}

