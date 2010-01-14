#include "StdAfx.h"
#include "UnixThread.h"

UnixThread::UnixThread(void)
{
}

UnixThread::~UnixThread(void)
{
}


int UnixThread::start()
{
  return pthread_create(&threads[t], NULL, PrintHello, (void*)t);
}

int UnixThread::terminate()
{
}


int UnixThread::suspend()
{
}