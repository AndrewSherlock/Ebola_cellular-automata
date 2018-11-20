#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "function_prototypes.h"
#include "Cell.h"
#include "Config.h"


void RunSimulation(Cell **worldCells)
{
    int counter = NUM_OF_RUNS;
    int run = 0;

    long startPop = 0;
    long currentDeath = 0;
    long currentVacinated = 0;
    long currentRecovered = 0;
    long currentInfected = 0;

    float progress = 100.f/ (CELL_Y * NUM_OF_RUNS);
    float curProgress = 0.f;
  
    printf("Currently simulating illness. Please Wait\n");
  
    startPop = CELL_X * CELL_Y;
    currentInfected = NUM_OF_SICK;
    int vacine_start = counter - VACINE_DAY_START;

    while(counter > 0) // as many runs as we want
    {
        int x,y;

        Cell **newWorld = malloc(CELL_Y * sizeof(Cell*)); // creation of our new array to hold temp values
			// own function 	

	for(int i = 0; i < CELL_Y;i++) // this for loop allocates space in memory for each of the columns of the size of the world cells array
        {
            newWorld[i] = malloc(CELL_X * sizeof(Cell)); 
            memcpy(newWorld[i], worldCells[i],CELL_X * sizeof(Cell)); // copies worldcells to newworld
        }

	if(counter <= vacine_start)
	{
	  long peopleToVacine = (startPop - currentDeath) - (currentVacinated + currentInfected);
          int vPeople = VacinatePeople(newWorld, peopleToVacine);
	  currentVacinated += vPeople;
	}

        for(y = 0; y < CELL_Y; y++) // gets each tile in our world
        {
	    printf("Simulation_Progress............................... %.1f/100\n", curProgress); 
            for(x = 0; x < CELL_X; x++)
            {
              	if(worldCells[x][y].person.currentState == DEAD || worldCells[x][y].person.currentState == RECOVERED || worldCells[x][y].person.currentState == IMMUNE){
                    continue;
                }

                if(worldCells[x][y].person.currentState != SICK)
                {
                    currentInfected += InfectionPersonCheck(worldCells, newWorld, x, y);                      		    
                }
                else if(worldCells[x][y].person.currentState == SICK) // if they are sick
                {
                    if(worldCells[x][y].person.healthLevel <= 0)
                    {
                        newWorld[x][y].person.healthLevel = 0; // kill them
                        newWorld[x][y].person.currentState = DEAD;
			currentDeath++;
			currentInfected--;
                    } else{

		      int isGettingWorse = rand() % 2; // else 50 : 50 chance of decrementing health
		      if(isGettingWorse == 1)
			{
			  int decrementOfHealthAmount = (rand() % 20 - 10) + 10; // Gives a random amount of decremented health to subtract between 10-20
			  newWorld[x][y].person.healthLevel -= decrementOfHealthAmount; // take health way
			} else{
			int recover = CheckForImprovement(worldCells, newWorld, x, y);
			if(recover != 0){
			  currentRecovered++;
			  currentInfected--;
			}
		      }
		    }
		}
	    }

	   curProgress += progress;
	} 
    

	int i, p;
        for(i = 0; i < CELL_Y;i++) // loop and copy rows of arrays to new array
        {
            memcpy(worldCells[i], newWorld[i],CELL_X * sizeof(Cell));
        }

	for(p = 0; p < CELL_Y;p++) // loop and copy rows of arrays to new array
        {
	    free(newWorld[p]);
        }
        free(newWorld); // free up memory of the temp array

	run++;
        PrintWorldInfoToFile(worldCells, run);
    
        counter--;
    }

    printf("Simulation is finished. Thank you.\n");
}





