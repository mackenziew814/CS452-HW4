#ifndef MTQ_H
#define MTQ_H

// An MT-safe wrapper around the deq module.
//
// One mutex protects each queue. Two condition variables let threads
// sleep, instead of spinning, until the queue changes:
//   - get blocks while the queue is empty.
//   - put blocks while the queue is full (only when max>0).


#include "deq.h"                

typedef void *Mtq;

extern Mtq mtq_new(int max); // Create an empty queue, max is the capacity (0 = unbounded)
extern void mtq_free(Mtq q); // Free the queue (no thread may still be using it)
extern int mtq_len(Mtq q); // Return the number of items currently in the queue

extern void mtq_head_put(Mtq q, Data d); // Add d at the head, blocks while the queue is full
extern Data mtq_head_get(Mtq q); // Remove and return the head item, blocks while empty

extern void mtq_tail_put(Mtq q, Data d); // Add d at the tail, blocks while the queue is full
extern Data mtq_tail_get(Mtq q); // Remove and return the tail item, blocks while empty

#endif