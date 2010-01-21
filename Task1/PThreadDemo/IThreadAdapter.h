enum ThreadState {CREATED, READY, RUNNING, SUSPENDED, TERMINATED}

class IThreadAdapter
{
public:

  virtual int start() = 0;
  virtual int terminate() = 0;
  virtual int suspend() = 0;
  virtual int resume() = 0;

protected:
  ThreadState state;
};
