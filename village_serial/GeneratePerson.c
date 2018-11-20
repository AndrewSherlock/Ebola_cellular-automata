

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//#include "Config.h"
#include "Person.h"
#include "function_prototypes.h"
//#include "Cell.h"

//void generatePerson(Cell world[][CELL_Y], int x, int y) // we need to get the pointer to the person to get this to work, i just taught this would work

void GeneratePerson(Person *personPointer)
{

    personPointer->age = rand() % 100;
    personPointer->healthLevel = (rand() %  99) + 1;
    personPointer->startHealthLevel = personPointer->healthLevel;
    personPointer->currentState = HEALTHY; // whats the difference between health level and current state???

    // this generates the information. we have add more fields in here if we so wish

}
