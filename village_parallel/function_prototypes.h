#include "Cell.h"
#include "thread_info_t.h"

void GeneratePopulation(Cell **);
void RunSimulation(Cell **);
extern void PrintWorldInfoToFile(Cell**, int);
void GeneratePerson(Person *);
void GenerateCells(Cell **, int, int);
void RunSimulation(Cell **);
extern int GetNeighbourProbability(Cell[], int);
extern int get_weighted_probability(int, int); 
int Increment_probabilty(int, int, int);
void PickSickCells(Cell **);
extern float AddInfectionRateForAge(int);
int GetPersonImprovement(Person *);
void GetNeighbourCells(Cell **, Cell *, int, int);
int FirstRoundOfInfections(Cell **, int, int, int);
void GetTopLeftCornerCellsNeighbours(Cell **, Cell *, Cell, int);
void GetTopRightCornerNeighbours(Cell **, Cell *, Cell, int);
void GetBottomLeftCornerNeighbours(Cell **, Cell *, Cell, int);
void GetBottomRightCornerNeighbours(Cell **, Cell *, Cell, int);
void GetRowOfCells(Cell **, Cell *, Cell, int, int);
void GetColOfCells(Cell **, Cell *, Cell, int, int);
int VacinatePeople(Cell **, int);
int CheckForImprovement(Cell **, Cell **, int, int);
int InfectionPersonCheck(Cell **, Cell **, int, int);
int NumberOfRowsPerCore(int);
void ThreadSetUp(Cell **, Cell **, thread_info_t *);
void* RunSectionOfGrid(void *);
