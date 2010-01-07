

class IThreadAdapter
{
public:

  virtual void start() = 0;
  virtual void stop() = 0;
  virtual void pause() = 0;

private
};
