/*
 * @Description: 
 * @Author: Longjing Xia
 * @FilePath: \tri_func\unit_test_fnArctan.cpp
 * @Date: 2022-03-27 15:07:39
 * @LastEditTime: 2022-03-27 15:30:56
 */


#include "fnArctan.h"
#include <stdio.h>
#include <assert.h>

int main()
{
    printf("fnArctan(-2)= %lf\n", fnArctan(-0.5));
    assert(fnArctan(1) - 0.78539816339745 < 0.0001);
    assert(fnArctan(0.5) - 0.46364760 < 0.0001);
    assert(fnArctan(0) == 0);
    assert(fnArctan(-0.5) + 0.463647 < 0.01);
    printf("all passed.\n");
}
