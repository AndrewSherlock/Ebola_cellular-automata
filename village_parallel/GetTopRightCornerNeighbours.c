#include "Cell.h"
#include "Config.h"

void GetTopRightCornerNeighbours(Cell **world, Cell *neighbours, Cell cornerCell, int startIndex)
{
  neighbours[startIndex] = world[(CELL_X + cornerCell.x + 1) % CELL_X][(CELL_Y + cornerCell.y - 1) % CELL_Y]; // right corner
  neighbours[startIndex + 1] = world[cornerCell.x][(CELL_Y + cornerCell.y - 1) % CELL_Y]; // straight above
  neighbours[startIndex + 2] = world[(CELL_X + cornerCell.x + 1) % CELL_X][cornerCell.y]; // to the right
}
