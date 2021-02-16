// http://igoro.com/archive/gallery-of-processor-cache-effects/


#include <iostream>
#include <cstdlib>
#include <chrono>

int main()
{
    int Length = 64 * 1024 * 1024;
    int *arr = new int[Length];

    // Loop 1
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < Length; i++)
        arr[i] *= 3;
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;
    std::cout << "Time passed 1: " << duration.count() << std::endl;

    // Loop 2
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < Length; i += 16)
        arr[i] *= 3;
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Time passed 2: " << duration.count() << std::endl;

    return 0;
}