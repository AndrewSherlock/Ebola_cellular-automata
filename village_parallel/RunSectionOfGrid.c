#include "Cell.h"
#include "Config.h"
#include "function_prototypes.h"

void* RunSectionOfGrid(void *arg)
{
  int x, y;
  thread_info_t *ptr = (thread_info_t *) arg;
  float progressPerTick = 100.f/ (CELL_Y * NUM_OF_RUNS);

  for(y = ptr->startY; y < ptr->finishY; y++) // gets each tile in our world
  {
    for(x = 0; x < CELL_X; x++)
    {
      if(ptr->worldPointer[x][y].person.currentState == DEAD || ptr->worldPointer[x][y].person.currentState == RECOVERED || ptr->worldPointer[x][y].person.currentState == IMMUNE)
      {
	continue;
      }

      if(ptr->worldPointer[x][y].person.currentState != SICK)
      {
	ptr->numberInfectedInArea += InfectionPersonCheck(ptr->worldPointer, ptr->newArray, x, y);                      		    
      }
      else if(ptr->worldPointer[x][y].person.currentState == SICK) // if they are sick
      {
	if(ptr->worldPointer[x][y].person.healthLevel <= 0)
	{
	  ptr->newArray[x][y].person.healthLevel = 0; // kill them
          ptr->newArray[x][y].person.currentState = DEAD;
	  ptr->numberDeadInArea;
	  ptr->numberInfectedInArea;
        } else{

	  int isGettingWorse = rand() % 2; // else 50 : 50 chance of decrementing health
	  if(isGettingWorse == 1)
	  {
	    int decrementOfHealthAmount = (rand() % 20 - 10) + 10; // Gives a random amount of decremented health to subtract between 10-20
	    ptr->newArray[x][y].person.healthLevel -= decrementOfHealthAmount; // take health way
	  } else{
	    int recover = CheckForImprovement(ptr->worldPointer, ptr->newArray, x, y);
	    if(recover != 0){
	      ptr->numberRecoveredInArea++;
	      ptr->numberInfectedInArea--;
	    }
	  }
	}
      }
    }
    ptr->progressInArea += progressPerTick;
  }
}

