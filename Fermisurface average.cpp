#include<iostream>
#include<string>
#include<cmath>
#include<fstream>

using namespace std;

float Energy(float kx,float ky){
    float E=-(cos(kx)+cos(ky));
    return E;
}
//function inside the integral
float fintegral(float kx,float ky){
    float f=pow(kx*kx-ky*ky,2);
    return f;
}

//function to find the points on a fermi curve
float **surface(float Ev,float Etol,int n){

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
    int clcnt=0;//count the number of theta steps until first point is found
    int indx=0;//crct indx of the point
    
    float **surpnts= new float*[8*n];// Initialising the 2D array to store the points on Fermi surface

    float kx1,kx2,kx3,kx4,kx5,kx6,kx7,kx8=0;
    float ky1,ky2,ky3,ky4,ky5,ky6,ky7,ky8=0;
    int i2,i3,i4,i5,i6,i7,i8=0;
    
    for (int i = 0; i < n+1; i++)
    {
        surpnts[i]=new float[2];//Creating the columns for kx and ky

        theta=i*thetastep;
        cs=cos(theta);
        sn=sin(theta);
        k=0;

        tolflag=0;
        Etolc=fabs(Ev-Energy(0,0));//Tolerance varibale is initiated
        
        kxp,kyp=0;
    
        
        while (tolflag==0)
        {   

            if (Etolc>Etol)
            {
                k=k+kstep;
                kx=k*cs;
                ky=k*sn;
                if (fabs(kx)>M_PI || fabs(ky)>M_PI)
                {
                    clcnt++;
                    break;
                }
                E=Energy(kx,ky);
                Etolc=fabs(E-Ev);
            }
            else
            {
                here:
                Etolcp=Etolc;
                kxp=kx;
                kyp=ky;

                k=k+kstep;
                kx=k*cs;
                ky=k*sn;

                if (fabs(kx)>M_PI || fabs(ky)>M_PI)//Brillouin zone conditon
                {
                    kx=kxp;
                    ky=kyp;
                    //save points and break

                    break;
                }

                E=Energy(kx,ky);
                Etolc=fabs(E-Ev);

                if(Etolc==Etolcp)
                {
                    kx=(kx+kxp)/2;
                    ky=(ky+kyp)/2;
                    //save points
                }
                else if (Etolc>Etolcp)
                {
                    kx=kxp;
                    ky=kyp;
                    //save points
                }
                else
                {
                    goto here;
                }
                
            }
            
        } 

        // Using symmetries to find points on the rest of the fermi surace
        kx1=surpnts[i][0];
        ky1=surpnts[i][1];
        //Reflection about 45 degree line
        kx2=ky1;
        ky2=kx1;
            
        i2=2*n-i;

        surpnts[i2]=new float[2];

        surpnts[i2][0]=kx2;
        surpnts[i2][1]=ky2;

            
        //Reflection about y axis
        kx3=-kx2;
        ky3=ky2;

        i3=4*n-i2;
        surpnts[i3]=new float[2];

        surpnts[i3][0]=kx3;
        surpnts[i3][1]=ky3;

        kx4=-kx1;
        ky4=ky1;

        i4=4*n-i;
        surpnts[i4]=new float[2];

        surpnts[i4][0]=kx4;
        surpnts[i4][1]=ky4;

        //Reflection about x axis
        kx5=kx4;
        ky5=-ky4;

        i5=8*n-i4;
        surpnts[i5]=new float[2];

        surpnts[i5][0]=kx5;
        surpnts[i5][1]=ky5;

        kx6=kx3;
        ky6=-ky3;

        i6=8*n-i3;
        surpnts[i6]=new float[2];

        surpnts[i6][0]=kx6;
        surpnts[i6][1]=ky6;

        kx7=kx2;
        ky7=-ky2;

        i7=8*n-i2;
        surpnts[i7]=new float[2];

        surpnts[i7][0]=kx7;
        surpnts[i7][1]=ky7;

        if (i!=0)
        {
           kx8=kx1;
           ky8=-ky1;
           
           i8=8*n-i;
           surpnts[i8]=new float[2];
           
           surpnts[i8][0]=kx8;
           surpnts[i8][1]=ky8;

        }
           
    }
    
    return surpnts;
}

int main(){
    int n=100;
    float Etol=0.01;
    float Eval=1;

    float **surfdata;

    surfdata=surface(Eval,Etol,n);

    char filename[25];
    sprintf(filename,"square_%.2f_%d.txt",Eval,n);

    ofstream data(filename);

    for (int i = 0; i < 8*n; i++)
    {
        data << surfdata[i][0] << "\t" << surfdata[i][1]<<"\n";
    }

    data.close();

    return 0;

    
    
}