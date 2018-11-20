#include <stdlib.h>
#include "Cell.h"
#include "function_prototypes.h"

int FirstRoundOfInfections(Cell **world, int numOfSick, int xStartPoint, int yStartPoint)
{
   Cell *neighbours = malloc(sizeof(Cell) * 8);
   int i; 
   GetNeighbourCells(world, neighbours, xStartPoint, yStartPoint);
   int sickLeft;
   
   if(numOfSick > 8)
   {
     sickLeft = numOfSick - 8;
   } else{
     sickLeft = 0;
   }
   
   for(i = 7; i >= 0; i--)
   {

     if(numOfSick != 0)
     {
     	int x = neighbours[i].x;
     	int y = neighbours[i].y;
     	world[x][y].person.currentState = SICK;
    	numOfSick--;
     } else
     {
       return numOfSick;
     }
   }

    free(neighbours);

    return sickLeft;
}
