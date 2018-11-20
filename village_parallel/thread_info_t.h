#include "Cell.h"

typedef struct{

  int startY;
  int finishY;
  Cell **worldPointer;
  Cell **newArray;

  int numberInfectedInArea;
  int numberDeadInArea;
  int numberRecoveredInArea;

  float progressInArea;
  
} thread_info_t;
