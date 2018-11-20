#include "Cell.h"
#include "Config.h"

void GetBottomLeftCornerNeighbours(Cell **world, Cell *neighbours, Cell cornerCell, int startIndex)
{
  neighbours[startIndex] = world[(CELL_X + cornerCell.x - 1) % CELL_X][(CELL_Y + cornerCell.y + 1) % CELL_Y]; // right bottom left
  neighbours[startIndex + 1] = world[cornerCell.x][(CELL_Y + cornerCell.y + 1) % CELL_Y]; // straight down
  neighbours[startIndex + 2] = world[(CELL_X + cornerCell.x - 1) % CELL_X][cornerCell.y]; // to the left
}
