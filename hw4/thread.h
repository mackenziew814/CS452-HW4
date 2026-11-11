#ifndef THREAD_H
#define THREAD_H

// A small module for running a function in several threads at once.
//
// threads_create() starts n new threads, each calling f(arg).
// threads_join() waits for all of them to finish, then frees the group.
// Every group returned by threads_create() must be passed to
// threads_join() exactly once.

typedef void *Threads;
typedef void *(*ThreadF)(void *arg);

extern Threads threads_create(int n, ThreadF f, void *arg);
extern void    threads_join(Threads t);

#endif