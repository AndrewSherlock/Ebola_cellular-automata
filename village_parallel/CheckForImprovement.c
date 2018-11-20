#include <math.h>
#include "Cell.h"
#include "Person.h"
#include "function_prototypes.h"

int CheckForImprovement(Cell **world, Cell **nWorld, int x, int y)
{
    if((rand() % 100) < 10)
    {
       Person *ptr = &(world[x][y].person);
       int improvementRate = GetPersonImprovement(ptr);
       nWorld[x][y].person.healthLevel += improvementRate;
       if(nWorld[x][y].person.healthLevel >= world[x][y].person.startHealthLevel)
       { 
	 nWorld[x][y].person.currentState = RECOVERED;
	 return 1;
       }
    }

    return 0;
}
