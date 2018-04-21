#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

int accum = 0;
mutex accum_mutex;

void square(int tid) {
    for(int i=0;i<10000;i++){
        accum_mutex.lock();
        accum += tid * tid;
        accum_mutex.unlock();
    }
}

// correct result (mutex)
int main() {
    vector<thread> ths;
    for (int tid = 1; tid <= 20; tid++) {
        ths.push_back(thread(&square, tid));
    }

    for (auto& th : ths) {
        th.join();
    }
    cout << "accum = " << accum << endl;
    return 0;
}
