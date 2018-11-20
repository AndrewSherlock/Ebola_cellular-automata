#include "Cell.h"
#include "Config.h"

void GetRowOfCells(Cell **world, Cell *neighbours, Cell startCell, int startIndex,  int runs)
{
  int i;
  for(i = 1; i <= runs - 1; i++)
  {
    neighbours[startIndex + i] = world[(CELL_X + startCell.x + i) % CELL_X][startCell.y];
  }
}
