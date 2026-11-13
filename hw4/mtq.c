// MT-safe queue, wraps a Deq with one mutex and two condition variables

#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "mtq.h"
#include "error.h"

typedef struct {
  Deq q;                        // the wrapped, MT-unsafe queue
  int max;                      // capacity, 0 means unbounded
  pthread_mutex_t lock;         // protects q
  pthread_cond_t notEmpty;      // signaled after a put
  pthread_cond_t notFull;       // signaled after a get
} *Rep;

// pthread functions return an error number
#define CHECK(call) do {                                \
  int err=(call);                                       \
  if (err) ERROR("%s failed: %s",#call,strerror(err));  \
} while (0)

static Rep rep(Mtq q) {
  if (!q) ERROR("null Mtq");
  return (Rep)q;
}

extern Mtq mtq_new(int max) {
  if (max<0) ERROR("mtq_new(): negative capacity: %d",max);
  Rep r=(Rep)malloc(sizeof(*r));
  if (!r) ERROR("malloc() failed");
  r->q=deq_new();
  r->max=max;
  CHECK(pthread_mutex_init(&r->lock,0));
  CHECK(pthread_cond_init(&r->notEmpty,0));
  CHECK(pthread_cond_init(&r->notFull,0));
  return r;
}

extern void mtq_free(Mtq q) {
  Rep r=rep(q);
  CHECK(pthread_cond_destroy(&r->notFull));
  CHECK(pthread_cond_destroy(&r->notEmpty));
  CHECK(pthread_mutex_destroy(&r->lock));
  deq_del(r->q,0);
  free(r);
}

extern int mtq_len(Mtq q) {
  Rep r=rep(q);
  CHECK(pthread_mutex_lock(&r->lock));
  int len=deq_len(r->q);
  CHECK(pthread_mutex_unlock(&r->lock));
  return len;
}

// Shared put/get logic. f is the deq function for the chosen end.
// The waits are in while loops, because a woken thread must recheck
// its condition

static void put(Rep r, void (*f)(Deq,Data), Data d) {
  CHECK(pthread_mutex_lock(&r->lock));
  while (r->max && deq_len(r->q)>=r->max)
    CHECK(pthread_cond_wait(&r->notFull,&r->lock));
  f(r->q,d);
  CHECK(pthread_cond_signal(&r->notEmpty));
  CHECK(pthread_mutex_unlock(&r->lock));
}

static Data get(Rep r, Data (*f)(Deq)) {
  CHECK(pthread_mutex_lock(&r->lock));
  while (deq_len(r->q)==0)
    CHECK(pthread_cond_wait(&r->notEmpty,&r->lock));
  Data d=f(r->q);
  CHECK(pthread_cond_signal(&r->notFull));
  CHECK(pthread_mutex_unlock(&r->lock));
  return d;
}

extern void mtq_head_put(Mtq q, Data d) {        put(rep(q),deq_head_put,d); }
extern Data mtq_head_get(Mtq q)         { return get(rep(q),deq_head_get);   }

extern void mtq_tail_put(Mtq q, Data d) {        put(rep(q),deq_tail_put,d); }
extern Data mtq_tail_get(Mtq q)         { return get(rep(q),deq_tail_get);   }