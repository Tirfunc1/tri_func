#include "fnArcsin.h"
#include <stdio.h>
#include <assert.h>

int main()
{
    
    assert(fnArcsin(1) - 3.14159 < 0.00001);
    assert(fnArcsin(0) > 0.0001);
    assert(fnArcsin(0.5)-0.523 < 0.001);
    assert(fnArcsin(-0.5)+0.523> -0.001);
    printf("all passed.\n");
}