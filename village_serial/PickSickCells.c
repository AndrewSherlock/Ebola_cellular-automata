#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "Cell.h"
#include "function_prototypes.h"
#include "Config.h"

void PickSickCells(Cell **world)
{
  int numOfSick =  NUM_OF_SICK;
  int xStartPoint = rand() % CELL_X;
  int yStartPoint = rand() % CELL_Y;

   world[xStartPoint][yStartPoint].person.currentState = SICK;
   numOfSick -= 1;
 
  if(numOfSick <= 8)
  {
    numOfSick = FirstRoundOfInfections(world, numOfSick, xStartPoint, yStartPoint);
    return;
  }else{
     int iterationGrowth = 4;
     int iteration = 0;
     Cell *neighbours;
 
     while(numOfSick > 0)
     {
       if(iteration == 0)
       {
	   numOfSick = FirstRoundOfInfections(world, numOfSick, xStartPoint, yStartPoint);
	   neighbours = malloc(sizeof(Cell) * 8);
	   GetNeighbourCells(world, neighbours, xStartPoint, yStartPoint);
	   iteration++;
       }else{

	 int numOfCellsToCheck = (3 * 4) + (4 * (iteration - 1));
	 Cell *temp = malloc(sizeof(Cell) * numOfCellsToCheck);
	 int nextElement = 0;
	 int colSize = 1 * iteration;
	 
	 GetTopLeftCornerCellsNeighbours(world, temp, neighbours[0], 0); // takes the first 3 elements
	 nextElement = 3;
	
	 GetTopRightCornerNeighbours(world, temp, neighbours[iteration], nextElement);
         nextElement += 3;
	 
	 GetBottomRightCornerNeighbours(world, temp, neighbours[5 + iteration],nextElement);
	 nextElement +=3;
	
	 GetBottomLeftCornerNeighbours(world, temp, neighbours[3 + iteration], nextElement);
	 nextElement += 2; // correcting for indexes
	
	 GetRowOfCells(world, temp, temp[1], nextElement, colSize);
	 nextElement += colSize - 1;
	
	 GetRowOfCells(world, temp, temp[10], nextElement, colSize);
	 nextElement += colSize - 1;
	
	 GetColOfCells(world, temp, temp[2], nextElement, colSize);
	 nextElement += colSize - 1;
	 GetColOfCells(world, temp, temp[5], nextElement, colSize);

	 neighbours = malloc(sizeof(Cell) * numOfCellsToCheck);

	 memcpy(neighbours, temp, sizeof(Cell) * numOfCellsToCheck);
	 free(temp);
	 
	 int i;
	 for(i = 0; i < numOfCellsToCheck;i++)
	 {
	    if(numOfSick <= 0)
	   {
	     return;
	   }
	   
	    world[neighbours[i].x][neighbours[i].y].person.currentState = SICK;
	    numOfSick--;
	   }
       } 
       iteration++;
     }
  }
  
 

}

