#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

// outputs 100 (incorrect behavior since assigner thread should assign the value
// and then reporter thread should display it)
int main() {
  int value = 100;
  thread reporter([&]() {
    cout << "The value is " << value
         << ((value == 20) ? " (correct)" : " (incorrect)") << endl;
  });

  thread assigner([&]() {
    this_thread::sleep_for(chrono::milliseconds(100));
    value = 20;
  });

  reporter.join();
  assigner.join();
  return 0;
}
