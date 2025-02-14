// Ayden Hocking 1/30/25
#include <pthread.h>
#include <iostream>

using namespace std;


// This function shows the skeleton that pthread 
// functions must adhere to. 
const char* my_messages[4] = {"Italian: Ciao!", 
	"English: Hello!", "Hindi: Namaste!", 
	"Spanish: Hola!" }; //my_messages array
void *printMessage(void *arg)
{
   cout << "Thread is running..." << endl;
   int index = *(int *)arg; //typecast for index from void 
   cout << my_messages[index] << endl; //output each index in array
   return 0;
}


int main()
{
   // id is used to store a unique thread identifier,
   // returned by the call to create a new POSIX thread
   pthread_t id;
   int arr[4]; //array of indices for unique index
   
   // rc is used to store the code returned by the
   // call to create a new POSIX thread. The value is
   // zero (0) if the call succeeds.
   int rc;
   
   for (int index = 0; index < 4; index++)
   {
      arr[index] = index; //assigns each pthread to new position
      rc = pthread_create(&id, NULL, printMessage,(void*) &arr[index]);// creates pthread with the array parameter to display correctly 
   }

   if (rc){
      cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
   }
   

   // NOTE: Using exit here will immediately end execution of all threads
   pthread_exit(0);
}
