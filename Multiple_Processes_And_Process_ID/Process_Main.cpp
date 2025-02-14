#include <stdio.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sstream>
#include <fstream>
#include <sys/stat.h>
#include <fcntl.h>
#include "Processes.h"


using namespace std;


pid_t process_id;


int main(void)
{
   // Call the user-defined function that retrieves the process ID
   cout << "Part 1: Working With Process IDs" << endl;
   cout << "Process ID: " << getProcessID() << endl;
   cout << endl << endl;
   
   
   // Call the user-defined function that creates a new process
   cout << "Part 2: Working With Multiple Processes" << endl;
   cout << createNewProcess() << endl;
   cout << endl << endl;
   

   // Call the function that call an external OS command
   if (process_id != 0)
   {
      cout << "Part 3: Working With External Commands" << endl;
      char * args[3] = {(char * )"ls", (char * )"-l", NULL};
      
      replaceProcess(args);
      
      cout << endl;
   }

   
   return 0;
}



