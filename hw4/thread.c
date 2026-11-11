// Thread module: run a function n times, in n new threads,
// and later wait for all of them to finish.

#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "thread.h"
#include "error.h"

typedef struct {
  int n;                        // number of threads in the group
  pthread_t *tids;              // their ids, for pthread_join()
} *Rep;

extern Threads threads_create(int n, ThreadF f, void *arg) {
  if (n<0) ERROR("threads_create(): negative thread count: %d",n);
  if (!f) ERROR("threads_create(): null function");

  Rep r=(Rep)malloc(sizeof(*r));
  if (!r) ERROR("malloc() failed");
  r->n=n;
  r->tids=(pthread_t *)malloc(n*sizeof(*r->tids));
  if (n && !r->tids) ERROR("malloc() failed");

  // pthread functions return an error number, rather than setting errno.
  for (int i=0; i<n; i++) {
    int err=pthread_create(&r->tids[i],0,f,arg);
    if (err) ERROR("pthread_create() failed: %s",strerror(err));
  }
  return r;
}

extern void threads_join(Threads t) {
  Rep r=(Rep)t;
  if (!r) ERROR("threads_join(): null thread group");
  for (int i=0; i<r->n; i++) {
    int err=pthread_join(r->tids[i],0);
    if (err) ERROR("pthread_join() failed: %s",strerror(err));
  }
  free(r->tids);
  free(r);
}