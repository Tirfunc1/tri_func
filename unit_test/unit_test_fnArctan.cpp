/*
 * @Description: 
 * @Author: Longjing Xia
 * @FilePath: \tri_func\unit_test\unit_test_fnArctan.cpp
 * @Date: 2022-03-27 15:07:39
 * @LastEditTime: 2022-04-01 20:52:12
 */


#include "../tri_funcs/fnArctan.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>

int main()
{
    printf("fnArctan(-2)= %lf\n", fnArctan(1, -2));
    assert(fabs(fnArctan(0, -2) -atan(-2)) < 0.0001) ;
    assert(fnArctan(0, 1) - atan(1) < 0.0001);
    assert(fnArctan(0, 0.5) - atan(0.5) < 0.0001);
    assert(fnArctan(0, 0) == 0);
    assert(fnArctan(0, -0.5) + atan(-0.5) < 0.01);
    printf("all passed.\n");
}
