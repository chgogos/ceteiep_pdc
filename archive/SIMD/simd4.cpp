// https://www.youtube.com/watch?v=ee932A3iJwc

#include <iostream>
#include <immintrin.h>

using namespace std;

int main(){
    __m256 evens = _mm256_set_ps(2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0);
    __m256 odds = _mm256_set_ps(1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0);

    __m256 result = _mm256_sub_ps(evens, odds);

    float *f =(float*)&result;

    for(int i=0;i<8;i++){
        cout << f[i] << " ";
    }
    cout << endl;

    return 0;
}
