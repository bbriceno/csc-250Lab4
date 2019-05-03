	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#include <unistd.h>
	#include "myFunctionsLib.h"
	

	// defining the maximum size of our array
	#define MAXROWS 200
	#define MAXCOLS 200
	

	int main(int argc, char *argv[])
	{
	    FILE *myFile; // creates a pointer file that points to myFile
	    myFile = fopen(argv[1],"r"); // myFile opens the file called "life.txt"
	        if (myFile == NULL) { // if myFile returns NULL, print "File Not Found"
	            printf("***File Not Found!!!!***\n");
	            exit(1); // if myFile returns NULL, quits the program...
	        }
	        
	    int nRows; // used to read number of rows in life.txt
	    int nCols; // used to read number of columns in life.txt
	    
	    fscanf(myFile, "%d", &nRows); // reads the rows in life.txt... 20 rows
	    fscanf(myFile, "%d", &nCols); // reads the columns in life.txt... 40 columns
	    
	    printf("%d %d \n", nRows, nCols);  // prints the number of rows and columns
	

	    char list[2000]; // limit characters to 2000 rather than a smaller number to be safe
	    int i=0; // makes i=0 for loop below
	    
	    while(! feof(myFile)){
	        char t; // creates a variable as t
	        
	            fscanf (myFile, "%c", &t); // reads each character in the life.txt... characters are either '*' or ' '
	            list[i] = t;
	            i++; // repeats until myFile reaches end of file
	    }
	    
	    fclose(myFile); // closes myFfile when complete...
	    
	    int rowIndex, colIndex; // creates indexes for rows and columns
	    char golGridWithFile[MAXROWS][MAXCOLS];
	    
	    int listIndex=0; // initializes listIndex to zero
	    
	    for (rowIndex=0; rowIndex < nRows; rowIndex++) // increases row index until it reaches 20
	    {
	        for (colIndex=0; colIndex < nCols; colIndex++) // increases column index until it reaches 40
	        {
	            golGridWithFile[rowIndex][colIndex] = list[listIndex];
	            listIndex++; // list index is made 800 (rowIndex times colIndex (20*40))
	        }  
	    }
	    
	    int golGridWithFileAgain [MAXROWS][MAXCOLS];
	

		for(rowIndex=0; rowIndex < nRows; rowIndex++) // resets rowIndex to 0 then reinstates it to 20 again to make game work
		{
			for(colIndex = 0; colIndex < nCols; colIndex++) // resets colIndex to 0 then reinstates it to 40 again to make game work
			{
				if(golGridWithFile[rowIndex][colIndex] == '*') // creates '*' for life cells in GoL
				{
					golGridWithFileAgain[rowIndex][colIndex] = 1; // initializes '*' to variable 1
				}
				else
				{
					golGridWithFile[rowIndex][colIndex] = 0; // if not variable 1, everything else (' ') is variable 0
				}
			}
	    }
	    
	    printGameOfLife(golGridWithFileAgain,nRows,nCols); // prints the GoL with the proper amount of rows and columns with
	                                                       // with the proper '*' and ' '
	    

	    usleep(1000000); // shows the original layout of cells for 1 second1	    
	    while(1){
	    printf("--------------------------------------------\n"); // if the game continues to the next iteration,
	                                                              // will create a new dashed line
	    printGameOfLife(golGridWithFileAgain,nRows,nCols); // prints the game of life with current cells
	    updateGameOfLife(golGridWithFileAgain,nRows,nCols); // updates the game with new cells
	    usleep(2000000); // pauses for 2 seconds before updating the game of life
	    }
	    
	    
	}
