#include <chrono>
#include <future>
#include <iostream>
#include <vector>

using namespace std;

int work(int tid) {
  cout << "Message from thread " << tid << " (sleeping for 5 seconds)" << endl;
  this_thread::sleep_for(chrono::seconds(5));
  return 42;
}

int main() {
  auto a = async(&work, 1);
  // future<int> a = async(&work, 1);
  cout << "Message 1 from the main thread " << endl;
  int v = a.get();
  cout << "The thread returned " << v << endl;
  cout << "Message 2 from the main thread " << endl;
  return 0;
}
