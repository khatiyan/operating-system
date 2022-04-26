#include <stdio.h>
#include <string.h>
#include <pthread.h>

// Global variable:
int i = 3;

void* foo(void* p){
  // Print value received as argument:
  printf("Value recevied as argument in starting routine: ");
  printf("%i\n", * (int*)p);
  i++;
  // Return reference to global variable:
  pthread_exit(&i);
}
void* hoo(void* p){
  // Print value received as argument:
  printf("Value recevied as argument in starting routine: ");
  printf("%i\n", * (int*)p);
  i--;
  // Return reference to global variable:
  pthread_exit(&i);
}

int main(void){
  // Declare variable for thread's ID:
  pthread_t id1=1;
  pthread_t id2=2;

  int j = 1,k=2;
 int* ptr1;
int* ptr2;
  pthread_create(&id1, NULL, foo, &j);
pthread_join(id1, (void**)&ptr1);
 printf("Value recevied by parent from child: ");
  printf("%i\n", *ptr1);
  pthread_create(&id2, NULL, hoo, &k);
    
 

  // Wait for foo() and retrieve value in ptr;
  
pthread_join(id2, (void**)&ptr2);
  printf("Value recevied by parent from child: ");
  //printf("%i\n", *ptr1);
 printf("%i\n", *ptr2);
}
