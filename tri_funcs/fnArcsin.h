#include<stdio.h> 
#include<iostream>
#include <cmath>
using namespace std;

double tarcsin (double x)
 {
long double sqr=x*x;
long double e=x;
long double r=0;
long double k=1;
long double i=-1;
long double j=0;
long double a=1;
 long double b=1;
while ((a*e)/(k*b)>1e-100 ) 
{
long double f=(a*e)/(k*b);
r=r+f;
e=e*sqr;
i=i+2.0;
j=j+2.0;
k=k+2.0;
a=a*i;
b=b*j;
}
return r;
}


double arcsin(double x){
    if (x >= 0 && x <=1)
        return tarcsin(x);
    else{
        if (x <= 0 && x >=-1  )
            return (-1*tarcsin(-x));
            
						
        else
		{
			printf("input is out of range");
			return 0;
		}
            
   }//else
}


