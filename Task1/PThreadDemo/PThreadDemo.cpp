// PThreadDemo.cpp: Hauptprojektdatei.

#include "stdafx.h"
#include <phthread.h>
#define NUM_THREADS 5

using namespace System;

static void *PrintHello(void) 
{
    long tid = 255;
    //tid = (long)threadid;
    printf("Hello World! It's me thread #%ld!\n", tid);
    //pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  //Thread* threads[NUM_THREADS];
  ThreadDelegate thread_delegate = new ThreadDelegate(PrintHello);
  IThreadAdapter* thread = new WindowsThread(thread_delegate);
  int rc;
  long t;
  for(t=0;t<NUM_THREADS;t++)
  {
    printf("In main: creating thread %\n", t);
//ThreadAdapter thread(&threads[t], NULL, PrintHello, (void*)t); // from old posix stuff
    IThreadAdapter* thread = new WindowsThread(thread_delegate);
    thread.start();
    if(rc) {
      printf("ERROR: return code of pthread_create is %d\n", t);
      exit(-1);
    }
  }
}
