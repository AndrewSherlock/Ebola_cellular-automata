#include "Cell.h"
#include "Config.h"

void GetColOfCells(Cell **world, Cell *neighbours, Cell startCell, int startIndex, int runs)
{
  int i;
  for(i = 1; i <= runs - 1; i++)
  {
    neighbours[startIndex + i] = world[startCell.x][(CELL_Y + startCell.y + i) % CELL_Y];
  }
}
