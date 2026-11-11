// Whack-a-Mole: n producer threads each create a mole and put it in an
// MT-safe queue; n consumer threads each take a mole out and whack it.
// produce and consume communicate only through the queue.
//
// The queue's capacity (max) limits how many unwhacked moles can wait,
// so producers stall ("congestion") when consumers fall behind.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "lawn.h"
#include "mole.h" 
#include "mtq.h"
#include "thread.h"

// Each thread gets arg: arg[0] is the Mtq, arg[1] is the Lawn.

static void *produce(void *a) {
  void **arg=a;
  Mtq q=(Mtq)arg[0];
  Lawn l=(Lawn)arg[1];
  mtq_tail_put(q,mole_new(l,0,0));
  return 0;
}

static void *consume(void *a) {
  void **arg=a;
  Mtq q=(Mtq)arg[0];
  mole_whack(mtq_head_get(q));  // mole_whack() frees the mole
  return 0;
}

int main() {
  srandom(time(0));
  const int n=10;               // moles; must match producers and consumers
  const int max=4;              // queue capacity; 0 means unbounded

  Lawn lawn=lawn_new(0,0);
  Mtq q=mtq_new(max);
  void *arg[]={q,lawn};         // on main's stack: safe, we join below

  Threads producers=threads_create(n,produce,arg);
  Threads consumers=threads_create(n,consume,arg);
  threads_join(producers);
  threads_join(consumers);

  mtq_free(q);
  lawn_free(lawn);
  return 0;
}