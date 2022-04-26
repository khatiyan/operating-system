#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main( void ) {
	char *argv[] = {"./fork1",NULL};

	int pid = fork();

	if ( pid == 0 ) {
  printf("hello\n");
		execvp(argv[0],argv);
	}
   else
{

	/* Put the parent to sleep for 2 seconds--let the child finished executing */
	sleep( 2 );

	printf( "Finished executing the parent process\n"
	        " - the child won't get here--you will only see this once\n" );
}
	return 0;
}
