#pragma once

using namespace System::Threading;

ref class WindowsThread
{
private:
  Thread^ trd;
  ThreadStart^ myThreadDelegate;

public:
  WindowsThread(ThreadStart^ thread_delegate) : myThreadDelegate(thread_delegate) {};
  ~WindowsThread(void);

  virtual void start();
  virtual void terminate();
  virtual void suspend();
  virtual void resume();
  Thread^ get_instance(){
    return trd;
  };
};
