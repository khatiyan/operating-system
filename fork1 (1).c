#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h> 

void example()
{
	int x = 1;

	pid_t k = fork();
        if(k==-1)
              printf("error");
        else if (k == 0)
		printf("Child has x = %d\n", ++x);
	else
		printf("Parent has x = %d\n", --x);
}
int main()
{
       example();
	return 0;
}

