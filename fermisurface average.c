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
float surface(float Ev,float Etol,int n,float surpnts[8*n][2]){
    float kstep=Etol/sqrt(2*Ev); // value with which k is incremented
    float thetastep=PI/(4*n); // value with which theta is incremented

    //Initialising different variables
    float E=0; // E-Energy
    float Etolc=0;// Etolc-Calculated value of tolerance in E
    float Etolcp=0;
    float k=0;// k-Radial co-ordinate
    float theta=0;// theta-Polar angle
    float cs,sn=0;
    float kx,ky=0;// x and y components respectively
    float kxp,kyp=0;
    int tolflag=0; // varialble to flag when we reach minimum error
    
    
    
    for (int i = 0; i < n+1; i++)
    {
        theta=i*thetastep;
        cs=cos(theta);
        sn=sin(theta);
        k=0;
        tolflag=0;
        Etolcp=fabs(Ev)+1;
        kxp,kyp=0;
    
        while (tolflag==0)
        {   
            kx=k*cs;
            ky=k*sn;
            E=Energy(kx,ky);
            Etolc=fabs(E-Ev);

            if (Etolcp-Etolc>0)
            {
                k=k+kstep;
                Etolcp=Etolc;
                kxp=kx;
                kyp=ky;
            }
            else if (Etolcp-Etolc==0)
            {
                kx=kx-(kstep/2)*cs;
                ky=ky-(kstep/2)*sn;
                surpnts[i][0]=kx;
                surpnts[i][1]=ky;
                tolflag=1;

            }
            else
            {
                surpnts[i][0]=kxp;
                surpnts[i][1]=kyp;
                tolflag=1;
            }
            
        }
    }

    float kx1,kx2,kx3,kx4,kx5,kx6,kx7,kx8=0;
    float ky1,ky2,ky3,ky4,ky5,ky6,ky7,ky8=0;
    int i2,i3,i4,i5,i6,i7,i8=0;

    // Using symmetries to find points on the rest of the fermi surace
    for (int i = 0; i < n+1; i++)
    {
        kx1=surpnts[i][0];
        ky1=surpnts[i][1];
        //Reflection about 45 degree line
        kx2=ky1;
        ky2=kx1;
            
        i2=2*n-i;

        surpnts[i2][0]=kx2;
        surpnts[i2][1]=ky2;

            
        //Reflection about y axis
        kx3=-kx2;
        ky3=ky2;

        i3=4*n-i2;

        surpnts[i3][0]=kx3;
        surpnts[i3][1]=ky3;

        kx4=-kx1;
        ky4=ky1;

        i4=4*n-i;

        surpnts[i4][0]=kx4;
        surpnts[i4][1]=ky4;

        //Reflection about x axis
        kx5=kx4;
        ky5=-ky4;

        i5=8*n-i4;

        surpnts[i5][0]=kx5;
        surpnts[i5][1]=ky5;

        kx6=kx3;
        ky6=-ky3;

        i6=8*n-i3;

        surpnts[i6][0]=kx6;
        surpnts[i6][1]=ky6;

        kx7=kx2;
        ky7=-ky2;

        i7=8*n-i2;

        surpnts[i7][0]=kx7;
        surpnts[i7][1]=ky7;

        if (i!=0)
        {
           kx8=kx1;
           ky8=-ky1;
           
           i8=8*n-i;
           
           surpnts[i8][0]=kx8;
           surpnts[i8][1]=ky8;

        }
           
    }   
    
}


int main(int argc,char *argv[]){

    int n=100;
    float surfdata[8*n][2];
    float Ev=3;
    float Etol=0.01;

    surface(Ev,Etol,n,surfdata);

    char filename[25];
    sprintf(filename,"spherical_%.2f_%d.txt",Ev,n);

    FILE *fptr;
    fptr=fopen(filename,"w");

    for (int i = 0; i < 8*n; i++)
    {
        fprintf(fptr,"%f\t%f\n",surfdata[i][0],surfdata[i][1]);
    }
    
    fclose(fptr);

    //Integral over the energy surface
    float integralval=0;
    float h=0;
    int i1;
    float kx1,kx2;
    float ky1,ky2;
    for (int i = 0; i < 8*n; i++)
    {   
        i1=i+1-(i+1)*floor(i+1/(8*n));

        kx1,ky1=surfdata[i][0],surfdata[i][1];
        kx2,ky2=surfdata[i1][0],surfdata[i1][1];
        h=sqrt((kx1-kx2)*(kx1-kx2)+(ky1-ky2)*(ky1-ky2));
        integralval=integralval+(1/MdelEnergy(kx1,ky1)+1/MdelEnergy(kx2,ky2))*h/2;

    }
    
    integralval=integralval/pow(2*PI,3);
    printf("value of the integral:\t%.4f\n",integralval);
    

    return 0;
}