#include<iostream>
#include<cmath>

using namespace std;

float *ar(int n){
    float* a= new float[n];

    //for (int i = 0; i < n; i++)
    //{
    //    a[i]=i;
    //}
    return a;
    

}
int main(){

    
    int n=4;

    float *data;
    data=ar(n);
    cout << data[1] <<"\n";
    delete[] data;
    data=nullptr;
    
    
    }