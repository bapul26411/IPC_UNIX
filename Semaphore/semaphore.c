#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
sem_t sem;
int counter=0;
void* handler (void *ptr)
	{
	int x;
	x= *((int*)ptr);
	printf("\nthread %d: wait to eneter critical section", x);
	sem_wait(&sem);
	
	printf("\nthread %d: now critical section", x);
	printf("\ncurrent counter value: %d", counter);
	counter++;
	printf("\nnew counter value: %d", counter);
	sem_post(&sem);
	printf("\nthread %d exit critical section...", x);
	
	pthread_exit(0);
	}
	
int main()
{
int i[2]= {0, 1};
pthread_t id1, id2;
sem_init(&sem, 0, 1);
pthread_create(&id1, NULL, handler, (void *)&i[0]);
pthread_create(&id2, NULL, handler, (void *)&i[1]);

pthread_join(id1, NULL);
pthread_join(id2, NULL);

sem_destroy(&sem);
exit(0);
return 0;
}
