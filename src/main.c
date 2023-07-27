#include "project.h"

int get_random (int max)
{
   double val;
 
   val = (double) max * rand ();
   val = val / (RAND_MAX + 1.0);
 
   return ((int) val);
}

void *func1(void *arg)
{
	pthread_mutex_t *mutex = (pthread_mutex_t *)arg;
	pthread_mutex_lock(mutex);
	for (int i = 0; i < 10; i++)
	{
		sleep(get_random(2));
		printf("\033[95mthread 1 : %d\033[0m\n", i);
	}
	pthread_mutex_unlock(mutex);
	pthread_exit(NULL);
}

void *func2(void *arg)
{
	pthread_mutex_t *mutex = (pthread_mutex_t *)arg;
	pthread_mutex_lock(mutex);
	for (int i = 0; i < 10; i++)
	{
		sleep(get_random(2));
		printf("\033[91mthread 2 : %d\033[0m\n", i);
	}
	pthread_mutex_unlock(mutex);
	pthread_exit(NULL);
}

int main (void)
{
	pthread_t t1;
	pthread_t t2;
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

	pthread_create(&t1, NULL, func1, (void *)&mutex);
	pthread_create(&t2, NULL, func2, (void *)&mutex);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return (1);
}