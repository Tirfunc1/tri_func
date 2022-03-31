#include<stdio.h> 
#include<iostream>
#include <cmath>
using namespace std;
double Arcsin (double x)
 {
double sqr=x*x;
double e=x;
double r=0;
int k=1;
int i=-1;
int j=0;
int a=1;
int b=1;
while (fabs((a*e)/(k*b))>1e-15) {
double f=(a*e)/(k*b);
r=r+f;
e=e*sqr;
i+= 2;
j+=2;
k+=2;
a=a*i;
b=b*j;
}
return r;
}

