#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* This program implements an array of size m*n 
* with k number of mines randomly generated on the array.
* It then counts the number of neighbouring mines
* for each cell not containing a mine.
**/
int main(int argc, char *argv[]) {

  int m = atoi(argv[1]);
  int n = atoi(argv[2]);
  int k = atoi(argv[3]);
  int i,j;
  int mine = 0;

  if(k>20||k<0||m<=1||(m*n)<k||argv[3]==0||argv[4]>=0) {
    printf("Invalid Input");
    exit(0);
  }

/**
* Create and intialize the size of an array.
* Use srand() function to set the seed for rand() function.
* Initialize the array elements to '0'.
**/
  int minefield[m][n];
  srand(time(NULL));
  for (i = 0; i < m; i++ ) {
    for (j = 0; j < n; j++) {
      minefield[i][j] = '0';
    }
  }

/**
* While loop is used to randomly generate k number of mines.
* Randomly generate a value for i and j within the range of m and n respectively.
* If at that cell there is no mine then a mine is placed.
**/
  while (mine < k) {
    i = rand() % m;
    j = rand() % n;
    if( minefield[i][j] != '*') {
      minefield[i][j] = '*';
      mine++;
    }
  }

/** For loop and nested if else statements
* to count the number of mines surrounding a cell.
**/
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (i == 0) { // Row 1
        if (j == 0) { // Top left corner cell surrounded by 3 cells
          if(minefield[i+1][j+1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	  if(minefield[i][j+1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
          if(minefield[i+1][j] == '*' && minefield[i][j] != '*') {
	    minefield[i][j]++;
          }
       	}
	else if (j == n-1) { // Top right corner cell surrounded by 3 cells
          if(minefield[i+1][j-1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
  	  }
          if(minefield[i][j-1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
          if(minefield[i+1][j] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	}
      	else { // Remaining cells in Row 1
          if(minefield[i+1][j-1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
          if(minefield[i+1][j] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
          if(minefield[i+1][j+1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	  if(minefield[i][j-1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	  if(minefield[i][j+1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	}
      }
      else if (i==m-1) { // Row m
        if (j==0) { // Bottom left corner cell surrounded by 3 cells
          if(minefield[i-1][j+1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
          if(minefield[i][j+1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
          if(minefield[i-1][j] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	}
	else if (j==n-1) { // Bottom right corner cell surrounded by 3 cells
	  if(minefield[i-1][j-1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	  if(minefield[i][j-1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	  if(minefield[i-1][j] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	}
	else { // Remaining cells in Row m surrounded by 5 cells
	  if(minefield[i-1][j-1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	  if(minefield[i-1][j] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	  if(minefield[i-1][j+1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	  if(minefield[i][j-1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	  if(minefield[i][j+1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	}
      }
      else { 
        if (j==0) { // Remaining cells in Column 1 surrounded by 5 cells
	  if(minefield[i-1][j] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	  if(minefield[i+1][j] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	  if(minefield[i-1][j+1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	  if(minefield[i][j+1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	  if(minefield[i+1][j+1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	}
	else if (j==n-1) { // Remaining cells in Column n surrounded by 5 cells
	  if(minefield[i-1][j] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	  if(minefield[i+1][j] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	  if(minefield[i-1][j-1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	  if(minefield[i][j-1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	  if(minefield[i+1][j-1] == '*' && minefield[i][j] != '*') {
            minefield[i][j]++;
          }
	}
	else { // All the remaining cells in the minefield surrounded by 8 cells
	  if(minefield[i-1][j-1] == '*' && minefield[i][j] != '*'){
            minefield[i][j]++;
          }
	  if(minefield[i-1][j] == '*' && minefield[i][j] != '*'){
            minefield[i][j]++;
          }
	  if(minefield[i-1][j+1] == '*' && minefield[i][j] != '*'){
            minefield[i][j]++;
          }
	  if(minefield[i][j-1] == '*' && minefield[i][j] != '*'){
            minefield[i][j]++;
          }
	  if(minefield[i][j+1] == '*' && minefield[i][j] != '*'){
            minefield[i][j]++;
          }
	  if(minefield[i+1][j-1] == '*' && minefield[i][j] != '*'){
            minefield[i][j]++;
          }
	  if(minefield[i+1][j] == '*' && minefield[i][j] != '*'){
            minefield[i][j]++;
          }
	  if(minefield[i+1][j+1] == '*' && minefield[i][j] != '*'){
            minefield[i][j]++;
          }
	}
      }
    }
  }

/**
* For loop to print the minefield
**/
  for (i = 0; i < m; i++){
    for (j = 0; j < n; j++){
      printf("%c ", minefield[i][j]);
    }
    printf("\n");
  }
  return 0;
}
