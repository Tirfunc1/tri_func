#pragma once

const double pi = 3.1415926;

double fnArctan(double x){
    double sqr = x * x;
    double e = x;
    double r = 0;
    int i = 1;
    while (fabs(e / i) > 1e-15){
        double f = e / i;
        r = (i % 4 == 1)? r + f : r - f;
        e *= sqr;
        i += 2;
    }
    return r;
}

double arctan(double x){
    if (x >= -1 && x <= 1)
        return fnArctan(x);
    else{
        if (x > 0)
            return (pi/2 - fnArctan(1 / x));
        else
            return (-pi/2 - fnArctan(1 / x));
   }
}

