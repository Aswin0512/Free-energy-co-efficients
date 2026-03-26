#include<iostream>
#include<string>
#include<cmath>

using namespace std;

float Energy(float kx,float ky){
    float E=-(cos(kx)+cos(ky));
    return E;
}
//function inside the integral
float fintegral(float kx,float ky){
    float f=ky*ky/(kx*kx+ky*ky);
    return f;
}

//function to find the points on a fermi curve
float *surface(float Ev,float Etol,int n){

    float kstep=Etol/sqrt(2*Ev); // value with which k is incremented
    //float kstep=0.001;
    float thetastep=M_PI/(4*n); // value with which theta is incremented

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
    
    float **surpnts= new float*[8*n];// Initialising the 2D array to store the points on Fermi surface
    
    for (int i = 0; i < n+1; i++)
    {
        surpnts[i]=new float[2];
        if (i!=n)
        {
            for (int j = 1; j < 9 ; j++)
            {
                surpnts[j*n+1]=new float[2];
            }
            
        }

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
                if (Etolc>Etol)
                {
                    printf("Calculated tolerance is greater\n");
                    return nullptr;
                }
            }
            else
            {
                surpnts[i][0]=kxp;
                surpnts[i][1]=kyp;
                tolflag=1;
                if (Etolcp>Etol)
                {
                    printf("Calculated tolerance is greater\n");
                    return nullptr;
                }
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

int main(){
    float kx,ky,E;
    cout << "Enter kx,ky\n";
    cin >> kx;
    cin >> ky;

    E=Energy(kx,ky);
    cout << E<<"\n";
    return 0;

}