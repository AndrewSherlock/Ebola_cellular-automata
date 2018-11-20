#include <stdio.h>
#include <stdlib.h>

#include "Config.h"
#include "Cell.h"
#include "function_prototypes.h"




void GeneratePopulation(Cell **world) // this is just a method to generate everyone in the world
{
    int y,x = 0;
    for(y = 0; y < CELL_Y; y++)
    {
        for(x = 0; x < CELL_X; x++)
        {
             Person *ptr = &(world[x][y].person); // get the memory address of the perosn on the tile
             GeneratePerson(ptr); // pass it in to the function to generate the person information
        }
    }
}


/* DELETE MAYBE
void PrintRightName(int state)
{
  switch(state){
      case 0:
        printf("Healthy");
      break;
      case 1:
        printf("Dead");
        break;
      case 2:
        printf("Sick");
        break;
      case 3:
        printf("Immune");
        break;
      case 4:
        printf("Recovered");
        break;
      }
} */ 
