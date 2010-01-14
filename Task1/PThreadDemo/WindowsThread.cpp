#include "StdAfx.h"
#include "WindowsThread.h"

WindowsThread::WindowsThread(void) // TODO here we have to pass the method that is run in the thread
{
  // what type is a class? Does this have to be done with Templates or with polymorphism

  // there are two ways to call the method in a thread:
  // 1) have a static method and pass the address of this method
  // 2) have an instance of an object, which has a method that shall be run
  myThreadDelegate = new ThreadStart(0, methodname);
}

WindowsThread::~WindowsThread(void)
{
}

void WindowsThread::start()
{
  trd = new Thread(myThreadDelegate);
  trd->Start();
}

void UnixThread::terminate()
{
  trd->Abort();
}


void UnixThread::suspend()
{
  trd->Suspend();
}

void UnixThread::resume()
{
  trd->Resume();
}