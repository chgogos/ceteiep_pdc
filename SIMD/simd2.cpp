// intel compiler
#include <iostream>

using namespace std;

void intrinsics()
{
    int cpuIfo[4]; __cpuid(cpuInfo, 1);
}

int main()
{
    intrinsics();
}
