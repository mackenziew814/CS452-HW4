#ifndef MTQ_H
#define MTQ_H

// An MT-safe wrapper around the (MT-unsafe) deq module.
//
// One mutex protects each queue. Two condition variables let threads
// sleep, instead of spinning, until the queue changes:
//   - get blocks while the queue is empty.
//   - put blocks while the queue is full (only when max>0).
//
// mtq_new(max): max is the capacity; 0 means unbounded.
// mtq_free(q): frees the queue. No thread may still be using it,
// and any data left in the queue is not freed.

#include "deq.h"                // for Data

typedef void *Mtq;

extern Mtq  mtq_new(int max);
extern void mtq_free(Mtq q);
extern int  mtq_len(Mtq q);

extern void mtq_head_put(Mtq q, Data d);
extern Data mtq_head_get(Mtq q);

extern void mtq_tail_put(Mtq q, Data d);
extern Data mtq_tail_get(Mtq q);

#endif