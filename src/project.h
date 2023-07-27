#ifndef THREAD_H
# define THREAD_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_store {
    int stock;
    pthread_t store_thread;
    pthread_t clients_threads[5];
} t_store;

#endif