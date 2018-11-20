#include "Config.h"

int NumberOfRowsPerCore(int cores)
{
  int rows = CELL_Y/ cores;
  return rows;
}
