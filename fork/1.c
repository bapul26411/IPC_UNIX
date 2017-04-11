#include <stdio.h>
#include <stdlib.h>

int main()
{
pid_t id;

id= fork();

if(id==0)
	{
	printf("\nChld process id: %d", getpid());
	}
	else if(id == -1)	
	{
	printf("\nParent process id: %d", getppid());
	}
	else	
	{
	printf("\nother");
	}
	
return 0;
}
