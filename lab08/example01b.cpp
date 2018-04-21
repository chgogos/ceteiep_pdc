#include <iostream>
#include <thread>
using namespace std;

// thread creation using lambda function
int main() {
  int tid = 123;
  thread th([&tid]() {
    cout << "Message from thread " << tid << " (" << this_thread::get_id()
         << ")" << endl;
  });
  th.join();
  cout << "Message from the main thread" << endl;
  return 0;
}
