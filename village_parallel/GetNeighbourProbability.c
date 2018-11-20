#include "Cell.h"
#include "Config.h"
#include "function_prototypes.h"

int GetNeighbourProbability(Cell neighbours[], int sizeOfNeighbours)
{
    int i = 0;
    int probability = 0;

    for(i = 0; i < sizeOfNeighbours; i++) // simple loop to check each neighbours
    {
        if(neighbours[i].person.currentState == SICK)
        {
            probability += PROBABILITY_TO_ADD; // for each that is sick, add to probability
        }
    }
    return probability;
}

