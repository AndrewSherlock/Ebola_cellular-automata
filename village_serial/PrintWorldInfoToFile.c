#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "Cell.h"
#include "Config.h"
#include "function_prototypes.h"

void PrintWorldInfoToFile(Cell **world, int runNumber)
{
    FILE * file;
    char fileName[80];
    sprintf(fileName, "Files/run_%i.txt", runNumber);

    file = fopen(fileName, "w");

    if(file == NULL)
    {
        printf("No FILE!!!\n\n");
        return;
    }

    for(int y = 0; y < CELL_Y; y++)
    {
        for(int x = 0; x < CELL_Y; x++)
        {
            char cellInfo[50];

            sprintf(cellInfo, "[%i : %i : %i]\n",\
                         world[x][y].x, world[x][y].y, world[x][y].person.currentState);


            fprintf(file, "%s", cellInfo);
        }
    }

    fclose(file);
    char command  [128];
    sprintf(command, "java -jar Image_Printer.jar Files/run_%i.txt %i", runNumber,runNumber);
   
    
 

    system(command);

    
}
/*


   //  pid_t pid = fork();
    // pid = execl("/usr/bin/java", "java","-jar", "Image_Printer.jar", commands[0], commands[1], (char *)0);
    //wait(); // need to child out this process
pid_t   
     int     status;
     int     i;
     char    buf[BUF_SIZE];

     printf("*** Parent is about to fork process 1 ***\n");
     if ((pid1 = fork()) < 0) {
          printf("Failed to fork process 1\n");
          exit(1);
     }
     else if (pid1 == 0) 
          ChildProcess("First", "   ");

     printf("*** Parent is about to fork process 2 ***\n");
     if ((pid2 = fork()) < 0) {
          printf("Failed to fork process 2\n");
          exit(1);
     }
     else if (pid2 == 0) 
          ChildProcess("Second", "      "); */


