enum ThreadState {CREATED, READY, RUNNING, SUSPENDED, TERMINATED}

ref class IThreadAdapter
{
public:

  virtual void start() = 0;
  virtual void terminate() = 0;
  virtual void suspend() = 0;
  virtual void resume() = 0;

protected:
  ThreadState state;
};
