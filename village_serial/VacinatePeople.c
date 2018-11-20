#include <math.h>
#include "Cell.h"
#include "Config.h"

int VacinatePeople(Cell **world, int hPopulation)
{
  int vacine_round = NUM_VACINES_PER_DAY;
  int numPeopleVacinated = 0;
  while(vacine_round > 0)
  {
      if(hPopulation < vacine_round)
      {
	 return 0;
      }

      int vac_x = rand() % CELL_X;
      int vac_y = rand() % CELL_Y; 	
	
      if(world[vac_x][vac_y].person.currentState == HEALTHY || world[vac_x][vac_y].person.currentState != SICK )
      {
       world[vac_x][vac_y].person.currentState = IMMUNE;
       numPeopleVacinated++;
       vacine_round--;
      }	
   }

  return numPeopleVacinated;
}
