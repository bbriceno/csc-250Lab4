#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "myFunctionsLib.h"


//define max size of 2d array
#define MAXROWS 200
#define MAXCOLS 200

int main(int argc,char * argv[])
{
	
	
	//how many rows and cols we actually use
	int useRows = 20, useCols = 20;
	
	int rowIndex, colIndex;
	srand(time(NULL));
	
	//create 2d array
	int golGrid[MAXROWS][MAXCOLS];  /*= { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
									  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
									  {0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
									  {0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0},
									  {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									  {0},
									  {0},
									  {0},
									  {0},
									  {0} };
	
*/	
	int neighbors[MAXROWS][MAXCOLS];
	
	//seeds golGrid with random nums
	for (rowIndex=0; rowIndex < useRows; rowIndex++)
	{
		for (colIndex=0; colIndex < useCols; colIndex++)
		{
			golGrid[rowIndex][colIndex] = rand() % 2;	
		}
		
	}


	
	//prints game of life grid, updates it according to rules, then pauses
	//infinite loop.. will keep doing this until program is killed
	while(1){
		puts("========================================================");
		printGameOfLife(golGrid, useRows, useCols);
		updateGameOfLife(golGrid, useRows, useCols);
		usleep(600000);
				system("clear");
	}
	
}	
