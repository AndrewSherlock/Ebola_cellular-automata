#include "Config.h"
#include "Cell.h"
#include "function_prototypes.h"

void ThreadSetUp(Cell **world, Cell **temp, thread_info_t *thread)
{
  int numOfRowsPerThread = NumberOfRowsPerCore(numOfThreads);

  int i; 
  for(i = 0; i < numOfThreads; i++)
  {
    thread[i].startY = numOfRowsPerThread * i;
    if(i != numOfThreads - 1)
    {
      thread[i].finishY = (numOfRowsPerThread * i) + numOfRowsPerThread;
    } else{
      thread[i].finishY = CELL_Y;
    }

    thread[i].worldPointer = world; // cur cell
    thread[i].newArray = temp; // temp array

    thread[i].numberInfectedInArea = 0;
    thread[i].numberDeadInArea = 0;
    thread[i].numberRecoveredInArea = 0;
    thread[i].progressInArea = 0;
  }

}
