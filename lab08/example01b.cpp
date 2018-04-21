#include <iostream>
#include <thread>
using namespace std;

// thread creation using lambda function
int main() {
    thread th([](){
            cout << "Message from thread" << endl;
    });
    th.join();
    cout << "Message from the main thread" << endl;
    return 0;
}
