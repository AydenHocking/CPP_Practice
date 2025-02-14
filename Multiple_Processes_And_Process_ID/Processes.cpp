//Completed by Ayden Hocking


#ifndef Processes_cpp
#define Processes_cpp

#include "Processes.h"


using namespace std;


// Part 1: Working With Process IDs
pid_t getProcessID(void)
{
   // TODO: Add your code here
   pid_t process_id; //create process_id
   process_id = getpid(); //assign process_id to the actual Process ID
   if (process_id != -1){ //checks for correct execution
      return process_id;
   }else{
      return -1;
   }
}


// Part 2: Working With Multiple Processes
string createNewProcess(void)
{
   pid_t id = fork();
   
   process_id = id;
   
   
   if(id == -1)
   {
      return "Error creating process";
   }
   else if (id == 0)
   {
      // TODO: Add your code here
      cout << "I am a child process!"; //print
      cout << "\n"; //formatting
      return "I am bored of my parent, switching programs now"; //return
      cout << "\n"; //formatting
   }
   else
   {
      // TODO: Add your code here
      cout << "I just became a parent!"; //print
      cout << "\n"; //formatting
      int status; //determine child status
      wait(&status); //wait for status change
      return "My child process just terminated!"; //print
   }
}


// Part 3: Working With External Commands"
void replaceProcess(char * args[])
{
   // Spawn a process to execute the user's command.
   pid_t id = fork();
   
   
   // TODO: Add your code here
   if (id == -1){ //check for correct execution
      cout << "Error creating process";
   }else if(id ==0){ // show ls -l execution from fork
      execvp(args[0], args);
   }else{ // wait for child to terminate
      wait(NULL);
   }
}

#endif /* TestProg_cpp */
