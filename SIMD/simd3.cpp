#include <iostream>

void optimization(){
    const int length = 1024*104*64;
    float *a=new float[length];
    float *b=new float[length];
    float *c=new float[length];
    float *result=new float[length];

    mt19937_64 rng(random_device{}());
    uniform_real_distribution<float> dist;

    for(size_t i=0;i<length;i++){
        a[i]=dist(rng);
        b[i]=dist(rng);
        c[i]=dist(rng);
    }

    delete[] a;
    delete[] b;
    delete[] c;
}

int main(){

}