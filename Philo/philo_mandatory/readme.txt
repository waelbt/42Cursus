Deadlock is a situation where a set of processes 
are blocked because each process is holding a resource 
and waiting for another resource acquired by some other
process.Process 1 is holding Resource 1 and waiting for
resource 2 which is acquired by process 2, and process 2
is waiting for resource 1.

mutex is a sort of lock around a section of code
(a protection from threads to exucte code at the same time).

pthread_join wait for threads to finish work

pthread_create return value !! 


-g -fsanitize=thread


int	init_mutex(pthread_mutex_t *mutex, int size)
{
	int i;

	i = 0;
	mutex = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * size);
	if (!mutex)
		return (0);
	while (i < size)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	return (1);
}