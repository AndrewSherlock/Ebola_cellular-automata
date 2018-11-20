#include <math.h>
#include "Cell.h"

int InfectionPersonCheck(Cell **world, Cell **nWorld, int x, int y)
{
    Cell *nArray = malloc(sizeof(Cell) * 8);
    GetNeighbourCells(world, nArray, x, y);
    int probability = GetNeighbourProbability(nArray, 8); // work out the probability of infection

    if(probability > 0)
    {
    	int weighted = get_weighted_probability(probability, world[x][y].person.healthLevel); // get the infection for the rules
    	weighted = weighted + (weighted * AddInfectionRateForAge(world[x][y].person.age));	// takes into account for the age
	
    	if(rand() % 100 < weighted)
    	{
    	    nWorld[x][y].person.currentState = SICK; // calc taking persons health level into account
            return 1;
    	}
   }
    
    free(nArray);	
    return 0;

}
