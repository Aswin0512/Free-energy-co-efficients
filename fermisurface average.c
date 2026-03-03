#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.141592

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
    float thetastep=PI/(4*(n-1));
    float E=0;
    float Etolc=1;
    float k=0;
    float theta=0;
    float kx=0;
    float ky=0;
    for (int i = 0; i < n; i++)
    {
        theta=i*thetastep;
        k=0;
        while (Etolc<=Etol)
        {   
            kx=k*cos(theta);
            ky=k*sin(theta);
            E=Energy(kx,ky);
            Etolc=fabs(E-Ev); 
        }
    }
    
}


int main(){

}