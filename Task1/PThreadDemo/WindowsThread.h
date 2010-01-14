#pragma once

#using <mscorlib.dll>

class WindowsThread
{
private:
  Thread* trd;
  ThreadStart *myThreadDelegate;

public:
  WindowsThread(void);
  ~WindowsThread(void);

  virtual int start();
  virtual int terminate();
  virtual int suspend();
  virtual int resume();
};
