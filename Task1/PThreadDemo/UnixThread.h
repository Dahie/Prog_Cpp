#pragma once

class UnixThread
{
public:
  UnixThread(void);
  ~UnixThread(void);

  virtual int start();
  virtual int terminate();
  virtual int suspend();
  virtual int resume();
};
