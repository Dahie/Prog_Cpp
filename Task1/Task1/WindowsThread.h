#pragma once

using namespace System::Threading;

ref class WindowsThread
{
private:
  Thread^ trd;
  ThreadStart^ myThreadDelegate;
  ParameterizedThreadStart^ myPThreadDelegate;

public:
  WindowsThread(ThreadStart^ thread_delegate) : myThreadDelegate(thread_delegate) {};
  WindowsThread(ParameterizedThreadStart^ thread_delegate) : myPThreadDelegate(thread_delegate) {};
  ~WindowsThread(void);

  virtual void start();
  virtual void start(Object^ obj);
  virtual void terminate();
  virtual void suspend();
  virtual void resume();
   Thread^ get_instance(){
    return trd;
  };
};
