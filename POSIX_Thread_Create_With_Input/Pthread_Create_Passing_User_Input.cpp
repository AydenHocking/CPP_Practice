// Ayden Hocking 1/30/25
#include <pthread.h>
#include <iostream>

using namespace std;

void *PrintHello(void *arg)
{
   int actual_arg = *((int*) arg);
   cout << "Hello World from thread with arg: " << actual_arg << "!\n";
   return 0;
}

int main()
{
   pthread_t id;
   int rc;
   int t; //number 
   cout << "Input number: ";
   cin >> t; //user input
   cout << "In main: creating thread \n";
   //int t = 23;
   rc = pthread_create(&id, NULL, PrintHello, (void*) &t); //pthread create with new input

   if (rc){
      cout << "ERROR; return code from pthread_create() is " << rc << std::endl;
      return -1;
   }

   pthread_exit(0);
}
