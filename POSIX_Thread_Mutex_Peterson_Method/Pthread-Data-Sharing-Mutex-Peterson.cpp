#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#define FALSE 0 //added to indicate false
#define TRUE 1 //added to indicate true
#define TOTAL_THREADS 2

int count;
int turn;                  // Shared variable, indicates
                           // whose turn it is to execute

bool interested[TOTAL_THREADS];  // Shared variable, indicates
                                 // processes interested in executing

// The thread_id will be either 0 or 1
void enter_region(int thread_id)
{
   int other;                       // ID of the other thread
   
   other = 1 - thread_id;           // The opposite of thread_id
   
   // Add the code to indicate the thread's interest in executing.
   interested[thread_id] = TRUE; //shows interest is true

   
   // Indicate the thread's turn to execute next
   turn = thread_id; //make thread_id the next turn to execute
   
   // Busy wait until it is the thread's turn to execute
   while(turn == thread_id && interested[other] == TRUE); //waits until current turn is finished
   
}


void leave_region(int thread_id)
{
   // Add the code to set the flag indicating that the thread has exited the critical region.
   interested[thread_id] = FALSE; // removes itnerest from thread_id
   
}


void* myFunction(void* arg)
{
	int thread_id = *((int*) arg);
    
	for(unsigned int i = 0; i < 10; ++i) {

      enter_region(thread_id); //func call to enter_region     

      //  Beginning of the critical region
        
      count++;
      std::cout << "Thread #" << thread_id << " count = " << count << std::endl;
      
      //  End of the critical region
      
      leave_region(thread_id); //func call to leave_region  

      //  Random wait - This code is just to ensure that the threads
      //  show data sharing problems
      int max = rand() % 1000000;
      
      for (int x = 0; x < max; x++);
      
      // End of random wait code
	}
    
	pthread_exit(NULL);
}

int main()
{
    int rc[TOTAL_THREADS];
    pthread_t ids[TOTAL_THREADS];
    int args[TOTAL_THREADS];
    
    count = 0;
    for(unsigned int i = 0; i < TOTAL_THREADS; ++i) {
        args[i] = i;
        rc[i] = pthread_create(&ids[i], NULL, myFunction, (void*) &args[i]);
    }
    
    for(unsigned int i = 0; i < TOTAL_THREADS; ++i) {
        pthread_join(ids[i], NULL);
    }
    
    std::cout << "Final count = " << count << std::endl;
    pthread_exit(NULL);
}
