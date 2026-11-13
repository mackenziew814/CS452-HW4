#ifndef THREAD_H
#define THREAD_H

// A small module for running a function in several threads at once.

typedef void *Threads;
typedef void *(*ThreadF)(void *arg);

extern Threads threads_create(int n, ThreadF f, void *arg); // ThreadF is the type of a function that can be run in a thread.
extern void threads_join(Threads t); // Waits for all threads in the group to finish, then frees the group.


#endif