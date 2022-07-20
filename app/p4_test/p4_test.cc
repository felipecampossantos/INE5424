// EPOS Scheduler Test Program

#include <machine/display.h>
#include <time.h>
#include <synchronizer.h>
#include <process.h>

using namespace EPOS;

Thread *thread[6];

OStream cout;

int CPU_bound();
int IO_bound();

int main()
{
  cout << "PMS Scheduler test" << endl;

  cout << "Creating CPU threads" << endl;
  thread[0] = new Thread(&CPU_bound);
  thread[1] = new Thread(&CPU_bound);
  thread[2] = new Thread(&CPU_bound);

  cout << "Creating IO threads" << endl;
  thread[3] = new Thread(&IO_bound);
  thread[4] = new Thread(&IO_bound);
  thread[5] = new Thread(&IO_bound);

  cout << "Threads created!" << endl;

  for (int i = 0; i < 6; i++)
  {
    thread[i]->join();

    if (i < 3)
      cout << "IO Bound Thread " << thread[i] << " finished with type: " << thread[i]->type() << endl;
    else
      cout << "CPU Bound Thread " << thread[i] << " finished with type: " << thread[i]->type() << endl;
  }

  for (int i = 0; i < 6; i++)
  {
    delete thread[i];
  }

  return 0;
}

int CPU_bound()
{
  cout << "CPU bound process... " << endl;

  int n1 = 0, n2 = 1, result;
  for (size_t i = 0; i < 3000; i++)
  {
    if (i <= 1)
      result = i;
    else
    {
      result = n1 + n2;
      n1 = n2;
      n2 = result;
    }
  }

  cout << "Fibonacci of " << 10 << " is " << result << endl;
  return 0;
}

int IO_bound()
{
  for (size_t i = 0; i < 4; i++)
  {
    cout << "IO bound process -> Alarm::delay()" << endl;

    Alarm::delay(10000);

    cout << "IO bound process | Done waiting. " << endl;
  }

  return 0;
}