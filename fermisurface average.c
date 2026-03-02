#include<stdio.h>
#include<math.h>

//To calculate the fermi surface average of different functions

// Dispersion relation
float Energy(float kx,float ky){
    float E=(kx*kx+ky*ky)/2;
    return E;
}
//Magnitude of the gradient of Energy
float MdelEnergy(float kx,float ky){
    float MdelE=sqrt(kx*kx+ky*ky);
    return MdelE;
}

//function to find the points on a fermi curve
float surface(float Ev,float Etol,int n){
    float kstep=Etol/sqrt(2*Ev);
    float thetastep=
}


int main(){

}