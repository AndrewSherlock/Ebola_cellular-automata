ebola_Virus: main.o GenerateCells.o GeneratePerson.o GeneratePopulation.o RunSimulation.o PickSickCells.o PrintWorldInfoToFile.o GetNeighbourProbability.o get_weighted_probability.o Increment_probabilty.o AddInfectionRateForAge.o GetNeighbourCells.o FirstRoundOfInfections.o GetTopLeftCornerCellsNeighbours.o GetTopRightCornerNeighbours.o GetBottomRightCornerNeighbours.o GetRowOfCells.o GetColOfCells.o VacinatePeople.o CheckForImprovement.o InfectionPersonCheck.o
	gcc -o ebola_Virus main.o GenerateCells.o GeneratePerson.o PickSickCells.o GeneratePopulation.o RunSimulation.o PrintWorldInfoToFile.o GetNeighbourProbability.o get_weighted_probability.o Increment_probabilty.o AddInfectionRateForAge.o  GetPersonImprovement.o GetNeighbourCells.o FirstRoundOfInfections.o GetTopLeftCornerCellsNeighbours.o GetTopRightCornerNeighbours.o GetBottomLeftCornerNeighbours.o GetBottomRightCornerNeighbours.o GetRowOfCells.o GetColOfCells.o VacinatePeople.o CheckForImprovement.o InfectionPersonCheck.o NumberOfRowsPerCore.o ThreadSetUp.o RunSectionOfGrid.o -lm -lpthread

Main.o: main.o GenerateCells.o GeneratePerson.o GeneratePopulation.o PickSickCells.o RunSimulation.o Person.h State.h Cell.h Config.h function_prototypes.h
	gcc -c main.c -o main.o -lm

GenerateCells.o: GenerateCells.c Cell.h Person.h function_prototypes.h
	gcc -c GenerateCells.c 

GeneratePerson.o: GeneratePerson.c Person.h function_prototypes.h
	gcc -c GeneratePerson.c

GeneratePopulation.o: GeneratePopulation.c Config.h Cell.h function_prototypes.h
	gcc -c GeneratePopulation.c

PickSickCells.o: PickSickCells.c Cell.h Config.h function_prototypes.h GetNeighbourCells.o FirstRoundOfInfections.o GetTopLeftCornerCellsNeighbours.o GetTopRightCornerNeighbours.o GetBottomLeftCornerNeighbours.o GetBottomRightCornerNeighbours.o GetRowOfCells.o GetColOfCells.o
	gcc -c PickSickCells.c -lm

RunSimulation.o: RunSimulation.c Cell.h Config.h PrintWorldInfoToFile.o GetNeighbourProbability.o get_weighted_probability.o Increment_probabilty.o AddInfectionRateForAge.o function_prototypes.h GetPersonImprovement.o VacinatePeople.o CheckForImprovement.o InfectionPersonCheck.o NumberOfRowsPerCore.o ThreadSetUp.o thread_info_t.h RunSectionOfGrid.o WorldVaribles.h
	gcc -c RunSimulation.c -lm -lpthread

GetNeighbourProbability.o: GetNeighbourProbability.c Cell.h Config.h 
	gcc -c GetNeighbourProbability.c

get_weighted_probability.o: get_weighted_probability.c 
	gcc -c get_weighted_probability.c

Increment_probabilty.o: Increment_probabilty.c 
	gcc -c Increment_probabilty.c -lm

PrintWorldInfoToFile.o: PrintWorldInfoToFile.c Cell.h Config.h 
	gcc -c PrintWorldInfoToFile.c
AddInfectionRateForAge.o: AddInfectionRateForAge.c Config.h
	gcc -c AddInfectionRateForAge.c
GetPersonImprovement.o: GetPersonImprovement.c Config.h Person.h
	gcc -c GetPersonImprovement.c
GetNeighbourCells.o: GetNeighbourCells.c Cell.h Config.h
	gcc -c GetNeighbourCells.c
FirstRoundOfInfections.o: FirstRoundOfInfections.c Cell.h function_prototypes.h
	gcc -c FirstRoundOfInfections.c
GetTopLeftCornerCellsNeighbours.o: GetTopLeftCornerCellsNeighbours.c Cell.h Config.h
	gcc -c GetTopLeftCornerCellsNeighbours.c
GetTopRightCornerNeighbours.o: GetTopRightCornerNeighbours.c Cell.h Config.h
	gcc -c GetTopRightCornerNeighbours.c
GetBottomLeftCornerNeighbours.o: GetBottomLeftCornerNeighbours.c Cell.h Config.h
	gcc -c GetBottomLeftCornerNeighbours.c
GetBottomRightCornerNeighbours.o: GetBottomRightCornerNeighbours.c Cell.h Config.h
	gcc -c GetBottomRightCornerNeighbours.c
GetRowOfCells.o: GetRowOfCells.c Cell.h Config.h
	gcc -c GetRowOfCells.c
GetColOfCells.o: GetColOfCells.c Cell.h Config.h
	gcc -c GetColOfCells.c
VacinatePeople.o: VacinatePeople.c Cell.h Config.h
	gcc -c VacinatePeople.c -lm
CheckForImprovement.o: CheckForImprovement.c Cell.h Person.h function_prototypes.h
	gcc -c CheckForImprovement.c -lm
InfectionPersonCheck.o: InfectionPersonCheck.c Cell.h
	gcc -c InfectionPersonCheck.c -lm
NumberOfRowsPerCore.o: NumberOfRowsPerCore.c Config.h
	gcc -c NumberOfRowsPerCore.c
ThreadSetUp.o: ThreadSetUp.c Config.h Cell.h function_prototypes.h 
	gcc -c ThreadSetUp.c
RunSectionOfGrid.o: RunSectionOfGrid.c Cell.h function_prototypes.h Config.h
	gcc -c RunSectionOfGrid.c
