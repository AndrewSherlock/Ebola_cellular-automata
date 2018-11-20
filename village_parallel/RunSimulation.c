#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include <time.h>
#include "function_prototypes.h"
#include "Cell.h"
#include "Config.h"
#include "WorldVaribles.h"


void RunSimulation(Cell **worldCells)
{
  int counter = NUM_OF_RUNS;
  int vacine_start = VACINE_DAY_START;
  int day = 0;
  Cell **newWorld = malloc(CELL_Y * sizeof(Cell*)); // creation of our new array to hold temp values
  population = CELL_X * CELL_Y;
 
  for(int i = 0; i < CELL_Y;i++) // this for loop allocates space in memory for each of the columns of the size of the world cells array
  {
    newWorld[i] = malloc(CELL_X * sizeof(Cell)); 
    memcpy(newWorld[i], worldCells[i],CELL_X * sizeof(Cell)); // copies worldcells to newworld
  }

  thread_info_t thread_split[numOfThreads];
 
  ThreadSetUp(worldCells, newWorld, thread_split);

  while(counter > 0)
  {
    pthread_t thread_ids[numOfThreads];

    if(counter <= vacine_start)
    {
      long peopleToVacine = (population - numberOfDeath) - (numberOfVacinated + numberOfInfected);
      int vPeople = VacinatePeople(newWorld, peopleToVacine);
      numberOfVacinated += vPeople;
    }
     
    int i;
    for(i = 0; i < numOfThreads; i++)
    {
      numberOfDeath = 0;
      numberOfRecovered = 0;
      numberOfInfected = 0;
      pthread_create(&thread_ids[i], NULL, RunSectionOfGrid, (void *) (&thread_split[i]));
    }

    for(i = 0; i < numOfThreads;i++)
    {
      int error = pthread_join(thread_ids[i], NULL);
      numberOfDeath += thread_split[i].numberDeadInArea;
      numberOfRecovered += thread_split[i].numberRecoveredInArea;
      numberOfInfected += thread_split[i].numberInfectedInArea;
      progress += thread_split[i].progressInArea;
      thread_split[i].progressInArea = 0;
    }

    printf("Simulation_Progress............................... %.1f/100\n", progress);

  
    for(i = 0; i < CELL_Y;i++) // loop and copy rows of arrays to new array
    {
      memcpy(worldCells[i], newWorld[i],CELL_X * sizeof(Cell));
    }
    
    PrintWorldInfoToFile(worldCells, day);
    day++;
    counter--;
  } 
}

