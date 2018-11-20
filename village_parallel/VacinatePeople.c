#include <math.h>
#include "Cell.h"
#include "Config.h"

int VacinatePeople(Cell **world, int hPopulation)
{
  int vacine_round = NUM_VACINES_PER_DAY; // number of vacines availible on day
  int numPeopleVacinated = 0; // start number vacinated
  while(vacine_round > 0) // while we have vacines
  {
      if(hPopulation < vacine_round) // if there is no one to vacinate
      {
	 return 0;
      }

      int vac_x = rand() % CELL_X; // rand pos
      int vac_y = rand() % CELL_Y; 	
	
      if(world[vac_x][vac_y].person.currentState == HEALTHY || world[vac_x][vac_y].person.currentState != SICK ) // if the personcan be vacinated
      {
       world[vac_x][vac_y].person.currentState = IMMUNE; // change start
       numPeopleVacinated++; // add to number of vacinted
       vacine_round--; // take a vacinte away
      }	
   }

  return numPeopleVacinated; // num of people that have been vacinated
}
