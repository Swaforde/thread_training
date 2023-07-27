#ifndef THREAD_H
# define THREAD_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_store {
    int stock;

    pthread_t store_thread;
    pthread_t *clients_threads;
} t_store;

void thread(void);

#endif