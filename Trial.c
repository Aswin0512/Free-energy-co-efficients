#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.141592

//integral of sinx
int main(){
    /*
    float pi=PI;
    pi=abs(pi);
    float a[2][2]={{PI,2},{1,1}};
    printf("%f\t%f\n",a[0][0],a[1][0]);
    */
    /*
    float a[2][3];
    int len=sizeof(a[0])/sizeof(a[0][0]);
    printf("%d",len);
    */
   int i1=9;
   int n=8;
   i1=i1-i1*floor(i1/n);
   printf("%d\n",i1);
}