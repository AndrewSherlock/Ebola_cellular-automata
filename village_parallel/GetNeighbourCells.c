#include "Cell.h"
#include "Config.h"

void GetNeighbourCells(Cell **world, Cell *neighbours, int x, int y){

  neighbours[0] = world[(CELL_X + x - 1) % CELL_X][(CELL_Y + y - 1) % CELL_Y];
  neighbours[1] = world[(CELL_X + x) % CELL_X][(CELL_Y + y - 1) % CELL_Y];
  neighbours[2] = world[(CELL_X + x + 1) % CELL_X][(CELL_Y + y - 1) % CELL_Y];
  neighbours[3] = world[(CELL_X + x - 1) % CELL_X][(CELL_Y + y) % CELL_Y];
  neighbours[4] = world[(CELL_X + x + 1) % CELL_X][(CELL_Y + y) % CELL_Y];
  neighbours[5] = world[(CELL_X + x - 1) % CELL_X][(CELL_Y + y + 1) % CELL_Y];
  neighbours[6] = world[(CELL_X + x) % CELL_X][(CELL_Y + y + 1) % CELL_Y];
  neighbours[7] = world[(CELL_X + x + 1) % CELL_X][(CELL_Y + y + 1) % CELL_Y];
}
