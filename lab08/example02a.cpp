#include <iostream>
#include <vector>
#include <thread>
using namespace std;

int accum = 0;

void square(int tid) {
    for(int i=0;i<10000;i++){
        accum += tid * tid;
    }
}

// possibly incorrect result (race condition)
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
