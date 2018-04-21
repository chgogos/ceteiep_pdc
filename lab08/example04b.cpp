#include <iostream>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <mutex>
using namespace std;

condition_variable cond_var;
mutex m;

// outputs 100 (correct behavior)
int main() {
    int value = 100;
    bool notified = false;
    thread reporter([&]() {
        unique_lock<mutex> lock(m);
        while (!notified) {
            cond_var.wait(lock);
        }
        cout << "The value is " << value << endl;
    });

    thread assigner([&]() {
        this_thread::sleep_for(chrono::milliseconds(100));
        value = 20;
        notified = true;
        cond_var.notify_one();
    });

    reporter.join();
    assigner.join();
    return 0;
}
