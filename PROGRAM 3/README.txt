TEAM 3

Anusha Phaniraj
1KS20AI004
anushaphaniraj1209@gmail.com
+91 83101 55208

Sahithi Bhashyam
1KS20AI036
sahithib.uni@gmail.com
+91 82967 96003

LOGIC USED

Program 03:
Summary:
Minesweeper is a 1960s era video game played on an m-by-n grid of cells. The goal is to deduce which cells contain hidden mines using clues about the number of mines in neighbouring cells. The program takes three positive integers m, n, and k and prints an m-by-n grid of cells with k mines, using asterisks for mines and integers for the neighbouring mine counts (with one space character between each cell). The output should have exactly k of the m*n cells containing mines, uniformly at random. For each cell not containing a mine, count the number of neighbouring mines (above, below, left, right, or diagonal).

First, we take the user input for the size of the minefield and the number of mines. Then we check if it is within the constraints, if not, the program will come to an end. After this, we declare an array of size m*n, where m is the number of rows and n is the number of columns. The array elements are initialised to 0. Asterisks are placed at random positions in the array. Then, for a cell not containing a mine, the program will check the surrounding cells for the presence of mines and reflect the number of mines surrounding the cell in that cell (corner cells, boundary line cells and the remaining cells). Finally, we print the array to get the desired output.



CHALLENGES FACED AND HOW THEY WERE RECTIFIED


The first hurdle we faced was to randomly place asterisks in the array. We thought that we could somehow straight away generate asterisks in the array but we were proven wrong after referring to many programs over the internet and consulting our professor. We had to randomly generate numbers using the rand() function then assign them to indexes of the array to get random positions and change 0 at that cell to an asterisk. We learnt that the rand() function is a good way to generate numbers randomly but they are only random with every compile and not every run. To solve this problem we had to use srand(time(NULL)) function with a pre-processor directive <time.h>. The srand() function gives us random numbers with every run as long as the seed is different for every run or else it works just like the rand() function. time(NULL) uses the computer’s internal clock to control the seed. Since time is forever changing, we get a new seed with every run.

The second problem was to get the k number of mines. We tried using for loop, which gave us the incorrect output. By trial and error method we found that while loop works.

The third problem we faced was to count the number of mines surrounding a cell and reflecting that number on the cell. We used for loop to go through the array and check every cell for the presence of mines. If there is no mine, it looks around every other cell surrounding that cell and if there is a mine in the surrounding cell of that cell then it increments the value present at that cell. Here we ran into yet another problem. We cannot use the same set of if...else statements for every cell of the array. There are few cells that are not surrounded by cells in all 8 directions. Like, the corner cell is surrounded by 3 other cells and the boundary cells are surrounded by 5 other cells. After discussing with our professor, we wrote three cases of nested if...else statements for i) Corner cell ii) Boundary cell iii) Remaining cells of the array.
This increased the number of lines in our program but it gives the desired output. 

Our program had a shortcoming. It was supposed to display “Invalid input” for entering input values that are outside the given constraints i.e 1 < m and 20 > k. It was supposed to display “Invalid input” for negative numbers but it did not do anything(there was no output or error). Hence, as suggested by our professor we tweaked the program code. We declared the array after the if statement to display “Invalid input”. This gave us the desired output.

CONTRIBUTION BY EACH MEMBER

In the beginning, we brainstormed the program separately and then combined our interpretations and code to get the apt output. 

REFERENCES

https://mathbits.com/MathBits/CompSci/LibraryFunc/rand.htm
https://www.geeksforgeeks.org/cpp-implementation-minesweeper-game/
https://ofstack.com/C++/27267/c-language-implements-simple-minesweeper-games.html
https://stackoverflow.com/questions/69770245/minesweeper-program-exceeding-time-limit
https://cboard.cprogramming.com/c-programming/137175-generating-random-points-grid.html
