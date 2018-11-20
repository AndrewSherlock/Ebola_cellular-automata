#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "Person.h"
#include "State.h"
#include "Cell.h"
#include "Config.h"

#include "function_prototypes.h"



int main(int argc, char *argv[])
{
    srand(time(NULL));
    Cell **worldCell = malloc(CELL_Y * sizeof(Cell*));

    char sTime[80];
    time_t startTime;
    time(&startTime);
    strcpy(sTime, ctime(&startTime));

    int i;
    for(i = 0; i < CELL_Y;i++) // this for loop allocates space in memory for each of the columns of the size of the world cells array
    {
     worldCell[i] = malloc(CELL_X * sizeof(Cell)); 
    }


    GenerateCells(worldCell, CELL_X, CELL_Y);
    GeneratePopulation(worldCell);
    PickSickCells(worldCell);
    RunSimulation(worldCell);

    free(worldCell);

    time_t finishTime;
    time(&finishTime);

    printf("\nStart Time : %s \nFinish Time : %s", sTime, ctime(&finishTime));
 

    execl("/usr/bin/java", "java","-jar", "Ebola_visual.jar", (char *)0);
    return 0 ;
}
