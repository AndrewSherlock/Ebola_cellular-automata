#include <stdio.h>
#include "Cell.h"
#include "Person.h"

#include "Config.h"
#include "function_prototypes.h"


void GenerateCells(Cell **array, int sizeX, int sizeY) //CELL_X    CELL_Y
{
    int x,y;

    for(x = 0; x < sizeX; x++)
    {
        for(y = 0; y < sizeY; y++)
        {
            array[x][y].x = x;
            array[x][y].y = y;

        }
    }
}

